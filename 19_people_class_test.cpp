//#include "People.h" # 这个有点问题
#include "People.cpp"

void test_p(){
    People<string, int>p("lee ", 10);
    p.showPerson();

}

int main_pp() {
    test_p();
    return 0;
}
