#include <iostream>
#include <cstring> // c 语言中的 string
#include <string>
#include <stdio.h>

using namespace std;
// c语言struct只有变量, c++语言struct 既有变量，也有函数
//struct 和class是一个意思，唯一的不同  默认权限 ，struct是public，但是class默认权限是private
struct People{
    char mName[64];
    int mAge;
    void PersonEat(){
        cout <<  mName <<"吃人饭" << endl;
    }

};

struct Dog{
    char mName[64];
    int mAge;
    void DogEat(){
        cout << mName << "吃狗粮" << endl;
    }

};

//C++中的封装 严格类型转换检测， 让属性和行为 绑定到一起
// 1 属性和行为作为一个整体来表示生活中的事物
// 2 控制权限 public 公有权限   protected 保护权限  private 私有权限
void test08_1()
{
    People p1;
    strcpy(p1.mName, "老王");
    p1.PersonEat();
    //p1.DogEat(); // 报错
}

//struct 和class是一个意思，唯一的不同  默认权限 ，struct是public，但是class默认权限是private
class Animal
{
private:
    //如果我不声明权限，默认的权限是 private
    void eat(){ mAge = 100; };
    int mAge;

public:
    int mHeight;

protected: //保护权限 类内部可以访问 ，(当前类的子类可以访问) , 类外部不可以访问
    int mWeight;
    void setWeight(){ mWeight = 100; };
};

//所谓私有权限 就是私有成员(属性、函数) 在类内部可以访问，类外部不可以方法
//公共权限 ，在类内部和类外部都可以访问
void test08_02()
{
    Animal an;
    //an.eat(); //私有方法 不可以访问到
    //an.mAge; //私有属性 不可以访问到

    an.mHeight = 100; //公有权限在类外部可以访问到
    //an.mWeight = 100; //保护权限 在类外不可访问到
}

// public  类内 类外 都可以访问
// protected 类内可以访问 类外 不可以访问 （子类可以访问）
// private   类内可以访问 类外 不可以访问  （子类不可以访问）

class Person2
{

public:
    void setAge(int age) //设置年龄
    {
        if (age < 0 || age > 100){
            cout << "你这个老妖精" << endl;
            return;
        }
        m_Age = age;
    }
    //获取年龄 读权限
    int getAge(){
        return m_Age;
    }

    //读姓名
    string getName(){
        return m_Name;
    }
    //写姓名
    void setName(string name){
        m_Name = name;
    }

    //只写的情人
    void setLover(string lover){
        m_lover = lover;
    }

private: //类外不可访问，类内可以访问
    int m_Age  = 0; //年龄 读写
    string m_Name; //公有权限  读写
    string m_lover; //情人  只写

};

void test08_03()
{
    Person2 p1;
    p1.setName("老王");
    cout << "p1的姓名：" << p1.getName() << endl;

    //年龄
    p1.setAge(120);
    cout << "p1的年龄：" << p1.getAge() << endl;

    //情人 只能设置 外部我不告诉你
    p1.setLover("仓井");

}


int main08() {

    //test08_02();
    test08_03();
    return 0;
}
