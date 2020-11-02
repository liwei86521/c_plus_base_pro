#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

class Person{
public:
    //1. 当形参名和成员变量名一样时，this指针可用来区分
    Person(string name,int age){
        //name = name;
        //age = age; //输出错误
        this->name = name;
        this->age = age;
    }
    //2. 返回对象本身的引用
    //重载赋值操作符
    //其实也是两个参数，其中隐藏了一个this指针
    Person PersonPlusPerson(Person& person){
        string newname = this->name + person.name;
        int newage = this->age + person.age;
        Person newperson(newname, newage);
        return newperson;
    }
    void ShowPerson(){
        cout << "Name:" << name << " Age:" << age << endl;
    }
public:
    string name;
    int age;
};


void test13_1(){
    Person person("John",100);
    person.ShowPerson();

    cout << "---------" << endl;
    Person person1("John",20);
    Person person2("001", 10);

    //2. 成员函数实现两个对象相加
    Person person4 = person1.PersonPlusPerson(person2);
    person4.ShowPerson();
}


int main13() {

    test13_1();
    return 0;
}
