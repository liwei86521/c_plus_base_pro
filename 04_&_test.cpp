#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

//1、引用基本语法  Type &别名 = 原名
void test04_1()
{
    int a = 10;
    int &b = a; //给变量a取一个别名b

    b = 20;

    cout << "a = " << a << endl; // 20
    cout << "b = " << b << endl; // 20
}
//2、引用必须初始化
void test04_2()
{
    //int &a; 必须初始化
    int a = 10;
    int &b = a; //引用初始化后不可以修改了
    int c = 20;

    b = c; //赋值！！！  ---> 不能改变引用
    cout << "b = " << b << endl; // 20
}

//3、对数组建立引用
void test04_3()
{
    int arr[10];
    //int& ref3[10] = arr;  // 不能对数组建立引用
    for (int i = 0; i < 10;i++)
    {
        arr[i] = i;
    }

    //给数组起别名
    int(&pArr)[10] = arr; // 建立数组引用， 里面的10 不能省略
    for (int i = 0; i < 10;i++)
    {
        cout << pArr[i] << " ";
    }

    cout << endl;

    //第二种方式 起别名
    typedef int(ARRAYREF)[10]; //一个具有10个元素的int类型的数组
    ARRAYREF & pArr2 = arr;

    for (int i = 0; i < 10; i++){
        cout << pArr2[i] << " ";
    }
    cout << endl;

}

//地址传递
void mySwap2(int * a, int * b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void test04_4()
{
    int a = 10;
    int b = 20;
    mySwap2(&a, &b);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

//引用传递 类似传地址
void mySwap3(int &a, int &b)  //&a = a &b = b
{
    int tmp = a;
    a = b;
    b = tmp;
}

void test04_5()
{
    int a = 10;
    int b = 20;
    mySwap3(a, b);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

//引用的注意事项
//1、 引用必须引一块合法的内存空间
//2、不要返回局部变量的引用
int& doWork()
{
    int a = 10;
    return a;
}

void test04_6()
{
    int &ret = doWork();
    cout << "ret = " << ret << endl; // 报错
}


int main04_1() {
//    test04_1();
    test04_2();
//    test04_3();
//    test04_4();
//    test04_5();
//    test04_6();

    return 0;
}
