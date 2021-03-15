#include <iostream>
#include <vector>    //!    容器
#include <algorithm> // !    算法
#include <string>
using namespace std;

//?   迭代器   遍历功能，普通的指针也算迭代器

void test1()
{
    int array[5] = {1, 2, 3, 4, 5};

    int *p = array;
    for (int i = 0; i < 5; i++)
    {
        //cout << array[i] << endl; //?   常用遍历方式
        cout << *(p++) << endl;
    }
}

void myIntPrint(int v) //?   回调函数
{
    cout << v << endl;
}

void test2()
{
    //?  声明容器
    vector<int> v; //?   声明一个容器这个容器里存放int型数据    对象名称V；

    //?   向容器中放入数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    //?   遍历容器中的数据
    //?   利用迭代器
    vector<int>::iterator itBegin = v.begin(); //!    itBegin指向 v容器中的起始位置
    vector<int>::iterator itEnd = v.end();     //!    itEnd 指向V容器中最后一个位置的下一个地址

    /*while (itBegin != itEnd)
    {

        cout << *(itBegin++) << endl;
    }
    */
    //?  第二种遍历方法
    /* for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }  */

    //?  第三种方法:利用算法
    for_each(v.begin(), v.end(), myIntPrint);
}

//!  操作自定义数据类型
class Person
{
public:
    Person(string name, int age)
    {
        this->m_age = age;
        this->m_name = name;
    }
    void printP()
    {
        cout << this->m_name << this->m_age << endl;
    }
    string m_name;
    int m_age;
};
void myPersonPrint(Person *p)
{
    (*p).printP();
}
void test3()
{
    vector<Person> z;
    Person p1("大头儿子", 18);
    Person p2("小头爸爸", 38);
    Person p3("围裙妈妈", 35);
    Person p4("隔壁老王", 28);

    z.push_back(p1);
    z.push_back(p2);
    z.push_back(p3);
    z.push_back(p4);
    vector<Person>::iterator itB = z.begin();
    vector<Person>::iterator inE = z.end();

    //for_each(z.begin(), z.end(), myPersonPrint);    //?运用算法遍历

    /* for (vector<Person>::iterator it = z.begin(); it != z.end(); it++)
    {
        cout << (*it).m_name << (*it).m_age << endl;
    }*/
}

//!    自定义数据类型指针
void test4()
{
    vector<Person *> z;
    Person p1("大头儿子", 18);
    Person p2("小头爸爸", 38);
    Person p3("围裙妈妈", 35);
    Person p4("隔壁老王", 28);

    z.push_back(&p1);
    z.push_back(&p2);
    z.push_back(&p3);
    z.push_back(&p4);
    for_each(z.begin(), z.end(), myPersonPrint);
}

//!容器嵌套容器

int main()
{
    test4();
    return 0;
}