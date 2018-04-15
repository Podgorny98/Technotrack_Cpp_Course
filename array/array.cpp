#include <iostream>
#include <new>
#include <algorithm>
#include <cstdio>
#include <exception>
#include "array.hpp"

template <typename DataT>
Array<DataT>::Array(size_t size) :
    data_(new DataT[size]),
    size_(size)
{
    for(size_t i = 0; i < size; i++)
        data_[i] = 0;
    printf("Hello. motherfucker, I'm constructor\n");
}
//=========================================================
template <typename DataT>                                   // This == Thatt
Array<DataT>::Array(const Array& that) :
    data_(new DataT[that.size_]),
    size_(that.size_)
{
    std::copy_n(that.data_, that.size_, data_);
    printf("Hello. motherfucker, I'm copy constructor\n");
}
//=========================================================
/*
template <typename DataT>                                    // ???????????????
Array<DataT>::Array(Array&& that) :
    data_(that.data_),
    size_(that.size_)
{
    printf("Hello. motherfucker, I'm move constructor\n");
    that.data_ = nullptr;

}
*/
//=========================================================
template <typename DataT>
Array<DataT>::~Array(void) {
    for(size_t i = 0; i < size_; i++)
        data_[i] = -99;
    delete[] data_;
    data_ = nullptr;
    size_ = 0;
    printf("Hello. motherfucker, I'm destructor\n");
}
//=========================================================
template <typename DataT>
DataT& Array<DataT>::operator[](int pos) {
    if(pos < 0 || pos > size_)
        throw WRONG_POS;
    return data_[pos];
}
//=========================================================
template <typename DataT>
void Array<DataT>::Swap(Array& that) {
    std::swap(size_, that.size_);
    std::swap(data_, that.data_);
}
//=========================================================
template <typename DataT>
Array<DataT>& Array<DataT>::operator=(Array that) {
    printf("Hello. motherfucker, I'm =\n");
    Swap(that);
    return *this;
}
//=========================================================
/*
template <typename DataT>                                   // ???????????????
Array<DataT>& Array<DataT>::operator=(Array&& that) {
    printf("Hello. motherfucker, I'm move =\n");
    Swap(that);
    return *this;
}
*/
//=========================================================
template <typename DataT>
void Array<DataT>::Print(void) const {
    std::cout << std::endl;
    for(size_t i = 0; i < size_; i++)
        std::cout << "\t" << data_[i] << std::endl;
}
//=========================================================
template <typename DataT>
void Array<DataT>::Dump(void) const {
    std::cout << "\nsize_ = " << size_;
    std::cout << "\ndata_ = " << (void*)data_;
    Print();
    std::cout << std::endl;
}
//=========================================================
template <typename DataT>
Array<DataT> GetArray() {
    Array<DataT> a(10);
    printf("\nI'm GetArray\n");
    return a;
}

int main(void) {
  /*  Array<int> a1(10);
    for(int i = 0; i < 10; i++)
        printf("%d\n", a1[i]);
    for(int i = 0; i < 10; i++)
        a1[i] = i;
    a1.Dump();
    Array<int> a2(a1);
    a2.Dump();      */
//    Array<int> a3(5);
 //   a3 = Array<int>(10);
    Array<int> a = GetArray<int>();
    a.Dump();
  //  a3.Dump();
 /*   Array<int> a4;
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
    return 0;
}








