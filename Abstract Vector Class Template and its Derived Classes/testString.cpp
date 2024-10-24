#include <iostream>
#include "String.h"
#include <cstring>
using namespace std;
void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();
void testString() {

    String str1, str2, result;
    int choice;
    do {
        cout << "请选择要测试的功能：" << endl;
        cout << "1. 测试构造函数" << endl;
        cout << "2. 测试连接" << endl;
        cout << "3. 测试插入" << endl;
        cout << "4. 测试查找" << endl;
        cout << "5. 测试清空" << endl;
        cout << "6. 测试异常处理" << endl;
        cout << "7.测试派生类函数" << endl;
        cout << "0. 退出" << endl;
        cout << "输入你的选择: ";
        input(choice);
        switch (choice) {
        case 1:
            test1();
            break;
        case 2:
            test2();
            break;
        case 3: {
            test3();
            break;
        }
        case 4: {
            test4();
            break;
        }
        case 5: {
            test5();
            break;
        }
        case 6:
            test6();
            break;
        case 7:
            test7();
            break;
        case 0:
            cout << "退出程序";
            break;
        default:
            cout << "无效的选择，请重新输入。" << endl;
        }
    } while (choice != 0);
}
void test1() {
    basic_vec<char>* pStr; //积累指针
    String str1("Hello, ");
    String str2("World!");
    pStr = &str1;
    cout << "str1: ";
    pStr->Output(cout);
    pStr = &str2;
    cout << "str2: ";
    pStr->Output(cout);
    cout << endl;
}
void test2() {
    basic_vec<char>* pStr; //积累指针
    String str1("Hello, ");
    String str2("World!");
    String str3 = str1 + str2;
	cout << "str1: " << str1 << endl;
	cout << "str2: " << str2 << endl;
    cout << "str3 (str1 + str2): ";
    str3.Output(cout);
	cout << endl;

	

}
void test3() {
    basic_vec<char>* pStr; //积累指针
    String str1("Hllo");
    str1.Output(cout);
	cout << endl;
    str1.insert(1, "e");
    cout << "After insert: ";
    str1.Output(cout);
}
void test4() {
    String str1("Hello");
    cout << "str为：";
    str1.Output(cout);
    cout << endl;
    int pos = str1.find("l");
    cout << "l的位置是：" << pos << endl;
}
void test5() {
    String str1("Hello");
    cout << "str为：";
    str1.Output(cout);
    cout << endl;
    cout << "str长度为：" << str1.length() << endl;
    str1.clear();
    cout << "清空后长度为：" << str1.length() << endl;
}
void test6() {
    try {
        String str1("Hello");
        cout << str1[5];// 应该抛出异常
    }
    catch (const char* e) {
        cout << "抛出异常： " << e << endl;
    }
}
void test7() {
    cout << "使用基类指针调用Input:" << endl;
    basic_vec<char>* p;
    String str1;
    p = &str1;
    p->Input(cin);
    cout << "调用Output:" << endl;
    p->Output(cout);
    cout << endl;
}

