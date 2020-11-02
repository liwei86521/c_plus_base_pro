#include <iostream>
#include <cstring>
#include <stdio.h>
/*
谈谈你对重写，重载理解
    函数重载 Overload:
    必须在同一个类中进行
    在一个类中，同名的方法如果有不同的参数列表（参数类型不同、参数个数不同甚至是参数顺序不同）则视为重载
    重载的时候，返回值类型可以相同也可以不相同

    函数重写 Override:
    必须发生于父类与子类之间(继承)
    子类 在方法名，参数列表，返回类型都相同的情况下, 对方法体进行修改或重写，这就是重写
    使用virtual声明之后能够产生多态(如果不使用virtual，那叫重定义)
 * */

using namespace std;
class Base{
public:
    Base(){
        m_A = 100;
    }

    void fun(){
        cout << "Base func调用" << endl;
    }
    void fun(int a){
        cout << "Base func (int a)调用" << endl;
    }

    int m_A;
};

class Son :public Base{
public:
    Son(){
        m_A = 200;
    }

    void fun(){
        cout << "Son func调用" << endl;
    }

    int m_A;
};

void test15_03()
{
    Son s1;
    cout << s1.m_A << endl;
    //想调用 父类中 的m_A
    cout << s1.Base::m_A << endl; // 调用父类的属性

    s1.fun();
    s1.Base::fun(10); //调用父类的func
}

//如果子类和父类拥有同名的函数 属性 ，子类会覆盖父类的成员吗？ 不会
//如果子类与父类的成员函数名称相同，子类会把父类的所有的同名版本都隐藏掉
//想调用父类的方法，必须加作用域

int main15_03() {
    test15_03();

    return 0;
}
