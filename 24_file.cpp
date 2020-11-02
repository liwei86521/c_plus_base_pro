#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream> //文件读写头文件
using namespace std;

//写文件
void test24_01(){
//    char* sourceFileName = "test.txt";
    //以输出的方式打开文件
    //ofstream ofs("./test.txt", ios::out | ios::trunc);

    //后期指定打开方式
    ofstream ofs;
    ofs.open("test.txt", ios::out | ios::trunc);//  test.txt 会生成在 cmake-build-debug 文件夹里
    //判断是否打开成功
    if ( !ofs.is_open()){
        cout << "打开失败" << endl;
    }

    ofs << "姓名：abc" << endl;
    ofs << "年龄：100" << endl;
    ofs << "性别：男" << endl;

    ofs.close();

}

//读文件
void test24_02(){
    ifstream ifs;
    ifs.open("test.txt", ios::in);

    //判断是否打开成功
    if (!ifs.is_open()){
        cout << "打开失败" << endl;
    }

    //第一种方式
    char buf[1024];
    while (ifs >>buf) { //按行读取
    	cout << buf << endl;
    }

    //第二种方式
//    char buf2[1024];
//    while (!ifs.eof()){ //eof读到文件尾
//    	ifs.getline(buf2, sizeof(buf2));
//    	cout << buf2 << endl;
//    }

    ifs.close();

}

int main_24() {

//    test24_01();
    test24_02();
    return 0;
}
