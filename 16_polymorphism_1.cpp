#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;
/*
多态成立的三个条件:
 1 要有继承
 2 有virtual重写
 3 要有父类指针（父类引用）指向子类对象  Animal * animal = new Cat;
 * */

class Animal{
public:
    virtual void speak(){ // 这里 加上 virtual 就能 运行时候再去确定函数地址 实现多态
        cout << "动物在说话" << endl;
    }

    virtual void eat(){
        cout << "动物在吃饭" << endl;
    }

};

class Cat :public Animal{
public:
    void speak(){
        cout << "小猫在说话" << endl;
    }

    void eat(){
        cout << "小猫在吃鱼" << endl;
    }
};

//调用doSpeak ，speak函数的地址早就绑定好了，早绑定，静态联编，编译阶段就确定好了地址
//如果想调用猫的speak，不能提前绑定好函数的地址了，所以需要在运行时候再去确定函数地址
//动态联编，写法 doSpeak方法改为虚函数,在父类上声明虚函数，发生了多态
// 父类的引用或者指针 指向 子类对象
void doSpeak(Animal & animal) //Animal & animal = cat
{
    //父类指针指向子类对象 多态
    //Animal * animal = new Cat;
    animal.speak();
    animal.eat();
}

void test16_01(){
    Cat cat;
    doSpeak(cat);

}

int main16_01() {

    test16_01();
    return 0;
}
