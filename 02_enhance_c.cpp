#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;


//3、类型转换检测增强
void test02_1()
{
    char * p = (char*)malloc(sizeof(64)); //malloc返回值是void*
}


//4、struct 增强
struct People
{
    int m_Age;
    void plusAge(){ m_Age++; }; //c++中struct可以加函数
};
void test02_2()
{
    People p1; //使用时候可以不加struct关键字
    p1.m_Age = 10;
    p1.plusAge();
    cout << p1.m_Age << endl;
}

//5、 bool类型增强 C语言中没有bool类型
bool flag = true; //只有真或假 true代表 真（非0）  false 代表假（0）
void test02_3()
{
    cout << "sizeof(bool)   " << sizeof(bool) << endl;

    flag = 100;
    //bool类型 非0的值 转为 1  ，0就转为0
    cout << flag << endl;
}

//6、三目运算符增强
void test02_4()
{
    int a = 10;
    int b = 20;

    cout << "ret = " << (a < b ? a : b) << endl;
    (a < b ? a : b) = 100; //b = 100 C++中返回的是变量
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}


const int m_A = 10; //收到保护，不可以改
void test02_5()
{
    const int m_B = 20; //真正常量
    //m_B = 100;

    int * p = (int *)&m_B;
    *p = 200;
    cout << "*p = " << *p << endl;
    cout << "m_B = " << m_B << endl; // 20

}

void test02_6()
{
    extern const int test_var; //告诉编译器在test_var在外部  test.c
    printf("test_var = %d \n ", test_var);
}

void test02_7()
{
    extern const int test_var2; //告诉编译器在test_var2在外部  test.cpp
    printf("test_var2 = %d \n ", test_var2);
}

int main02() {
//    test02_1();
//    test02_2();
//    test02_3();
//    test02_4();
//    test02_5();
    test02_6();
    test02_7();

    return 0;
}
