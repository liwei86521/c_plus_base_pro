#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

struct People
{
    int m_Age;
};

void allocatMemory(People ** p) // **p 具体的Person对象  *p 对象的指针   p 指针的指针
{
    *p = (People *)malloc(sizeof(People));
    (*p)->m_Age = 100;
}

void test04_11()
{
    People * p = NULL;
    allocatMemory(&p);
    cout <<  "p的年龄： " <<p->m_Age << endl;
}


//利用指针引用开辟空间  // 直接传递结构图 应该避免因为，结构图可能会占用很大的内存， 而指针只占用8个字节
void allocatMemoryByRef(People* &p)
{
    p = (People*)malloc(sizeof(People));
    p->m_Age = 1000;
}

void test04_12()
{
    People * p = NULL;
    allocatMemoryByRef(p);
    cout << "p的年龄：" << p->m_Age << endl;
}

void select_sort(int arr[], int len){
//void select_sort(int (&arr)[6], int len){ // 数组引用
    for(int i=0; i<len; i++){
        int minIndex = i;
        for(int j=i+1; j<len; j++){
            if (arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }

        if (minIndex != i){
            int temp = arr[minIndex];
            arr[minIndex]=arr[i];
            arr[i] = temp;
        }
    }
}

void test04_13(){
    int arr[6] = {2,4,6,1,9,0};
    select_sort(arr, 6);
    for(int i=0; i<6; i++){
        cout << arr[i] << endl;
    }
}
int main04_11() {

//    test04_11();
//    test04_12();
    test04_13();

    return 0;
}
