#include <iostream>
using namespace std;

//分类：
//按照参数分类：无参构造函数（默认构造函数）、有参构造函数
//按照类型分类：普通构造函数、拷贝构造函数
class Person
{

public:
    int pAge;

    Person()
    {
        cout << "默认构造函数调用" << endl;
    }

    Person(int a)
    {
        cout << "有参构造函数调用" << endl;
    }

    Person(const Person &p) //拷贝构造函数
    {
        pAge = p.pAge;
        cout << "拷贝构造函数调用" << endl;
    }

    ~Person()
    {
        cout << "析构函数调用" << endl;
    }
};

void test()
{

    //构造函数调用：
    //括号法：
    //Person p1(1);    //有参
    // p1.pAge =10;
    // Person p2(p1);   //拷贝
    //cout << "P2的年龄：" << p2.pAge << endl;

    //Person p3;    //默认构造函数不用加括号
    //Person p3();   //编译器认为这行是函数的声明

    //显示法：
    //Person p4 = Person(100);    //有参
    //Person p5 = Person(p4);     //拷贝
    //Person(100);                //匿名对象，特点：若编译器发现了对象是匿名的，则在这行代码后就注释掉这个对象
    //不可以用拷贝构造函数初始化匿名对象，
    //Person p6 = Person(p5);     //如果写成左值，编译器认为是 Person p5,对象的声明。如果写成右值，则可以

    Person p7 = 100; //相当于调用了Person p7 = Person(100);
    Person p8 = p7;  //相当于：Person p8 = Person(p7);
}
int main()
{
    test();
    return 0;
}