#pragma  once

// 按照这样的格式声明， 这样就可以直接在C++ 中调用show()函数了， 而不用 extern "C" void show();
#ifdef __cplusplus //两个_下划线
extern "C" {
#endif

#include <stdio.h>

void show();





#ifdef __cplusplus //两个_下划线
}
#endif
