#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

class Base{
public:
    static void func(){
        cout << "base fun()" << endl;
    }
    static void func(int a){
        cout << "base fun(int)" << endl;
    }

    static int m_A;
};
int Base::m_A = 10; // 静态成员 类内定义， 类外初始化

class Son :public Base{
public:
    static void func(){
        cout << "son fun()" << endl;
    }
    static int m_A;
};
int Son::m_A = 20;

//静态成员属性 子类可以继承下来
void test15_04()
{
    cout << Son::m_A << endl;
    //访问父类的m_A
    cout << Base::m_A << endl;

    Son::func();
    //访问 父类中同名的函数
    Son::Base::func(10);

}

int main15_04() {
    test15_04();

    return 0;
}
