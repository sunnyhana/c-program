#include <iostream>
#include <string>
using namespace std;

//!友元函数类外实现
template <class T1, class T2>
class Person; //? 声明Person 类，让编译器提前看到
template <class T1, class T2>
void printPerson(Person<T1, T2> &p); //?类外声明友元函数 让编译器提前看到

template <class T1, class T2>
class Person
{
    //!友元函数类内实现

    friend void printPerson<>(Person<T1, T2> &p); //? 核心
    //?   没有<>则是普通函数声明！不可为类外友元函数声明  ，<>用空参数列表告诉编译器这是模板函数的声明
    /*{
        cout << "姓名：" << p.m_name << "  年龄：" << p.m_age << endl;
    }
    */

public:
    Person(T1 name, T2 age)
    {
        this->m_name = name;
        this->m_age = age;
    }

    //private:
    T1 m_name;
    T2 m_age;
};

//类外实现
template <class T1, class T2>
void printPerson(Person<T1, T2> &p)
{
    cout << "姓名：" << p.m_name << "  年龄：" << p.m_age << endl;
}

void test1()
{
    Person<string, int> p("张三", 18);
    printPerson(p);
}

int main()
{
    test1();
    return 0;
}