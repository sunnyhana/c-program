#include <iostream>
using namespace std;

class Person
{
public:
    Person()
    {
        cout << "默认构造函数" << endl;
    }
    Person(int a)
    {
        cout << "有参构造函数" << endl;
    }
    ~Person()
    {
        cout << "析构函数" << endl;
    }
};

void test1()
{
    Person p1;               //栈区开辟空间，会是会释放对象，堆区则不会
    Person *p2 = new Person; //堆区开辟，
    //所有new出的对象都会返回该类型的指针
    //malloc 返回void * 还需要强转后再赋值
    //malloc不会调用构造， new会调用构造
    //new为运算法，malloc为函数

    delete p2; //释放堆区的对象
    //delete也是运算符，配合new使用；malloc配合free用
}

void test2()
{
    //void * p = new Person;   //用void*接收new出的的指针会出现释放的问题,无法释放
    //delete p;
}

void test3()
{
    //通过new开辟数据，一定会调用默认构造函数，所以一定要提供默认构造
    //
    Person *pArray = new Person[4]; //堆区开辟
    //Person pArray2[2] = {Person(1),Person(2)};     //在栈上开辟数据，可以制定有参构造

    delete[] pArray;
    //释放数据数据，必须要 delete[]
}

int main()
{

    // test1();
    //test2();
    test3();
    return 0;
}