#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

template<class NameType, class AgeType =int> //类模板可以有默认类型
class Person{
public:
    Person(NameType name, AgeType age){
        this->mName = name;
        this->mAge = age;
    }
    void PrintPerson(){
        cout << "Name:" << this->mName << " Age:" << this->mAge << endl;
    }
public:
    NameType mName;
    AgeType mAge;
};

void test18_01(){
    //自动类型推导 ，类模板 不支持
    //People p("孙悟空", 100);

    //显示指定类型
    Person<string, int> p("孙悟空", 100);
    p.PrintPerson(); // Name:孙悟空 Age:100
}

//类模板做函数参数 --> 1 指定传入类型
void doWork(Person<string,int>& p){
    p.mAge += 20;
    p.mName += "_vip";
    p.PrintPerson();
}

void test18_02(){
    Person <string, int> p("MT", 10);
    doWork(p); // Name:MT_vip Age:30
}

//2 参数模板化
template<class T1 ,class T2>
void doWork2(Person<T1, T2> & p){
    //如何查看类型
    cout << typeid(T1).name() << endl;
    cout << typeid(T2).name() << endl;
    p.PrintPerson();
}
void test18_03(){
    Person <string, int> p("呆贼", 18);
    doWork2(p); // Name:呆贼 Age:18
}

int main18_01() {
    test18_01();
    test18_02();
    test18_03();

    return 0;
}
