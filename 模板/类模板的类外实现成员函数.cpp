#include <iostream>
#include <string>
using namespace std;

template <class T1, class T2>
class Person
{
public:
    T1 m_Name;
    T2 m_Age;

    Person(T1 name, T2 age);
    /*{
        this->m_Name = name;
        this->m_Age = age;
    }*/

    void showPerson();
    /*{
        cout<< "姓名:" << this->m_Name << endl;
        cout<< "年龄:" << this->m_Age << endl;
    }*/
};

template <class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
    this->m_Name = name;
    this->m_Age = age;
}
template <class T1, class T2>
void Person<T1, T2>::showPerson()
{
    cout << "姓名:" << this->m_Name << endl;
    cout << "年龄:" << this->m_Age << endl;
}

void test1()
{
    Person<string, int> p1("sun", 18);
    p1.showPerson();
}

int main()
{
    test1();
    return 0;
}