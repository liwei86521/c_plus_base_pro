#include <iostream>
#include <string>
#include <stdio.h>

#include <stdexcept> //系统提供标准异常 要包含头文件
using namespace std;

int myDevide(int a ,int b)
{
    if (b == 0){
        //throw 1; 抛出int类型异常
        //throw 3.14; //抛出double类型异常  异常必须处理，如果不处理 就挂掉
        throw runtime_error("除数不能为0！");
    }
    return a / b;
}

class Person6{
public:
    Person6(string name, int age){
        this->m_Name = name;
        //年龄做检测
        if (age < 0 || age > 200){
            //抛出越界异常
            throw  out_of_range("年龄越界了！");
            //throw length_error("长度越界");
        }
    }

    string m_Name;
    int m_Age;
};

void test21_01()
{
    try{
        Person6 p("张三",300);
    }
    catch (out_of_range & e){
        cout << e.what() << endl;
    }
    catch (length_error & e){
        cout << e.what() << endl;
    }


    try{
        int a = 10;
        int b = 0;
        myDevide(a ,b);
    }catch (out_of_range & e){
        cout << e.what() << endl;
    }catch (...){
        cout << "其他类型异常捕获" << endl;
    }
}

int main21_01() {

    test21_01();
    return 0;
}
