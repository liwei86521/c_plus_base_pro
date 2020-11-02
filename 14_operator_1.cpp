#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

class People
{	// 友元函数可以访问 私有属性
    friend ostream& operator<<(ostream &cout, People & p1);

public:
    People(){}
    People(int a, int b){
        this->m_A = a;
        this->m_B = b;
    }

private:
    int m_A;
    int m_B;
};

//重载左移操作符(<<),使得cout可以输出对象
ostream& operator<<(ostream &cout , People & p1 )  //第一个参数 cout  第二个参数  p1
{
    cout << "m_A = " << p1.m_A << " m_B = " << p1.m_B;
    return cout;
}

void test14_01(){
    People p1(10, 10); //cout << person; //cout.operator+(person)
    cout << p1 <<endl; //重载左移操作符(<<),使得cout可以输出对象

}

int main14_01() {
    test14_01();

    return 0;
}
