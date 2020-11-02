#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

//1. 形参b设置默认参数值，那么后面位置的形参c也需要设置默认参数
void TestFunc02(int a,int b = 10,int c = 10){
    cout << "a + b  = " << a + b << endl;
}

//2. 如果函数声明和函数定义分开，函数声明设置了默认参数，函数定义不能再设置默认参数
void TestFunc03(int a = 10,int b = 20);

//实现函数重载的条件
// 1.同一个作用域,函数名称相同   2.函数的参数 个数不同 或者 类型不同  或者 顺序不同
void func(){
    cout << "无参数的func" << endl;
}

void func(int a ){
    cout << "有参数的func(int a)" << endl;
}

void func(double  a){
    cout << "有参数的func(double a)" << endl;
}

void func(double  a , int b){
    cout << "有参数的func(double a ,int b)" << endl;
}

void func(int a, double b){
    cout << "有参数的func(int a ,double b)" << endl;
}

void test06_01()
{
    func(3);
    func(1.1,3);
    func(1, 3.14);
}

int main06() {

    //TestFunc03();
    test06_01();
    return 0;
}


void TestFunc03(int a,int b){
    cout << "a + b  = " << a + b << endl;
}