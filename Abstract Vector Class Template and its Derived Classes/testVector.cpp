#include <iostream>
#include "Vector.h" 
#include"string.h"
using namespace std;
void testa();
void testb();
void testc();
void testd();
void teste(); // 测试 pop 函数
void testf(); // 测试 push 函数
void testg(); // 测试 at 函数
void testh(); // 测试 operator[] 函数
void testi(); // 测试 operator+ 函数
void testj(); // 测试 swap 函数

void testVector() {
    Vector<int> vec;

    int choice;
    while (true) {
        cout << "\n请选择要测试的功能（输入 0 退出）:\n";
        cout << "1. 测试输出\n";
        cout << "2. 测试派生类函数\n";
        cout << "3. 测试异常处理\n";
        cout << "4. 测试insert\n";
        cout << "5. 测试pop\n";
        cout << "6. 测试push\n";
        cout << "7. 测试at\n";
        cout << "8. 测试下标运算符\n";
        cout << "9. 测试加法运算符\n";
        cout << "10. 测试swap\n";
        cout << "输入你的选择: ";
        input(choice);

        if (choice == 0) {
            break;
        }

        switch (choice) {
        case 1: {
            testa();
            break;
        }
        case 2: {
            testb();
            break;
        }
        case 3: {
            testc();
            break;
        }
        case 4: {
            testd();
            break;
        }
        case 5: {
            teste();
            break;
        }
        case 6: {
            testf();
            break;
        }
        case 7: {
            testg();
            break;
        }
        case 8: {
            testh();
            break;
        }
        case 9: {
            testi();
            break;
        }
        case 10: {
            testj();
        }
        default:

            break;
        }
    }
}
void testa() {
    Vector<int> vecInt;
    Vector<double> vecDouble;
    Vector<char> vecChar;


    for (int i = 0; i < 10; ++i) {
        vecInt.push(i);
        vecDouble.push(i * 1.1);
        vecChar.push('A' + i);
    }

    cout << "vecInt: ";
    vecInt.Output(cout);
    cout << endl;
    cout << "vecDouble: ";
    vecDouble.Output(cout);
    cout << endl;
    cout << "vecChar: ";
    vecChar.Output(cout);
    cout << endl;
}
void testb() {
    Vector<int> vecInt;
    Vector<double> vecDouble;
    Vector<char> vecChar;


    for (int i = 0; i < 10; ++i) {
        vecInt.push(i);
        vecDouble.push(i * 1.1);
        vecChar.push('A' + i);
    }
    basic_vec<int>* pVecInt = &vecInt;
    basic_vec<double>* pVecDouble = &vecDouble;
    basic_vec<char>* pVecChar = &vecChar;

    cout << "对int类型的Output: ";
    pVecInt->Output(cout);
    cout << endl;
    cout << "对double类型的Output: ";
    pVecDouble->Output(cout);
    cout << endl;
    cout << "对char类型的Output: ";
    pVecChar->Output(cout);
    cout << endl;
    Vector<int> vecInt1;
    Vector<double> vecDouble1;
    Vector<char> vecChar1;
    cout << "对int类型的Input: ";
    pVecInt = &vecInt1;
    pVecInt->Input(cin);
    pVecInt->Output(cout);
    cout << endl;
    cout << "对double类型的Input: ";
    pVecDouble = &vecDouble1;
    pVecDouble->Input(cin);
    pVecDouble->Output(cout);
    cout << endl;
    pVecChar = &vecChar1;
    cout << "对char类型的Output: ";
    pVecChar->Input(cin);
    pVecChar->Output(cout);
    cout << endl;

}
void testc() {
    try {
        Vector<int> vecInt;
        for (int i = 0; i < 10; ++i) {
            vecInt.push(i);
        }
        cout << "越界异常测试：" << endl;
        vecInt.at(100);
    }
    catch (const char* e) {
        cout << "接受异常： " << e << endl;
    }
}
void testd() {
    Vector<int> vecInt;
    Vector<double> vecDouble;
    Vector<char> vecChar;


    for (int i = 0; i < 10; ++i) {
        vecInt.push(i);
        vecDouble.push(i * 1.1);
        vecChar.push('A' + i);
    }
    vecInt.insert(2, 42);
    cout << "在2的位置插入42: ";
    vecInt.Output(cout);
    cout << endl;
    vecDouble.insert(2, 4.2);
    cout << "在2的位置插入4.2: ";
    vecDouble.Output(cout);
    cout << endl;
    vecChar.insert(2, 'a');
    cout << "在2的位置插入: ";
    vecChar.Output(cout);
    cout << endl;

}
void teste() {
    Vector<int> vecInt;
    Vector<double> vecDouble;
    Vector<char> vecChar;
    for (int i = 0; i < 10; ++i) {
        vecInt.push(i);
        vecDouble.push(i * 1.1);
        vecChar.push('A' + i);
    }
    cout << "弹出前: ";
    vecInt.Output(cout);
    cout << endl;
    vecDouble.Output(cout);
    cout << endl;
    vecChar.Output(cout);
    cout << endl;
    vecInt.pop();
    vecChar.pop();
    vecDouble.pop();
    cout << "弹出后: ";
    vecInt.Output(cout);
    cout << endl;
    vecDouble.Output(cout);
    cout << endl;
    vecChar.Output(cout);
    cout << endl;
}

void testf() {
    Vector<double> vecDouble;
    vecDouble.push(1.1);
    vecDouble.push(2.2);
    cout << "添加元素1.1、2.2: ";
    vecDouble.Output(cout);
    cout << endl;
}

void testg() {
    Vector<char> vecChar;
    for (char c = 'A'; c <= 'E'; ++c) vecChar.push(c);
    cout << "vecChar数组内元素：" << vecChar << endl;
    cout << "访问元素C: " << vecChar.at(2) << endl;
}

void testh() {
    Vector<int> vecInt;
    for (int i = 0; i < 5; ++i) vecInt.push(i);
    cout << "vecInt数组内元素：";
    vecInt.Output(cout);
    cout << endl;
    cout << "访问第3个元素: " << vecInt[2] << endl;
}

void testi() {
    Vector<int> vec1, vec2;
    for (int i = 0; i < 5; ++i) {
        vec1.push(i);
        vec2.push(i * 2);
    }
    cout << "vec1:" << vec1 << " vec2:" << vec2 << endl;
    cout << "加法运算结果: ";
    cout << vec1 + vec2 << endl;
}

void testj() {
    Vector<int> vec1, vec2;
    for (int i = 0; i < 5; ++i) vec1.push(i);
    for (int i = 5; i < 10; ++i) vec2.push(i);
    cout << "交换前 vec1: ";
    vec1.Output(cout);
    cout << "交换前 vec2: ";
    vec2.Output(cout);
    vec1.swap(vec2);
    cout << "交换后 vec1: ";
    vec1.Output(cout);
    cout << "交换后 vec2: ";
    vec2.Output(cout);
}