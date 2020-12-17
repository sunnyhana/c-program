#include <iostream>
using namespace std;

class Person
{

public:
    Person()
    {

        //构造中修改属性
        //this永远指向本体
        //const Person *const this
        this->m_a = 0;
        this->m_b = 0;
    }
    void showInfo() const //!常函数，不允许修改指针
    {
        this->m_b = 100; //!加上mutable修饰后可以修改

        cout << "m_a = " << this->m_a << endl;

        cout << "m_b = " << this->m_b << endl;
    }
    int m_a;
    mutable int m_b; //就算是常函数，也可以修改加mutable修饰
};

void test1()
{
    Person p1;
    p1.showInfo();

    //! 常对象 不允许修改属性
    const Person p2; //* 常对象前面加 const
    //p2.m_a = 100;
    cout << p2.m_a << endl;
    //* 常对象不可写，但是可读，常对象不可以调用普通成员函数 ，只能调用常函数，
}

int main()
{

    test1();
    return 0;
}
