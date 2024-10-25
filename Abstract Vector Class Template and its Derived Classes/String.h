// String.h
#ifndef MY_STRING_H
#define MY_STRING_H
#include <iostream>
using namespace std;
#include "vec.h"
class String : public basic_vec <char>
{
public:
	String(const char* str = "");						// 构造函数


	//继承多态性
	void Input(istream& in);
	void Output(ostream& out) const;
	
	
	//功能函数
	String& insert(int p0, const char* s);			// 将 s 所指向的字符串插入在本串位置 p0 之前
	int find(const String& Str) const;				// 查找并返回 Str 在本串中第一次出现的位置
	int length() const;							// 返回串的长度（字符个数）
	const char* c_str();							// 转换为 C-字符串
	void swap(String& Str);							// 将本串与 Str 交换
	void clear();									// 清空String
	String& append(const char* s);                  //向字符串的末尾添加字符

	//运算符函数
	String operator+(const String& Str); // 友元函数，字符串拼接
	String& operator+=(const String& Str);			// 字符串拼接及赋值

	// 重载关系运算
	friend bool operator==(const String& Str1, const String& Str2);
	friend bool operator!=(const String& Str1, const String& Str2);
	friend bool operator> (const String& Str1, const String& Str2);
	friend bool operator>=(const String& Str1, const String& Str2);
	friend bool operator< (const String& Str1, const String& Str2);
	friend bool operator<=(const String& Str1, const String& Str2);
	
	// 附加的成员函数
	friend istream& getline(istream& in, String& Str, int num, char delim = '\n');
	String& trim();								// 删除字符串前后的空白（空格、制表）字符
};

void testString();
void input(int& op);
#endif

#pragma once
