#include "String.h"
#include "Vector.h"
#include <iostream>
using namespace std;
int main() {
	/*int choice;

	cout << "ÇëÑ¡ÔñÒª²âÊÔµÄÀà£º" << endl;
	cout << "1. String" << endl;
	cout << "2. Vector" << endl;
	cout << "ÊäÈëÄãµÄÑ¡Ôñ: ";

	cin >> choice;
	
	switch (choice) {
	case 1:
		testStringFunctions();
		break;
	case 2:
		testVector();
		break;
	}
	cout << "¶àÌ¬ÐÔ²âÊÔ" << endl;
	cout << "StringÀà²âÊÔ" << endl;
	basic_vec<char> *op;
	String str1 = "hello";

	op=&str1;
	str1.Output(cout);
	op->Output(cout);

	cout << endl;
	cout << str1.Size() << endl;
	str1.resize(2);
	str1.Output(cout);
	cout << str1.Size() << endl;
	cout << "ÇëÊäÈë×Ö·û´®£º" << endl;
	str1.Input(cin);
	str1.Output(cout);
	cout << endl;

	cout << "VectorÀà²âÊÔ" << endl;
	Vector<char> vec;
	cout << "ÇëÊäÈë×Ö·û´®£º" << endl;
	vec.Input(cin);
	vec.Output(cout);
	cout << vec.Size() << endl;
	vec.resize(2);
	vec.Output(cout);
	cout << vec.Size() << endl;

	op = &vec;
	op->Output(cout);*/
	String str1 = "hello";
	String str2 = "world";
	cout<< str1 + str2;
	//cout << str3[8] << endl;
	return 0;
}