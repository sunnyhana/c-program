#include <iostream>
using namespace std;

class mylars
{
public:
    int m_a;
    /*mylars()
        {
            cout << "默认构造函数" << endl;
        }*/
    mylars(int a)
    {
        cout << "有参构造函数" << endl;
    }
    //1、当我提供有参构造函数，系统就不会提供默认构造函数。但是，系统还是提供默认拷贝构造函数
};
//2、当我们提供拷贝构造，系统就不会提供其他构造了

class mylars2
{
public:
    int m_a;

    /*mylars()
        {
            cout << "默认构造函数" << endl;
        }*/
    /*mylars2(int a)
        {
            cout << "有参构造函数" << endl;
        }   */
    mylars2(const mylars2 &c)
    {
    }
};

void test1()
{
    mylars c1(1);
    c1.m_a = 10;
    mylars c2(c1);
    cout << c2.m_a << endl;
}

int main()
{
    test1();
    return 0;
}