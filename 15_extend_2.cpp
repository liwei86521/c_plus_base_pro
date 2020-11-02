/*
-------------------------------------------------
   Author :       F7687778
   date:          2020/10/20 上午 11:35
-------------------------------------------------
*/

#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

class Base2
{
public:
    Base2(int a)
    {
        this->m_A = a;
        cout << "base2 有参构造函数调用" << endl;
    }
    int m_A;
};

class Son2:public Base2
{
public:
    Son2(int a ) : Base2(a)//利用初始化列表方式 显示调用 有参构造
    {
        cout << "Son2 有参构造函数调用" << endl;
        cout << a << endl;
    }
};

void test15_02()
{
    Son2 s2(1000);
}

int main15_02() {

    test15_02();
    return 0;
}
