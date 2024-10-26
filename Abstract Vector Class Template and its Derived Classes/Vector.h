#include "vec.h"
#include <stdexcept>
using namespace std;

template <typename type>
class Vector:public basic_vec<type>
{
private:
    int capacity;                               //容量
public:
    void Input(istream & in);
    void Output(ostream & out) const ;
    void reserve(int n);
    Vector();                                  //构造函�?1  将capacity设为15,p指向type类型的数组头
    Vector(int n);                              //构造函�?2  将capacity设为n*2�?
    Vector(int n, type m);                      //构造函�?3  将capacity设为n*2,将前n�?内�?�赋为type m
    Vector(Vector<type>& a);                    //复制构造函�? 利用copy函数复制数据，但具体�?持的数据类型不清楚，基本的int double等应该是�?以的，但不知道struct 和class 效果怎么�?//al:对class也有�?(english version:Also applicable to class type)
    explicit Vector(type* p1, type* p2);         //将type类型数组的p1和p2之间的数�?复制，两者顺序可以�?�倒，还有这是要显式调用的
    ~Vector();
    bool empty();                               //判断�?否为空，空返回true
    int Capacity();                             //返回capacity
    int Size();
    void pop();//弹出最后一�?数据成员，希望�?�这�?函数重写一遍，结合capacity，size�?          //al:试着完成�?(english version:have tried to solve the problem.)
    void push(type a);                          //将type a加入vector的末尾， 当�?�量capacity不足以存储时，扩容，希望对扩容功能加以�?��?   //al:加了一�?检测，但不知道你想在哪里�?�测�?
    type at(int i);//返回vector�?第i位的数据，�?�i越界的异常�?�理没有写完，希望补�?

    Vector & operator=(const Vector<type>& vec); //赋值运算�?�号，希望�?��?
    type& operator[](int i) ;//下表运算符，但没有越界�?�理//al:加入了越界�?�理
    Vector& operator++(int);//希望加入对数�?类型的判�?，以避免数据不满�?++运算操作
    Vector& operator++();

    void free2();                               //将�?�量变为size大小，及舍弃�?利用的空�?
    void insert(int position, type n);
    void insert(int position, type n, int m);
    void Delete(int n);
    void Delete(int n, int m);
    void swap(Vector<type>& vec);



    //basic_vec<type>& operator+(const basic_vec<type> & vec);//二选一

   // basic_vec<type>& operator+(const basic_vec<type> & vec);//二选一

    Vector& operator+(const basic_vec<type> &v);//��ѡһ


};

// template <typename type>
// ostream& operator<<(ostream& os, Vector<type>& vec);
void testVector();


template <typename type>
Vector<type> ::Vector():basic_vec<type>(0)             //构造函�?1
{
    capacity = 15;
    this->ptr = new type[capacity]();
}
template <typename type>
Vector<type>::Vector(int n):basic_vec<type>()           //���캯��2
{
    this->ptr = new type[n * 2];
    capacity = n * 2;
}
template <typename type>                //���캯��3
void Vector<type>::reserve(int n)             //�?改�?�得
{
    if(n<0){
        throw "n<0";
    }
    type *tempt=new type[n+this->size];
    for(int i=0;i<this->size;i++){
        tempt[i]=this->ptr[i];
    }
    capacity=this->size+n;
}
template <typename type>                //���캯��4
Vector<type> ::Vector(int n, type m)
{
    this->ptr = new type[n * 2];
    //memset(p,)
    fill(this->ptr, this->ptr + n, m);
    capacity = n * 2;
    this->size = n;
}
template<typename type>                 //�������캯��6
Vector<type>::Vector(Vector<type>& a):basic_vec<type>(a)
{
    this->ptr = new type[a.size * 2]();
    //copy(a.p, a.p + a.size, p);                        //copy�?浅拷贝，这里用type类型对应的深拷贝比较�?
    for (int i = 0; i < a.size; i++)
    {
        this->ptr[i] = a.ptr[i];                                   //对应type类型重载=来实现深拷贝
    }
    this->size = a.size;
    capacity = a.size * 2;
}
template<typename type>                 //���캯��7
Vector<type>::Vector(type* p1, type* p2)
{

    if ((p2 - p1) >= 0)
    {
        this->ptr = new type[(p2 - p1) * 2]();
        this->size = p2 - p1;
        capacity = (p2 - p1) * 2;
        for (int i = 0; i < p2 - p1; i++)
            this->ptr[i] = p1[i];
    }
    else
    {
        this->ptr = new type[(p1 - p2) * 2]();
        capacity = (p1 - p2) * 2;
        this->size = p1 - p2;
        for (int i = 0; i < p1 - p2; i++)
        {
            this->ptr[i] = p2[i];
        }
    }

}
template<typename type>                 //��������
Vector<type>::~Vector()
{
    //delete[]this->ptr;
}
template<typename type>                 //�ж�vector�Ƿ�Ϊ��
bool Vector<type>::empty()
{
    if (this->size == 0)
        return true;
    else
        return false;
}
template<typename type>                 //����capacity
int Vector<type>::
Capacity()
{
    return capacity;
}
template<typename type>                 //���ص�ǰ�洢����
int Vector<type>::Size()
{
    return this->size;
}
template<typename type>                 //ɾ�����һ���?������ǰvectorΪ�գ���ӡerror
void Vector<type>::pop()
{
    if (this->size >= 1)
    {
        if constexpr (!std::is_trivially_destructible<type>::value) {
            this->ptr[this->size - 1].~T();  //�?type为类弹出后执行它的析构函�?(english version:If the type is a class, its destructor is executed after popping.)
        }
        this->size--;
        if (this->size <= capacity / 4) {
            capacity /= 2;
            type* tempt = new type[this->capacity];
            for (int i = 0; i < this->size; i++)
            {
                tempt[i] = this->ptr[i];
            }
            delete[]this->ptr;
            this->ptr = tempt; /*al:按照要求对利用capacity和size重写了，不过感�?�没什么必要，如果你也认为这个缩小vector没必要的话，就删除这一段吧�?(english version : According to the requirements,
                       I rewrote it using capacity and size, but I don't think it's necessary. If you also believe that this resizing of the vector is unnecessary, feel free to delete that part.)*/
        }
        
    }
    else
    {
        cout << "error";
    }
}
template<typename type>                 //��˳������?�أ�
void Vector<type>::push(type a)
{
    if (this->size == this->capacity)
    {
        capacity *= 2;
        type* tempt = new(std::nothrow) type[this->capacity];
        if (!tempt)
        {
            throw std::runtime_error("Memory allocation failed");
        }
        for (int i = 0; i < this->size; i++)
        {
            tempt[i] = this->ptr[i];
        }
        delete[]this->ptr;
        this->ptr = tempt;
    }
    *(this->ptr + this->size) = a;
    this->size++;
}
template<typename type>                 //����vector���±�λ��Ԫ�أ����������ޣ����� 0X16
type Vector<type>::at(int i)
{
    if (i >= this->size)
    {
        throw "yuejie!\n";                //*******加入当i越界时，触发异常
    }
    return this->ptr[i];
}
template<typename type>                 //��=��������أ�ʵ��vec1=vec2��ֵ
Vector<type>& Vector<type>::  operator=(const Vector<type>& vec)
{
    // if(this == &vec)
    //     return *this;
    type* temp = new type[vec.capacity];
    for (int i = 0; i < vec.size; ++i) {
        temp[i] = vec.ptr[i];
    }
    delete[] this->ptr;
    this->ptr = temp;
    this->size = vec.size;
    this->capacity = vec.capacity;
    return *this;
}
template<typename type>             //��[]���أ�ʵ��vec[i]���±�Ϊi
type& Vector<type>:: operator[](int i)
{
    if(i>=this->size||i<0) throw(char)0;       //al:新�?�越界�?�问异常处理(english version:Add out-of-bounds access exception handling.)
    return this->ptr[i];
}

// template<typename type>             //��+���أ�ʵ��vec1+vec2����vec3�����и�Ԫ��Ϊ��Ӻ���?
// basic_vec<type>& Vector<type>:: operator+(const basic_vec<type>& vec)
// {
//     if(this->size!=vec.Size())
//         throw "different size";
//     static Vector<type> tempt;
//     
//     for(int i=0;i<vec.Size();i++)
//     {
//         tempt.ptr[i]+=vec[i];
//     }
//     return tempt;
// }
template<typename type>             
Vector<type>& Vector<type>:: operator+(const basic_vec<type>& vec)
{
    if(this->size!=vec.Size())
        throw "different size!!!";
    static Vector<type> tempt;
    tempt = *this;
    for(int i=0;i<vec.Size();i++)
    {
        tempt.ptr[i]+=vec[i];
    }
    return tempt;
}

//template<typename type>             //��+���أ�ʵ��vec1+vec2����vec3�����и�Ԫ��Ϊ��Ӻ���?
//basic_vec<type>& Vector<type>:: operator+(const basic_vec<type>& vec)
//{
//    if(this->size!=vec.Size())
//        throw "different size";
//    static Vector<type> tempt(*this);
//    for(int i=0;i<vec.Size();i++)
//    {
//        tempt.ptr[i]+=vec[i];
//    }
//    return tempt;
//}
 template<typename type>             
 Vector<type>& Vector<type>:: operator+(const basic_vec<type>& vec)
 {
     if(this->size!=vec.size)
         throw "different size";
     static Vector<type> tempt(*this);
     for(int i=0;i<vec.size;i++)
     {
         tempt.ptr[i]+=vec.ptr[i];
     }
     return tempt;
 }

template<typename type>                     //�Ժ�׺�����?++���أ�ʵ�ַ���++ǰ�Ķ���֮���ٶԲ�������ȫ��Ԫ�ؼ�1
Vector<type> & Vector<type>:: operator++(int)//��Ӽ�?
    {
        static Vector<type> tp(*this);
        static_assert(std::is_arithmetic<type>::value,"Vector element must be of arithmetic type" );
        for(int i=0;i<this->size;i++)
        {
            this->p[i]++;
        }
        return tp;
    }
template<typename type>                     //��ǰ׺�����?++���أ�ʵ���ȶԲ�������ȫ��Ԫ�ؼ�1���󷵻�++��Ķ���?
Vector<type>& Vector<type>:: operator++()//ǰ�Ӽ�
{
    for (int i = 0; i < this->size; i++)
    {
        this->p[i]++;
    }
    return *this;
}
template<typename type>                     //ͨ������vector.size��С�����飬��ԭ����Ǩ�ƣ���delete��ԭ������Ŀռ�?
void Vector<type>::free2()                 //��ɶ�size��ռ�����?
{
    type* temp = new type(this->size);
    for (int i = 0; i < this->size; i++)
    {
        temp[i] = this->ptr[i];
    }
    delete[]this->ptr;
    this->ptr = temp;
    capacity=this->size;
}
template<typename type>                 //��ָ��λ��position����nԪ��
void Vector<type>::insert(int position, type n)
{
    if (this->size == this->capacity)
    {
        capacity *= 2;
        type* tempt = new type[this->capacity];
        for (int i = 0; i < this->size; i++)
        {
            tempt[i] = this->ptr[i];
        }
        delete[]this->ptr;
        this->ptr = tempt;
    }
    for (int i = this->size; i > position; i--)
    {
        this->ptr[i] = this->ptr[i - 1];
    }
    this->ptr[position] = n;
    this->size++;
}
template<typename type>                     //��positionλ�ò���m��nԪ��
void Vector<type>::insert(int position, type n, int m)
{
    if ((this->size + m) >= this->capacity)
    {
        do
        {
            capacity *= 2;
        } while ((this->size + m) >= this->capacity);
        type* tempt = new type[this->capacity];
        for (int i = 0; i < this->size; i++)
        {
            tempt[i] = this->ptr[i];
        }
        delete[]this->ptr;
        this->ptr= tempt;
    }
    for (int i = this->size + m - 1; i >= position + m; i--)
    {
        this->ptr[i] = this->ptr[i - m];
    }
    for (int i = position; i < position + m; i++)
        this->ptr[i] = n;
    this->size += m;

}
template<typename type>             //ɾȥn�±�����Ԫ��
void Vector<type>::Delete(int n)
{
    this->size--;
    for (int i = n; i < this->size; i++)
    {
        this->ptr[i] = this->ptr[i + 1];
    }

    //this->ptr[size] = 0;

    //this->p[size] = 0;

}
template<typename type>                 //ɾȥnС�괦�����n��Ԫ��
void Vector<type>::Delete(int n, int m)
{//[n,m]����
    for (int i = 0; i < this->size - m - 1; i++)
        this->ptr[n + i] = this->ptr[m + i + 1];

    for (int i = this->size - 1; i >= this->size - 1 - m + n; i--)
    {
        this->ptr[i] = 0;
    }
    this->size -= m - n + 1;

}
template<typename type>            //ʵ������vector�����ݻ���
void Vector<type>::swap(Vector<type>& vec)
{
    type* t = this->ptr;
    this->ptr = vec.ptr;
    vec.ptr = t;
    int tt;
    tt = this->size;
    this->size = vec.size;
    vec.size = tt;
    tt = this->capacity;
    this->capacity = vec.capacity;
    vec.capacity = tt;
}

template<typename type>
void Vector<type>::Input(istream & in){
    type tempt;
    in>>tempt;
    for(int i=0;i<this->capacity;i++){
        this->push(tempt);
        if(in.peek()=='\n')
            {
                in.get();
                break;
            }
        in>>tempt;
    }
}
template<typename type>
void Vector<type>::Output(ostream& out)const{
    for(int i=0;i<this->size;i++){
        out<<this->ptr[i];
        cout<<' ';
    }
}


