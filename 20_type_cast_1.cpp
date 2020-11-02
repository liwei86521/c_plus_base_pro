#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

//静态转换
//基础类型
void test20_01(){
    char a = 'a';
    double d = static_cast<double>(a);
    cout << "d = " << d <<endl;
}

//父子之间转换
class Base{};
class Child :public Base{};
void test20_02()
{
    Base * base = NULL;
    Child * child = NULL;

    //把base转为 Child*类型 向下  不安全
    Child * child2 = static_cast<Child*>(base);

    //把child 转为 Base*  向上  安全
    Base * base2 = static_cast<Base*>(child);
}

class Base2{
    virtual void func(){};
};

class Child2 :public Base2{
    virtual void func(){};
};

class Other2{};

void test04(){
    Base2 * base = NULL;
    Child2 * child = NULL;

    Base2 * base2 = dynamic_cast<Base2*>(child); //child转Base2 *  安全

    //base 转Child2 * 不安全
    //Child2 * child2 = dynamic_cast<Child2*>(base);

    //dynamic_cast 如果发生了多态，那么可以让基类转为派生类 ，向下转换
    Base2 * base3 = new Child2;
    Child2 * child3 = dynamic_cast<Child2*>(base3);

}

// 常量转换(const_cast)
void test05(){
    const int * p = NULL;
    //取出const
    int * newp = const_cast<int *>(p);

    int * p2 = NULL;
    const int * newP2 = const_cast<const int *>(p2);

    //不能对非指针 或 非引用的 变量进行转换
    //const int a = 10;
    //int b = const_cast<int>(a);

    //引用
    int num = 10;
    int &numRef = num;
    const int &numRef2 = static_cast<const int &>(numRef);
}

int main_20_1() {
    test20_01();

    return 0;
}
