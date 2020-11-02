#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

class Animal2{
public:
    virtual void speak(){
        cout << "动物在说话" << endl;
    }

    //普通析构 是不会调用子类的析构的，所以可能会导致释放不干净
    //利用虚析构来解决这个问题
//    virtual ~Animal2() // OK
//    {
//        cout << "Animal的析构调用" << endl;
//    }

    //纯虚析构 写法如下
    //纯虚析构 ，需要声明 还需要实现 类内声明，类外实现
    virtual ~Animal2() = 0; // 纯虚析构 写法
    //如果函数中出现了 纯虚析构函数，那么这个类也算抽象类
};

Animal2::~Animal2() //类内声明，类外实现
{
    cout << "Animal的纯虚析构调用" << endl;
}

class Cat2:public Animal2{
public:
    Cat2(const char * name){
        this->m_Name = new char[strlen(name) + 1];
        strcpy(this->m_Name, name);
    }

    virtual void speak(){
        cout << "小猫在说话" << endl;
    }

    ~Cat2(){
        cout << "Cat的析构调用" << endl;
        if (this->m_Name !=NULL){
            delete[] this->m_Name;
            this->m_Name = NULL;
        }
    }

    char * m_Name;
};

void test16_03()
{
    Animal2 * animal = new Cat2("TOM");
    animal->speak();

    delete animal;

}

int main16_03() {
    test16_03();

    return 0;
}
