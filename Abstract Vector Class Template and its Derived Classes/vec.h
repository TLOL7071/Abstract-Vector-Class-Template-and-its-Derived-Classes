#ifndef BASIC_VEC
#define BASIC_VEC
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

public:
    virtual bool push_back(T)=0;
    virtual bool resize(int)=0;
    virtual bool pop()=0;
    virtual T at(int pos)=0;
};
template<typename T>
basic_vec<T>::basic_vec(int cap):size(0),capacity(cap),ptr(new T[capacity]),start(ptr),end(ptr){}
#endif()
