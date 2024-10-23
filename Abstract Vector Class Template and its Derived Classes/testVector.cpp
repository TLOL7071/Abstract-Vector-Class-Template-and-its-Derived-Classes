#include <iostream>
#include "Vector.h"  
using namespace std;

void testVector() {
    Vector<int> vec;

    int choice;
    while (true) {
        cout << "\n请选择要测试的功能（输入 0 退出）:\n";
        cout << "1. 添加元素到末尾\n";
        cout << "2. 弹出最后一个元素\n";
        cout << "3. 输出当前元素\n";
        cout << "4. 检查是否为空\n";
        cout << "5. 获取元素\n";
        cout << "6. 复制构造函数\n";
        cout << "7. 容量信息\n";
        cout << "8. 释放未使用空间\n";
        cout << "9. 清除元素\n";
        cout << "输入你的选择: ";
        cin >> choice;

        if (choice == 0) {
            break;
        }

        switch (choice) {
        case 1: {
            int element;
            cout << "输入要添加的元素: ";
            cin >> element;
            vec.push(element);
            cout << "元素 " << element << " 已添加.\n";
            break;
        }
        case 2: {
            try {
                vec.pop();
                cout << "最后一个元素已弹出.\n";
            }
            catch (const char* msg) {
                cout << msg << endl;  // 输出异常信息
            }
            break;
        }
        case 3: {
            cout << "当前元素: ";
            vec.Output(cout);
            cout << endl;
            break;
        }
        case 4: {
            if (vec.empty()) {
                cout << "Vector 是空的.\n";
            }
            else {
                cout << "Vector 不是空的.\n";
            }
            break;
        }
        case 5: {
            int index;
            cout << "输入要获取的索引: ";
            cin >> index;
            try {
                cout << "第 " << index << " 个元素: " << vec.at(index) << endl;
            }
            catch (const char* msg) {
                cout << msg << endl;  // 输出异常信息
            }
            break;
        }
        case 6: {
            Vector<int> vec2(vec);  // 使用复制构造函数
            cout << "使用复制构造函数创建 vec2.\n";
            cout << "vec2 的元素: ";
            vec2.Output(cout);
            cout << endl;
            break;
        }
        case 7: {
            cout << "当前容量: " << vec.Capacity() << endl;
            break;
        }
        case 8: {
            vec.free2();
            cout << "已释放未使用的空间.\n";
            break;
        }
        case 9: {
            vec.Delete(0);  // 删除第一个元素
            cout << "已删除第一个元素.\n";
            break;
        }
        default:
            cout << "无效的选择，请重新输入.\n";
            break;
        }
    }
}