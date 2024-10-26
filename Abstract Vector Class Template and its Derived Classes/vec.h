#ifndef BASIC_VEC
#define BASIC_VEC
#include <iostream>
using namespace std;
template<typename T>
class basic_vec{

 
public:
    basic_vec(int num = 0, const T* x = NULL);	
    basic_vec(const basic_vec& v);				
    virtual ~basic_vec();
    basic_vec& operator=(const basic_vec& v);	

    int Size() const;
	void resize(int num);
    T & operator[](int)const;
    virtual void Input(istream& in) = 0;
    virtual void Output(ostream& out) const = 0 ;//纯虚函数，记得在派生类中重新定义
	virtual basic_vec& operator+(const basic_vec<T> & vv)=0;



protected:
	int size;
	T* ptr;

};

template <typename T>
basic_vec<T>::basic_vec(int num, const T* x)	
{
	size = (num > 0) ? num : 0;
	ptr = NULL;
	if (size > 0)
	{
		ptr = new T[size];
		for (int i = 0; i < size; i++)
			ptr[i] = (x == NULL) ? 0 : x[i];
	}
}

template <typename T>
basic_vec<T>::basic_vec(const basic_vec<T>& v)	
{

	if ((size = v.size) == 0)
		ptr = NULL;
	else
	{
		ptr = new T[size];
		for (int i = 0; i < size; i++)
			ptr[i] = v.ptr[i];
	}
}

template <typename T>
basic_vec<T>::~basic_vec()						
{
	if (ptr != NULL) delete[] ptr;
}

template <typename T>
basic_vec<T>& basic_vec<T>::operator=(const basic_vec<T>& v)
{
	if (size != v.size)
	{
		if (ptr != NULL) delete[] ptr;
		ptr = new T[size = v.size];
	}
	for (int i = 0; i < size; i++)
		ptr[i] = v.ptr[i];
	return *this;
}


template<typename T>
int basic_vec<T>::Size()const{
    return size;
}

template <typename T>
void basic_vec<T>::resize(int num)			
{
	if (num < 0 || num == size)
		return;
	else if (num == 0)
	{
		if (ptr != NULL) delete[] ptr;
		ptr = NULL;
		size = 0;
	}
	else
	{
		T* temp = ptr;
		ptr = new T[num];
		for (int i = 0; i < num; i++)
			ptr[i] = (i < size) ? temp[i] : 0;	// 尽量保留原有数据
		size = num;
		delete[] temp;
	}
}


template<typename T>
T & basic_vec<T>::operator[](int pos)const{
    if(pos>=size || pos<0)
        throw "yuejie";
    return ptr[pos];
}

template <typename T>
ostream& operator<<(ostream& out, const basic_vec<T>& v)	// 不必是友元函数
{
	v.Output(out);
	return out;
}

template <typename T>
istream& operator>>(istream& in, basic_vec<T>& v)			// 不必是友元函数
{
	v.Input(in);
	return in;
}
#endif