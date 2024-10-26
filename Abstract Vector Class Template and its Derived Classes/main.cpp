#include "Vector.h"
// #include "vec.h"
#include "String.h"
int main(){
    String dsd;
    String ass;
    dsd + ass;
    //String sa;
    //dsd+sa;
   // 测试默认构造函数
    Vector<int> vecDefault;
    cout << "Default Vector: ";
    for (int i = 0; i < 10; ++i) {
        vecDefault.push(i+1);
    }
    cout << vecDefault << endl;
    // 测试带初始容量的构造函数
    Vector<int> vecCapacity(5);   
    for (int i = 0; i < 5; ++i) {
        vecCapacity.push(i * 10);
    }
    cout << "Vector with capacity 5: " << vecCapacity << endl;
    
    cin.get();
    // 测试带初始容量和值的构造函数
    Vector<int> vecWithValues(3, -1);
    cout << "Vector with 3 elements initialized to -1: " << vecWithValues << endl;

    cin.get();
    // 测试拷贝构造函数
    Vector<int> vecCopy(vecWithValues);
    cout << "Copied Vector: " << vecCopy << endl;

    cin.get();
    // 测试赋值运算符
    vecWithValues = vecCapacity;
    cout << "vecWithValues (after assignment from vecCapacity): " << vecWithValues << endl;

    cin.get();
    // 测试插入功能
    vecDefault.insert(5, 99);
    cout << "vecDefault after inserting 99 at position 5: " << vecDefault << endl;

    cin.get();
    // 测试插入多个元素的功能
    vecDefault.insert(1, 200, 2);
    cout << "vecDefault after inserting 2 elements of 200 starting from position 1: " << vecDefault << endl;

    cin.get();
    // 测试删除功能
    vecDefault.Delete(4, 6);
    cout << "vecDefault after deleting element from position 4: " << vecDefault << endl;

    vecDefault.Delete(1);
    cout<<vecDefault<<endl;

    cin.get();
    //测试交换功能
    cout << "Before swap:\n";
    cout << "vecDefault: ";
    for (int i = 0; i < vecDefault.Size(); ++i) {
               cout << vecDefault[i] << " ";
    }
    cout << "\nvecCapacity: ";
    for (int i = 0; i < vecCapacity .Size(); ++i) {
        cout << vecCapacity[i] << " ";
    }

    cout<<endl;
    cout << "vec1 capacity before swap: " << vecDefault.Capacity() << endl;
    cout << "vec2 capacity before swap: " << vecCapacity .Capacity() << endl;
    cout << "vec1 size before swap: " << vecDefault.Size() << endl;
    cout << "vec2 size before swap: " << vecCapacity.Size() << endl;

    vecDefault .swap(vecCapacity);
    cout << "\nAfter swap:\n";
    cout << "vecDefault: ";
    for (int i = 0; i < vecDefault.Size(); ++i) {
        cout << vecDefault[i] << " ";
    }
    cout << "\nvecCapacity: ";
    for (int i = 0; i < vecCapacity.Size(); ++i) {
        cout << vecCapacity[i] << " ";
    }

    cout<<'\n';
    cout << "vec1 capacity after swap: " << vecDefault.Capacity() << endl;
    cout << "vec2 capacity after swap: " << vecCapacity .Capacity() << endl;
    cout << "vec1 size after swap: " << vecDefault.Size() << endl;
    cout << "vec2 size after swap: " << vecCapacity.Size() << endl;

    cin.get();
    // 测试下标越界异常
    try {
        cout << "Element at index 15: " << vecDefault.at(15) << endl;
    }
    catch (const char *e) {
        cout << "Exception caught: " << e << endl;
    }

    cin.get();
    // 测试容量调整
    cout << "vecDefault capacity before free2: " << vecDefault.Capacity() << endl;
    vecDefault.free2();
    cout << "vecDefault capacity after free2: " << vecDefault.Capacity() << endl;

    cin.get();
    // 测试pop功能
    cout<<vecDefault<<endl;
    cout<<vecDefault.Size();
    cout << "Element popped: " << vecDefault.at(vecDefault.Size()-1) << endl;
    vecDefault.pop();
    cout << "vecDefault after popping: " << vecDefault << endl;

    cin.get();
    // 测试友元输入运算符
    cout << "Enter elements for vecInput (end with newline):" << endl;
    Vector<int> vecInput;
    cin >> vecInput;
    cout << "Input Vector: " << vecInput<<'\n';

    //测试加法
    try{
        cout<<"vecDefault size "<<vecDefault.Size()<<'\n';
        cout<<"vecCopy size "<<vecCopy.Size()<<'\n';
        cout<<"vecDefault+vecCopy";
        cout<<vecDefault + vecCopy;
    }
    catch(const char *c){
            cout<<c<<"\ncant add two vector with different size"<<std::endl;
    }

    //测试
    try{
        cout<<"vecDefault capacity"<<vecDefault.Size()<<'\n';
        vecDefault.reserve(12);
        cout<<"after reserve      "<<vecDefault.Capacity()<<endl;
    }
    catch(const char *p){
        cout<<p;
    }

    cout<<"char\n";
    Vector<char> vecChar;
    cin>>vecChar;
    cout<<vecChar;

    return 0;
}