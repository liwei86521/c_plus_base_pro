#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

//交换int数据
void SwapInt(int& a,int& b){
    int temp = a;
    a = b;
    b = temp;
}

//类型，逻辑又非常相似
//类型参数化  泛型编程 -- 模板技术
// template<typename T>  等价于 template<class T>

template<class T> // 告诉编译器 下面如果出现T不要报错，T是一个通用的类型
void MySwap(T& a,T& b){
    T temp = a;
    a = b;
    b = temp;
}

//对char和int数组进行排序  排序规则 从大到小  利用选择排序
template<class T>
void mySort(T arr[], int len){// 选择排序
    for(int i = 0; i < len;i++){
        int min_ind = i;
        for (int j = i + 1; j < len;j++){
            if (arr[min_ind] > arr[j]){
                min_ind = j; //交换 下标
            }
        }

        if (min_ind != i){
            MySwap(arr[min_ind], arr[i]);//交换数据
        }
    }
}

//输出数组元素的模板
template<class T>
void printArray( T arr[], int len)
{
    for (int i = 0; i < len;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


void test17_01(){
    int a = 10;
    int b = 20;
    cout << "a:" << a << " b:" << b << endl;
    //1. 这里有个需要注意点，函数模板可以自动推导参数的类型
    MySwap(a,b);
    cout << "a:" << a << " b:" << b << endl;

    char c1 = 'a';
    char c2 = 'b';
    cout << "c1:" << c1 << " c2:" << c2 << endl;
    //2. 函数模板可以自动类型推导，那么也可以显式指定类型
    MySwap<char>(c1, c2);
    cout << "c1:" << c1 << " c2:" << c2 << endl;
}

void test17_02(){
    char charArr[] = "helloworld";
    int num = sizeof(charArr) / sizeof(char);
    mySort(charArr, num);
    printArray(charArr, num);


    int intArr[] = { 1, 4, 100, 34, 55 };
    int num2 = sizeof(intArr) / sizeof (int);
    mySort(intArr, num2);
    printArray(intArr, num2);
}

int main17_01() {

//    test17_01();
    test17_02();
    return 0;
}
