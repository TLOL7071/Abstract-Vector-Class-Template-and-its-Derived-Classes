// String.h
#ifndef MY_STRING_H
#define MY_STRING_H
#include <iostream>
using namespace std;
#include "vec.h"
class String : public basic_vec <char>
{
public:
	~String();
	String(const char* str = "");						// 锟斤拷锟届函锟斤拷
	

	//锟教承讹拷态锟斤拷
	void Input(istream& in);
	void Output(ostream& out) const;
	
	
	//锟斤拷锟杰猴拷锟斤拷
	String& insert(int p0, const char* s);			// 锟斤拷 s 锟斤拷指锟斤拷锟斤拷址锟斤拷锟斤拷锟斤拷锟斤拷诒锟斤拷锟轿伙拷锟� p0 之前
	int find(const String& Str) const;				// 锟斤拷锟揭诧拷锟斤拷锟斤拷 Str 锟节憋拷锟斤拷锟叫碉拷一锟轿筹拷锟街碉拷位锟斤拷
	int length() const;							// 锟斤拷锟截达拷锟侥筹拷锟饺ｏ拷锟街凤拷锟斤拷锟斤拷锟斤拷
	const char* c_str();							// 转锟斤拷为 C-锟街凤拷锟斤拷
	void swap(String& Str);							// 锟斤拷锟斤拷锟斤拷锟斤拷 Str 锟斤拷锟斤拷
	void clear();									// 锟斤拷锟絊tring
	String& append(const char* s);                  //锟斤拷锟街凤拷锟斤拷锟斤拷末尾锟斤拷锟斤拷锟街凤拷


	//锟斤拷锟斤拷锟斤拷锟斤拷锟�
	//friend String operator+(const String& str1, const String& Str2); // 锟斤拷元锟斤拷锟斤拷锟斤拷锟街凤拷锟斤拷拼锟斤拷
	String& operator+=(const String& Str);			// 锟街凤拷锟斤拷拼锟接硷拷锟斤拷值
	
	String & operator+(const basic_vec<char> &vv);
	// 锟斤拷锟截癸拷系锟斤拷锟斤拷

	//运算符函数
	String& operator+(const basic_vec<char> & vv); // 友元函数，字符串拼接
	String& operator+=(const String& Str);			// 字符串拼接及赋值

	// 重载关系运算

	friend bool operator==(const String& Str1, const String& Str2);
	friend bool operator!=(const String& Str1, const String& Str2);
	friend bool operator> (const String& Str1, const String& Str2);
	friend bool operator>=(const String& Str1, const String& Str2);
	friend bool operator< (const String& Str1, const String& Str2);
	friend bool operator<=(const String& Str1, const String& Str2);
	
	// 锟斤拷锟接的筹拷员锟斤拷锟斤拷
	//friend istream& getline(istream& in, String& Str, int num, char delim);
	String& trim();								// 删锟斤拷锟街凤拷锟斤拷前锟斤拷目瞻祝锟斤拷崭锟斤拷票锟斤拷锟斤拷址锟�
};

void testString();
void input(int& op);
#endif

#pragma once
