#include <iostream>
using namespace std;

class Person
{

    friend ostream &operator<<(ostream &out, Person &p);
    friend Person &operator++(Person &p);

private:
    int m_a;
    int m_b;

public:
    Person()
    {
        m_a = 0;
        m_b = 0;
    }
    Person(int a, int b) : m_a(a), m_b(b) {}
    ~Person() {}

    Person &operator++(int) //!  后缀自增重载, int 为后缀标记
    {
        Person t = *this;
        Person *temp = &t;

        (this->m_a)++;
        (this->m_b)++;
        //?  返回person会在后面赋值的的时候报错,排除法可知道赋值运算符重载没有问题
        return *temp;
    }

    Person operator+(Person &p) //!   +重载
    {
        Person temp;
        temp.m_a = this->m_a + p.m_a;
        temp.m_b = this->m_b + p.m_b;
        return temp;
    }

    void disp()
    {
        cout << "m_a = " << m_a << endl;
        cout << "m_b = " << m_b << endl;
    }
    void operator=(Person &p) //! 重载赋值运算符
    {
        this->m_a = p.m_a;
        this->m_b = p.m_b;
    }
};

ostream &operator<<(ostream &out, Person &p) //!   <<运算符重载只能做全局函数，因为第一参数为out,
{
    cout << "m_a = " << p.m_a << "  m_b = " << p.m_b << endl;
    return out;
}

Person &operator++(Person &p) //! 自增运算符重载
{

    ++p.m_a;
    ++p.m_b;
    return p;
}

void test1()
{
    Person p;
    Person p1(1, 2);
    Person p2(10, 20);
    p = p1++;
    cout << p;
    cout << p1;
}

int main()
{
    test1();
    return 0;
}