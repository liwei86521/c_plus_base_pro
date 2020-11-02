/*
-------------------------------------------------
   Author :       F7687778
   date:          2020/10/19 上午 11:10
-------------------------------------------------
*/

#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

class People
{
public:
    People(){
    }

    static int m_Age; //加入static就是 静态成员变量 ，会共享数据
    //静态成员变量，在类内声明，类外进行初始化

    //静态成员变量 也是有权限的
    int m_A;

    //静态成员函数
    //不可以访问  普通成员变量
    //可以访问 静态成员变量
    static void func(){
        //m_A = 10;
        m_Age = 100;
        cout << "func调用" << endl;
    };

    //普通成员函数 可以访问普通成员变量，也可以访问静态成员变量
    void myFunc(){
        m_A = 100;
        m_Age = 100;
    }

private:
    static int m_other; //私有权限 在类外不能访问
    static void func2(){
        cout << "func2调用" << endl;
    }
};

int  People::m_Age = 0; //类外初始化实现
int  People::m_other = 10;

void test11_01()
{
    //1 通过对象访问属性
    People p1;
    p1.m_Age = 10;

    People p2;
    p2.m_Age = 20;

    cout << "p1 = " << p1.m_Age << endl; //10 或者 20？ 20
    cout << "p2 = " << p2.m_Age << endl; //20
    //共享数据

    //2 通过类名访问属性
    cout << "通过类名访问Age" << People::m_Age << endl;
    //cout << "other = " << People::m_other << endl; //私有权限在类外无法访问

    //静态成员函数调用
    p1.func();
    p2.func();
    People::func();

    //静态成员函数 也是有权限的
    //People::func2();

}

int main11() {

    test11_01();
    return 0;
}
