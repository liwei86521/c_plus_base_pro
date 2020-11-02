#include <iostream> //标准输入输出流  in输入  out 输出
#include <cstring>
#include <stdio.h>

using namespace std; //使用命名空间 std 打开一个叫std房间

int atk = 200; // 全局变量
void test01_1()
{
    int atk = 100;

    cout << "攻击力为 ： " << atk << endl;
    //双冒号 作用域运算符  ::全局作用域
    cout << "全局攻击力为 ： " << ::atk << endl;
}

//1、命名空间下 可以放函数、变量、结构体、类
namespace A{
    void func();
    int m_A = 20;
    struct Person
    {
    };
    class Animal{};
    namespace B
    {
        int m_A = 10;
    }
}

void test01_2()
{
    cout << "作用域B下的m_A为： " << A::B::m_A << endl;
}

namespace KingGlory{
    int sunwukongId = 10;
}

//using编译指令
namespace LOL{
    int sunwukongId = 30;
}

void test01_3()
{
    int sunwukongId = 20;
    //using编译指令
    using namespace KingGlory; //打开王者荣耀房间
    using namespace LOL;//打开LOL房间
    //如果打开多个房间，也要避免二义性问题
    cout << sunwukongId << endl;
    cout << LOL::sunwukongId << endl;
}

int main_1() {

    // cout 标准的输出
    // <<  左移运算符
    // endl 结束换行
    //cout << "hello world " << 123456 << endl;

    //test01_1();
    test01_2();
    test01_3();

    return 0;
}

