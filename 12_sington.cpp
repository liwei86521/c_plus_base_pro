/*
-------------------------------------------------
   Author :       F7687778
   date:          2020/10/19 上午 11:18
-------------------------------------------------
*/

#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;
//创建主席类
//需求 单例模式  为了创建类中的对象，并且保证只有一个对象实例

class ChairMan
{
    //1构造函数 进行私有化
private:
    ChairMan(){
        //cout << "创建国家主席" << endl;
    }
    //拷贝构造 私有化
    ChairMan(const ChairMan&c){}

public:
    //提供 get方法 访问 主席
    static ChairMan* getInstance(){
        return singleMan;
    }

private:
    static ChairMan * singleMan;

};
// 类内声明， 内外初始化
ChairMan * ChairMan::singleMan = new ChairMan;

void test12_1(){
    //    ChairMan c1;
//    ChairMan * c2 = new ChairMan;
//    ChairMan * cm = ChairMan::singleMan;

    ChairMan * cm1 = ChairMan::getInstance();
    ChairMan * cm2 = ChairMan::getInstance();
    if (cm1 == cm2){
        cout << "cm1 与 cm2相同" << endl;
    }

}

class Printer
{
private:
    Printer(){ m_Count = 0; };
    Printer(const Printer& p);

public:
    static Printer* getInstance()
    {
        return singlePrinter;
    }

    void printText(string text)
    {
        cout << text << endl;
        m_Count++;
        cout << "打印机使用了次数为： " << m_Count << endl;
    }

private:
    static Printer* singlePrinter;
    int m_Count;
};
Printer* Printer::singlePrinter = new Printer;

void test12_2()
{
    //拿到打印机
    Printer * printer =  Printer::getInstance();

    printer->printText("离职报告");
    printer->printText("入职报告");
    printer->printText("加薪申请");
    printer->printText("升级申请");
    printer->printText("退休申请");
}

int main12() {
    //test12_1();
    test12_2();
    return 0;
}
