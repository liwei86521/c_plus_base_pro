#include <iostream>
#include <string>
//#include <cstring>
#include <stdio.h>

using namespace std;

class Person{
public:
    Person(string name, int age){
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};


template<class T>
bool myCompare( T &a , T &b ){
    if ( a == b){
        return true;
    }
    return false;
}

// 通过第三代具体化自定义数据类型，解决上述问题
// 如果具体化能够优先匹配，那么就选择具体化
// 语法  template<> 返回值  函数名<具体类型>(参数)
template<> bool myCompare<Person>(Person &a, Person &b)
{
    if ( a.m_Age  == b.m_Age)
    {
        return true;
    }

    return false;
}

void test17_3()
{
    int a = 10;
    int b = 10;

    int ret = myCompare(a, b);
    cout << "ret = " << ret << endl;

    Person p1("Tom", 10);
    Person p2("Jerry", 10);

    int ret2 = myCompare(p1, p2);
    cout << "ret2 = " << ret2 << endl;

}

int main17_3() {

    test17_3();
    return 0;
}
