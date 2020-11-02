#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

//利用多态实现计算器
class abstractCalculator{
public:
    //如果父类中有了 纯虚函数  子类继承父类，就必须要实现 纯虚函数
    //如果父类中 有了 纯虚函数 ，这个父类 就无法实例化对象了
    //这个类有了纯虚函数，通常又称为 抽象类
    virtual int getResult()  = 0;
    void setv1(int v){
        this->val1 = v;
    }
    void setv2(int v){
        this->val2 = v;
    }

public:
    int val1;
    int val2;

};

//如果父类中有了 纯虚函数  子类继承父类，就必须要实现 纯虚函数
//加法计算器
class PlusCalculator :public abstractCalculator{
public:
    int getResult(){
        return val1 + val2;
    };
};

class SubCalculator : public abstractCalculator{
public:
    int getResult(){
        return val1 - val2;
    };
};

class ChengCalculator :public abstractCalculator{
public:
    int getResult(){
        return val1 * val2;
    };

};

void test16_02()
{
    abstractCalculator * abc ;
    //加法计算器
    abc =  new PlusCalculator;
    abc->setv1(10);
    abc->setv2(20);
    cout << abc->getResult() << endl;
    delete abc;

    abc = new SubCalculator;
    abc->setv1(10);
    abc->setv2(20);
    cout << abc->getResult() << endl;
    delete abc;

    abc = new ChengCalculator;
    abc->setv1(10);
    abc->setv2(20);
    cout << abc->getResult() << endl;

    //如果父类有了纯虚函数，不能实例化对象了
    /*abstractCalculator aaa;
    abstractCalculator * abc = new abstractCalculator;*/

}



int main16_02() {
    test16_02();

    return 0;
}
