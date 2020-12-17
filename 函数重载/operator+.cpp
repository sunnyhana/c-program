#include <iostream>
using namespace std;

class Person
{
    friend Person operator+(Person &p1, Person &p2); //!  全局函数做友元，获取属性
private:
    int m_a;
    int m_b;

public:
    Person(){};
    Person(int a, int b) : m_a(a), m_b(b) {}
    /*
    Person operator+(Person &p)
    {
        Person temp;
        temp.m_a = this->m_a + p.m_a;
        temp.m_b = this->m_b + p.m_b;
        return temp;
    }
    */
    int get_m_a()
    {
        return m_a;
    }
    int get_m_b()
    {
        return m_b;
    }
};

Person operator+(Person &p1, Person &p2)
{
    Person temp;
    temp.m_a = p1.m_a + p2.m_a;
    temp.m_b = p1.m_b + p2.m_b;
    return temp;
}

void test1()
{
    Person p1(1, 2);
    Person p2(3, 4);
    Person p3(5, 6);
    Person p, q;
    p = p1 + p2;
    cout << "成员函数重载+" << endl;
    cout << p.get_m_a() << endl;
    cout << p.get_m_b() << endl;

    q = operator+(p2, p3);
    cout << "全局函数重载+" << endl;
    cout << q.get_m_a() << endl;
    cout << q.get_m_b() << endl;
}

int main()
{
    test1();
    return 0;
}