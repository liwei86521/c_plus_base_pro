
#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

//定义一个加法
#define  MyAdd(x,y) ((x)+(y))  // 宏函数  宏函数没有作用域概念

#define MyCompare(a,b)  ((a) < (b)) ? (a) :(b)
//1 内联函数 主要是来替代 宏函数的
inline void mycompare(int a, int b)
{
    int ret = a < b ? a : b;
    cout << "ret ::  " << ret << endl;
}

void test05_1()
{
    int a = 10;
    int b = 20;

//    int ret =  MyCompare(++a, b); // 预期结果 11    ((++a) < (b)) ? (++a):(b)
//    cout << "ret = " << ret << endl;

    mycompare(++a, b);

}

int main05() {
    test05_1();

    return 0;
}
