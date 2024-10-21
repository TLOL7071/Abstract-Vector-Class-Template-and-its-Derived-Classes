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
    basic_vec();

    virtual input(istream)=0 const;
    virtual output(ostream)=0 const;//纯虚函数，记得在派生类中重新定义
};
template<typename T>
basic_vec<T>::basic_vec(int cap):size(0),capacity(cap),ptr(new T[capacity]),start(ptr),end(ptr){}
//构造函数，记得在派生类的构造函数中显式的调用基类构造函数（这样做最好。如果你明白你在做什么，就随你来）
template<typename T>
basic_vec<T>::basic_vec():size(0),capacity(0),ptr(nullptr),start(ptr),end(ptr){}
//默认构造函数
#endif
