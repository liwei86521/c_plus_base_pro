#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

class Person10
{
public:
    Person10(){};
    Person10(int a, int b) :m_A(a), m_B(b)
    {}

    int m_A;
    int m_B;
};

//利用全局函数 进行+号运算符的重载
Person10 operator+ ( Person10 &p1,Person10& p2) //二元  p1 + p2
{
    Person10 tmp;
    tmp.m_A = p1.m_A + p2.m_A;
    tmp.m_B = p1.m_B + p2.m_B;
    return tmp;
}

Person10 operator+ (Person10 &p1, int a) //二元
{
    Person10 tmp;
    tmp.m_A = p1.m_A + a;
    tmp.m_B = p1.m_B + a;
    return tmp;
}


void test14_0()
{
    Person10 p1(10, 10);
    Person10 p2(10, 10);

    Person10 p3 = p1 + p2; // p1 + p2  从什么表达式转变的？ p1.operator+(p2)  operator+(p1,p2)
    Person10 p4 = p1 + 15; //重载的版本
    cout << "p3 的 m_A: " << p3.m_A << "  m_B: " << p3.m_B << endl;
    cout << "p3 的 m_A: " << p4.m_A << "  m_B: " << p4.m_B << endl;


}


int main14_0() {

    test14_0();
    return 0;
}
