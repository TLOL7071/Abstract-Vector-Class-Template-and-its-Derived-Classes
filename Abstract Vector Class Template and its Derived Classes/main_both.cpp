#include "string.h"
#include "Vector.h"
#include <iostream>
void testduotai();
using namespace std;
int main() {
    int choice = 1;
    while (choice != 0) {
        cout << "1、测试String类" << endl;
        cout << "2、测试Vector类" << endl;
        cout << "3、测试多态性" << endl;
        cout << "0、退出程序" << endl;
        input(choice);
        switch (choice)
        {
        case 1:testString();
            break;
        case 2:testVector();
            break;
        case 3:testduotai();
            break;
        default:cout << "无效输入，请重输" << endl;
            break;
        case 0:cout << "退出程序" << endl;
        }
    }
    return 0;
}
void testduotai() {
    cout << "string类多态测试:" << endl;
    cout << "使用基类指针调用Input:" << endl;
    basic_vec<char>* p;
    String str1;
    p = &str1;
    p->Input(cin);
    cout << "调用Output:" << endl;
    p->Output(cout);
    cout << endl;
    cout << "Vector类多态测试:" << endl;
    Vector<int> vecInt0;
    Vector<double> vecDouble0;
    Vector<char> vecChar0;
    for (int i = 0; i < 10; ++i) {
        vecInt0.push(i);
        vecDouble0.push(i * 1.1);
        vecChar0.push('A' + i);
    }
    basic_vec<int>* pVecInt0 = &vecInt0;
    basic_vec<double>* pVecDouble0 = &vecDouble0;
    basic_vec<char>* pVecChar0 = &vecChar0;
    cout << "对int类型的Output: ";
    pVecInt0->Output(cout);
    cout << endl;
    cout << "对double类型的Output: ";
    pVecDouble0->Output(cout);
    cout << endl;
    cout << "对char类型的Output: ";
    pVecChar0->Output(cout);
    cout << endl;
    Vector<int> vecInt10;
    Vector<double> vecDouble10;
    Vector<char> vecChar10;
    cout << "对int类型的Input: ";
    pVecInt0 = &vecInt10;
    pVecInt0->Input(cin);
    pVecInt0->Output(cout);
    cout << endl;
    cout << "对double类型的Input: ";
    pVecDouble0 = &vecDouble10;
    pVecDouble0->Input(cin);
    pVecDouble0->Output(cout);
    cout << endl;
    pVecChar0 = &vecChar10;
    cout << "对char类型的Output: ";
    pVecChar0->Input(cin);
    pVecChar0->Output(cout);
    cout << endl;
}