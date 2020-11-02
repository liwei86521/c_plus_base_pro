#include "test.h"

const int test_var = 10; //C语言中默认const是外部链接, 如果是test.cpp 就不可以

void show(){
    printf(" c++ 引用 c 语言函数 --> hello world \n");
}