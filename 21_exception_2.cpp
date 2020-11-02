#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

//异常基类
class BaseException{
public:
    virtual void printError(){} //定义接口
};

class  NullPointerException:public BaseException{
public:
    virtual void printError(){
        cout << "空指针异常" << endl;
    }
};

class OutofRangeException:public BaseException{
public:
    virtual void printError(){
        cout << "越界异常" << endl;
    }
};


void doWork2(){
    //throw NullPointerException();
    throw OutofRangeException();
}


void test21_02(){
    try{
        doWork2();
    }
    catch (BaseException & e){
        e.printError();
    }
}

int main21_02() {

    test21_02();
    return 0;
}
