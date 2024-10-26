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
	String(const char* str = "");						// ���캯��
	

	//�̳ж�̬��
	void Input(istream& in);
	void Output(ostream& out) const;
	
	
	//���ܺ���
	String& insert(int p0, const char* s);			// �� s ��ָ����ַ��������ڱ���λ�� p0 ֮ǰ
	int find(const String& Str) const;				// ���Ҳ����� Str �ڱ����е�һ�γ��ֵ�λ��
	int length() const;							// ���ش��ĳ��ȣ��ַ�������
	const char* c_str();							// ת��Ϊ C-�ַ���
	void swap(String& Str);							// �������� Str ����
	void clear();									// ���String
	String& append(const char* s);                  //���ַ�����ĩβ�����ַ�

	//���������
	//friend String operator+(const String& str1, const String& Str2); // ��Ԫ�������ַ���ƴ��
	String& operator+=(const String& Str);			// �ַ���ƴ�Ӽ���ֵ
	
	String & operator+(const basic_vec<char> &vv);
	// ���ع�ϵ����
	friend bool operator==(const String& Str1, const String& Str2);
	friend bool operator!=(const String& Str1, const String& Str2);
	friend bool operator> (const String& Str1, const String& Str2);
	friend bool operator>=(const String& Str1, const String& Str2);
	friend bool operator< (const String& Str1, const String& Str2);
	friend bool operator<=(const String& Str1, const String& Str2);
	
	// ���ӵĳ�Ա����
	friend istream& getline(istream& in, String& Str, int num, char delim);
	String& trim();								// ɾ���ַ���ǰ��Ŀհף��ո��Ʊ����ַ�
};

void testString();
void input(int& op);
#endif

#pragma once
