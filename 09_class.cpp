/*
-------------------------------------------------
   Author :       F7687778
   date:          2020/10/19 上午 09:50
-------------------------------------------------
*/

#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

class People{
public:
    People(){
        cout << "no param contructor!" << endl;
        mAge = 10;
    }
    People(int age){
        cout << "param constructor!" << endl;
        mAge = age;
    }
    People(const People& person){
        cout << "copy constructor!" << endl;
        mAge = person.mAge;
    }
    ~People(){
        cout << "destructor!" << endl;
    }
public:
    int mAge;
};
//1. 旧对象初始化新对象
void test09_01(){

    People p(10); // People p = People(10)
    People p1(p); // People p1 = People(p)
    People p2 = People(p);
    People p3 = p; // 相当于Person p2 = People(p);
}

//2. 传递的参数是普通对象，函数参数也是普通对象，传递将会调用拷贝构造
void doBussiness(People p){}

void test09_02(){
    People p(10);
    doBussiness(p);
}

//3. 函数返回局部对象
People MyBusiness(){
    People p(10);
    cout << "局部p:" << (int*)&p << endl;
    return p;
}
void test09_03(){
    //vs release、qt下没有调用拷贝构造函数
    //vs debug下调用一次拷贝构造函数
    People p = MyBusiness();
    cout << "局部p:" << (int*)&p << endl;
}


class Person3
{
public:

    Person3(){}
    //初始化属性
    Person3(char * name,int age)
    {
        m_Name = (char*)malloc(strlen(name) + 1);
        strcpy(m_Name, name);

        m_age = age;
    }
    //拷贝构造 系统会提供默认拷贝构造，而且是简单的值拷贝
    //自己提供拷贝构造，原因简单的浅拷贝会释放堆区空间两次，导致挂掉
    //深拷贝
    Person3(const Person3&p)
    {
        m_age = p.m_age;
        m_Name = (char*)malloc(strlen(p.m_Name) + 1); //自己申请了 空间  深copy
        strcpy(m_Name, p.m_Name);
    }

    ~Person3()
    {
        cout << "析构函数调用" << endl;
        if (m_Name!=NULL)
        {
            free(m_Name);
            m_Name = NULL;
        }
    }


    //姓名
    char * m_Name;
    //年龄
    int m_age;
};

void test09_05()
{
    Person3 p1("敌法",10); // Person3 p1 = Person3(10)
    Person3 p2(p1); //调用拷贝构造

}

int main09() {
    //test09_01();
    //test09_02();
    //test09_03();

    test09_05();

    return 0;
}
