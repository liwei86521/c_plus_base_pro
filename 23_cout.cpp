#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <iomanip> //使用控制符的头文件

using namespace std;

/*
cout.put() //向缓冲区写字符
cout.write() //从buffer中写num个字节到当前输出流中。
*/

void test23_1()
{
//	cout.put('a').put('b');
    char buf[1024] = "hellowrold";
    cout.write(buf, strlen(buf));
    cout << endl;

}

void test23_2(){
    //通过流成员函数
    int number = 20;
    cout.width(20);
    cout.fill('*');
    cout.setf(ios::left); //设置格式  输入内容做对齐
    cout.unsetf(ios::dec); //卸载十进制
    cout.setf(ios::hex); //安装16进制
    cout.setf(ios::showbase); // 强制输出整数基数  0  0x
    cout.unsetf(ios::hex);
    cout.setf(ios::oct);
    cout << number << endl;

}

//控制符的方式显示
void test23_3(){
    int number = 20;
    cout << setw(20)  // #include <iomanip> //使用控制符的头文件
         << setfill('~')
         << setiosflags(ios::showbase) //基数
         << setiosflags(ios::left) //左对齐
         << hex // 十六进制
         << number
         << endl;
}

int main23_1() {
    test23_1();
    test23_2();
    test23_3();

    return 0;
}
