#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

//1 普通函数与函数模板区别
template<class T>
T myPlus(T a, T b){
    return a + b;
}

int myPlus2(int a, int b){
    return a + b;
}

void test17_03(){
    int a = 10;
    int b = 20;
    char c = 'c'; // a = 97
//	myPlus(a, c); //类型推导不出来 ,函数模板不可以进行隐式类型转换
    cout << myPlus2(a, c) <<endl; // 10 + 99  普通函数 可以进行隐式类型转换
}


int main17_02() {


    return 0;
}
