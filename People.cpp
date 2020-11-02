#include "People.h"

template<class T1, class T2>
People<T1, T2>::People(T1 name, T2  age){
    this->m_Name = name;
    this->m_Age = age;
}

template <class T1, class T2>
void People<T1, T2>::showPerson(){
    cout << "name:" << this->m_Name << "age:" << this->m_Age << endl;
}
