#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

//父类类模板
template<class T>
class Base{
public:
    T m;
};

template<class T >
class Child2 : public Base<double>{  //继承类模板的时候，必须要确定基类的 数据类型
public:
    T mParam;
};

void test18_6()
{
    Child2<int> d2;
}

