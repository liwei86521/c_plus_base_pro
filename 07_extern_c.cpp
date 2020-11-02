/*
-------------------------------------------------
   Author :       F7687778
   date:          2020/10/19 上午 08:45
-------------------------------------------------
*/

#include <iostream>
#include <cstring>
#include <stdio.h>
#include "test.h"

using namespace std;

//C++中想调用C语言方法

//extern "C" void show(); //show方法 按照C语言方式做连接  方法一

//解决的问题就是 在C++中调用C语言的函数
int main07() {
    show(); //在C++中 函数是可以发生重载的，编译器会把这个函数名称偷偷改变  _showv  void

    return 0;
}
