#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;
class People{
public:
    People(){
        cout << "无参构造函数!" << endl;
        pName = (char*)malloc(strlen("undefined") + 1);
        strcpy(pName, "undefined");
        mAge = 0;
    }
    People(char* name, int age){
        cout << "有参构造函数!" << endl;
        pName = (char*)malloc(strlen(name) + 1);
        strcpy(pName, name);
        mAge = age;
    }
    void ShowPerson(){
        cout << "Name:" << pName << " Age:" << mAge << endl;
    }
    ~People(){
        cout << "析构函数!" << endl;
        if (pName != NULL){
            delete pName;
            pName = NULL;
        }
    }

public:
    char* pName;
    int mAge;
};

void test10_01(){
    // People p(10); // People p = People(10) // 静态分配内存
    People* person1 = new People; // 动态分配内存
    People* person2 = new People("John", 33); //堆区开辟

    //所有new出来的对象 都会返回该类型的指针
    //malloc 返回 void* 还要强转
    //malloc会调用构造吗？ 不会  new会调用构造
    // new 运算符  malloc 函数
    //释放 堆区空间
    // delete也是运算符 配合 new用  malloc 配合 free用
    /*
     People* person = new People;
    相当于:
    People* person = (People*)malloc(sizeof(People));
        if(person == NULL){
            return 0;
        }

     * */

    person1->ShowPerson();
    person2->ShowPerson();

    delete person1;
    delete person2;
}

void test10_02(){
    //栈聚合初始化
    People person[] = {People("john", 20), People("Smith", 22) };
    cout << person[1].pName << endl;

    //创建堆上对象数组必须提供构造函数
    People* workers = new People[20];
//    delete [] workers;
}



int main10() {
    //test10_01();
    test10_02();

    return 0;
}
