#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

//如果重新定义了基类中的重载函数，将会发生什么
class Base{
public:
    void func1(){
        cout << "Base::void func1()" << endl;
    };
    void func1(int param){
        cout << "Base::void func1(int param)" << endl;
    }
    void myfunc(){
        cout << "Base::void myfunc()" << endl;
    }
};
class Derived1 : public Base{ // Derive1 重定义了Base类的myfunc函数，derive1可访问func1及其重载版本的函数。
public:
    void myfunc(){
        cout << "Derived1::void myfunc()" << endl;
    }
};

//Derive2 通过改变函数参数列表的方式重新定义了基类的func1函数，则从基类中继承来的其他重载版本被隐藏，不可访问
class Derived2 : public Base{
public:
    //改变成员函数的参数列表
    void func1(int param1, int param2){
        cout << "Derived2::void func1(int param1,int param2)" << endl;
    };
};

// Derive3通过改变函数返回类型的方式重新定义了基类的func1函数，则从基类继承来的没有重新定义的重载版本的函数将被隐藏。
class Derived3 : public Base{
public:
    //改变成员函数的返回值
    int func1(int param){
        cout << "Derived3::int func1(int param)" << endl;
        return 0;
    }
};

void test_15_05(){
    Derived1 derived1;
    derived1.func1();
    derived1.func1(20);
    derived1.myfunc();
    cout << "-------------" << endl;

    Derived2 derived2;
//    derived2.func1();  //func1被隐藏
    //derived2.func1(20); //func2被隐藏
    derived2.func1(10,20); //重载func1之后，基类的函数被隐藏
    derived2.myfunc();
    cout << "-------------" << endl;

    Derived3 derived3;
    //derived3.func1();  没有重新定义的重载版本被隐藏
    derived3.func1(20);
    derived3.myfunc();

}


int main15_05() {
    test_15_05();

    return 0;
}
