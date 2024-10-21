#ifndef BASIC_VEC
#define BASIC_VEC
#include <iostream>
using namespace std;
template<typename T>
class basic_vec{
protected:
    T *ptr;
    T *start;
    T *end;
    //新加了定位指针
    int size;
    int capacity;
    basic_vec(int cap);//初始化

    virtual input(istream)=0 const;
    virtual output(ostream)=0 const;
};
template<typename T>
basic_vec<T>::basic_vec(int cap):size(0),capacity(cap),ptr(new T[capacity]),start(ptr),end(ptr){}

#endif
