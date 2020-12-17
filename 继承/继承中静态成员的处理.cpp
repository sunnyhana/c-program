#include <iostream>
using namespace std;

class Base
{
public:
    static int m_a;

    static void func()
    {
        cout << "base func" << endl;
    }
    static void func(int)
    {
        cout << "base func(int)" << endl;
    }
};
int Base::m_a = 0;

class Son : public Base
{
public:
    static int m_a;
    static void func()
    {
        cout << "son func" << endl;
    }
};
int Son::m_a = 100;

void test1()
{
    cout << Son::m_a << endl; //*   静态成员属性可以被派生类继承,出现同名，则覆盖父类
    cout << Base::m_a << endl;
    Son::func();
}

int main()
{
    test1();
    return 0;
}