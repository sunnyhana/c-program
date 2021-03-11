#include <iostream>
using namespace std;

template <class T>
class Base
{
public:
    T m_A;
};

//! child 继承于Base 必须告诉base 中T的类型，否则无法分配类型
class Child : public Base<int>
{
};

//!  Child1也是模板类！
template <class T1, class T2>
class Child1 : public Base<T2>
{

public:
    T1 m_B;
    Child1()
    {
        cout << typeid(T1).name() << endl;
        cout << typeid(T2).name() << endl;
    }
};

void test1()
{
    Child1<int, double> child; //? 由用户来制定类型
}

int main()
{
    test1();
    return 0;
}