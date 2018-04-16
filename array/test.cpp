#include <iostream>
#include <new>
#include <algorithm>
#include <cstdio>
#include <exception>
#include "array.hpp"

#define PERFORM_TEST(FuncName)                  \
    do {                                        \
        if(!Test##FuncName())                   \
            return false;                       \
    } while(0)

bool unit_test(void) {
}


int main(void) {
/*
    Array<int> a1(10);
    for(int i = 0; i < 10; i++)
        printf("%d\n", a1[i]);
    for(int i = 0; i < 10; i++)
        a1[i] = i;
    a1.Dump();
    Array<int> a2(a1);
    a2.Dump();
    Array<int> a3(5);
    a3 = Array<int>(10);
    Array<int> a = GetArray<int>();
    a.Dump();
    a3.Dump();
    Array<int> a4;
    a4 = a1;
    a4.Dump();
    a4 = Array<int>(2);
    a4.Dump();
    try {
        int a = a1[-1];
    }
    catch(enum ARRAY_EXC ErrCode) {
        if(ErrCode == WRONG_POS)
            printf("\nWRONG_POD Exception catched\n");
    }
*/
    Array<bool> a(5);
    a.Dump();
    a[2] = true ;
    a.Dump();
    a[2] = true ;
    a.Dump();
    a[2] = false ;
    a.Dump();

    return 0;
}





#undef PERFORM_TEST
