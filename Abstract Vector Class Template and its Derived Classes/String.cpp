// String.cpp
#include "String.h"
#include <cstring>

String ::~String(){}
String& String::operator+(const basic_vec<char> &vv){
	static String temp;
	temp.resize(this->Size()+vv.Size());
	for(int i=0;i<this->Size();i++){
		cout<<"chishi";
		temp[i]=this->operator[](i);//chou lou de xie fa
	}
	for(int i=this->Size();i<this->Size()+vv.Size();i++){
		temp[i]=vv[i];	
	}
	return temp;
}
String::String(const char* str) : basic_vec<char>(strlen(str),str)
{

}


void String::Input(istream& in)	// �����Զ���չ���������Ĺ���
{
	const int N = 1;//1024;		// Nȡ��Сֵ1��Ϊ�˵��ԣ�ʵ��ʹ��ʱȡ1024
	char buffer[N], ch;			// ���뻺����
	int i, j, k, flag;
	String temp;

	while (true)					// ���˵���Ч�ַ�ǰ�Ŀհ��ַ�
	{
		ch = in.peek();			// ͵����һ���ַ������Ƿ�Ϊ�հ��ַ�
		if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r')
			in.get(ch);			// ���ǿհ��ַ�������˵�������ȡ���ã�
		else
			break;				// ֱ�������ǿհ��ַ���������whileѭ��
	}
	for (k = 0, flag = 1; flag == 1; k++)
	{
		for (i = 0; i < N; i++)
		{
			ch = in.peek();
			if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r')
			{
				flag = 0;
				break;
			}
			else
				in.get(buffer[i]);
		}
		temp.resize(k * N + i);			// ������resize������"����������ԭ������"�Ĺ���
		for (j = 0; j < i; j++)
			temp[k * N + j] = buffer[j];// �����˷����������
	}
	*this = temp;					// �����˸�ֵ��������ֵ���㣩
}

void String::Output(ostream& out) const
{
	for (int i = 0; i < size; i++)
		out << ptr[i];
}












String& String::insert(int p0, const char* s)
{
	int n = size;
	if (p0 > n) p0 = n;
	char* p = new char[size + strlen(s) + 1];
	strncpy(p, ptr, p0);		// ԭ�ַ������ݵĵ�һ����
	p[p0] = '\0';
	strcat(p, s);				// ����Ĳ���
	strcat(p, ptr + p0);		// ԭ�ַ�����ʣ�ಿ��
	size = size + strlen(s);
	delete[] ptr;				// �ͷ�ԭ�ַ���
	ptr = p;					// �������ַ������׵�ַ
	return *this;
}


int String::find(const String& Str) const
{
	int i, j, m, n, flag;
	m = Str.size;
	n = size;
	if (m > n) return -1;
	for (i = 0; i < n - m; i++)
	{
		flag = 1;
		for (j = 0; j < m; j++)
			if (ptr[i + j] != Str.ptr[j])
			{
				flag = 0;
				break;
			}
		if (flag == 1)
			return i;
	}
	return -1;
}

int String::length() const
{
	return size;
}

const char* String::c_str()
{
	return ptr;
}

void String::swap(String& Str)
{
	char* temp = Str.ptr;
	Str.ptr = ptr;
	ptr = temp;
}

void String::clear()
{
	*this = "\0";
}
String& String::append(const char* s) {
	if (s == nullptr) return *this; // Handle null input

	int new_size = size + strlen(s);
	char* new_ptr = new char[new_size + 1]; // Allocate new memory

	strcpy(new_ptr, ptr); // Copy the existing string
	strcat(new_ptr, s);   // Append the new string

	delete[] ptr; // Free the old memory
	ptr = new_ptr; // Update the pointer to the new memory
	size = new_size; // Update the size

	return *this;
}


// String operator+(const String& Str1, const String& Str2) {
// 	String temp;
// 	temp.ptr = new char[Str1.size + Str2.size + 1];
// 	temp.size = Str1.size + Str2.size;
// 	strcpy(temp.ptr, Str1.ptr);
// 	strcat(temp.ptr, Str2.ptr);
// 	return temp;
// }


String& String::operator+=(const String& Str)
{
	*this = *this + Str;
	return *this;
}

bool operator==(const String& Str1, const String& Str2)
{
	return strcmp(Str1.ptr, Str2.ptr) == 0;
}

bool operator!=(const String& Str1, const String& Str2)
{
	return strcmp(Str1.ptr, Str2.ptr) != 0;
}

bool operator> (const String& Str1, const String& Str2)
{
	return strcmp(Str1.ptr, Str2.ptr) > 0;
}

bool operator>=(const String& Str1, const String& Str2)
{
	return strcmp(Str1.ptr, Str2.ptr) >= 0;
}

bool operator< (const String& Str1, const String& Str2)
{
	return strcmp(Str1.ptr, Str2.ptr) < 0;
}

bool operator<=(const String& Str1, const String& Str2)
{
	return strcmp(Str1.ptr, Str2.ptr) <= 0;
}



// ���ӵĳ�Ա����
// istream& getline(istream& in, String& Str, int num, char delim='\n')
// {
// 	if (num <= 0) return in;

// 	if (Str.ptr != NULL) delete[] Str.ptr;
// 	Str.ptr = new char[num + 1];
// 	in.getline(Str.ptr, num, delim);
// 	return in;
// }

String& String::trim()
{
	int i, j = strlen(ptr);

	if (j == 0) return *this;

	for (j--; j >= 0 && (ptr[j] == ' ' || ptr[j] == '\t'); j--)
		;
	ptr[j + 1] = '\0';
	for (i = 0; ptr[i] == ' ' || ptr[i] == '\t'; i++)
		;
	if (i > j)
	{
		delete[] ptr;
		ptr = new char[1];
		ptr[0] = '\0';
	}
	else
	{
		char* temp = new char[j - i + 2];
		strcpy(temp, ptr + i);
		delete[] ptr;
		ptr = temp;
	}
	return *this;
}
