#include <iostream>
#include <cstring>
#include <stdio.h>
//#define MAX 1024;  //尽量以const替换#define    const常量是由编译器处理的，提供类型检查和作用域检查
const int max= 1024;
using namespace std;

//1、const分配内存 取地址会分配临时内存
//2、extern 编译器也会给const变量分配内存

void test03_1()
{
    const int m_A = 10; // 改变不了
    int * p = (int*)&m_A; //会分配临时内存
    *p = 1000;
    cout << "*p = " << *p << endl; // *p = 1000
    cout << "m_A = " << m_A << endl; // m_A = 10

}

//3、 用普通变量初始化 const 的变量
void test03_2()
{
    int a = 10;
    const int b = a; //b 分配了内存，所以我们可以修改b内存中的值

    int * p = (int *) &b;
    *p = 1000;

    cout << "b = " << b << endl; // b = 1000
    cout << "*p = " << *p << endl; // *p = 1000
}

//4、 自定义数据类型  比如类对象, 加const也会分配内存
struct People
{
    string m_Name; //姓名
    int m_Age;
};

void test03_3()
{
    const People p1 = {"lee", 22};
    //p1.m_Name = "aaa";

    People * p = (People*)&p1; // 可以通过指针改变值
    p->m_Name = "德玛西亚";
    (*p).m_Age = 18;

    cout << "姓名： " << p1.m_Name << " 年龄： " << p1.m_Age << endl;
}


int main03_1() {

    test03_1();
//    test03_2();
    test03_3();
    return 0;
}
