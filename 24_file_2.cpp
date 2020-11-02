#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <fstream> //文件读写头文件
using namespace std;

class Person8{
public:
    Person8(){}
    Person8(char* name,int age){
        strcpy(this->mName, name);
        this->mAge = age;
    }
public:
    char mName[64];
    int mAge;
};

void test_242(){
    char* fileName = "person.txt";
    //二进制模式读写文件
    //创建文件对象输出流
    ofstream osm(fileName, ios::out | ios::binary);

    Person8 p1("John",33);
    Person8 p2("Edward", 34);

    //Person对象写入文件
    osm.write((const char*)&p1,sizeof(Person8));
    osm.write((const char*)&p2, sizeof(Person8));

    //关闭文件输出流
    osm.close();

    //从文件中读取对象数组
    ifstream ism(fileName, ios::in | ios::binary);
    if (!ism){
        cout << "打开失败!" << endl;
    }

    Person8 p3;
    Person8 p4;

    ism.read((char*)&p3, sizeof(Person8));
    ism.read((char*)&p4, sizeof(Person8));

    cout << "Name:" << p3.mName << " Age:" << p3.mAge << endl;
    cout << "Age:" << p4.mName << " Age:" << p4.mAge << endl;

    //关闭文件输入流
    ism.close();

}

int main242() {
    test_242();

    return 0;
}
