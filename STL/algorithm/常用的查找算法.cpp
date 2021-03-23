#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

/*
!   find 算法 查找算法

?   参数1       容器开始迭代器
?   参数2       容器结束迭代器
?   参数3       查找的元素
?   return      返回查找元素的位置
*/

void test1()
{
    vector<int> v; //?   源容器
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    cout << *(find(v.begin(), v.end(), 2)) << endl; //?   返回迭代器
}

//?   利用find 查找自定义的数据类型
class Person
{
public:
    string m_name;
    int m_age;

    Person(string name, int age)
    {
        this->m_age = age;
        this->m_name = name;
    }

    bool operator==(const Person &p)
    {
        if (this->m_age == p.m_age && this->m_name == p.m_name)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
void test2()
{
    vector<Person> v;
    Person p1("aaa", 12);
    Person p2("bbb", 12);
    Person p3("ccc", 12);
    Person p4("ddd", 12);
    Person p5("eee", 12);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    cout << (*find(v.begin(), v.end(), p2)).m_name << endl;
}

//?   利用find 查找自定义的指针数据类型

class MyCompare : public binary_function<Person *, Person *, bool>
{
public:
    bool operator()(Person *p1, Person *p2) const
    {
        if (p1->m_age == p2->m_age && p1->m_name == p2->m_name)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

void test3()
{
    vector<Person *> v;
    Person p1("aaa", 12);
    Person p2("bbb", 13);
    Person p3("ccc", 14);
    Person p4("ddd", 15);
    Person p5("eee", 16);
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

    Person *p = new Person("bbb", 13);
    //cout << (*find(v.begin(), v.end(), p2)).m_name << endl;      ////    find是可以进行指针和指针之间的对比
    //! 利用适配器
    vector<Person *>::iterator pos = find_if(v.begin(), v.end(), bind2nd(MyCompare(), p));
    if (pos != v.end())
    {
        cout << (*pos)->m_name << "  " << (*pos)->m_age << endl;
    }
    else
    {
        cout << "未找到改值！！！" << endl;
    }
}

/*
?    adjacent_find  查找相邻的重复元素
?   参数1       容器开始迭代器
?   参数2       容器结束迭代器
?   回调函数     或者谓词 （返回值为bool型的函数对象）       
?   return      返回相邻元素的第一个位置的迭代器。
*/

void test4()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(3);
    v.push_back(3);
    v.push_back(1);
    v.push_back(3);
    vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
    if (pos != v.end())
    {
        cout << "找到了重复元素: " << *pos << endl;
    }
    else
    {
        cout << "未找到重复元素" << endl;
    }
}

/*
?    binary_search 二分查找法    注意：在无序序列中不可以使用
?   参数1       容器开始迭代器
?   参数2       容器结束迭代器
?   参数3       要查找的元素       
?   return     true或者false
*/
void test5()
{
    vector<int> v;
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    v.push_back(10);
    v.push_back(11);
    int num = 0;
    cin >> num;
    bool t = binary_search(v.begin(), v.end(), num);
    if (t)
    {
        cout << "序列中有：" << num << endl;
    }
    else
    {
        cout << "未找到！！！" << endl;
    }
}

/*
?    count_if   统计元素出现的次数       仅使用count是不用加回调函数的
?   参数1       容器开始迭代器
?   参数2       容器结束迭代器
?   参数3       回调函数或者谓词（返回值bool型的函数对象）       
?   return     返回元素个数
*/
class my_compare : public binary_function<int, int, bool>
{
public:
    bool operator()(int v1, int v2) const
    {
        if (v1 == v2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
class my_compare01
{
public:
    bool operator()(int v)
    {
        if (v > 4)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

void test6()
{
    vector<int> v;
    v.push_back(4);
    v.push_back(4);
    v.push_back(8);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    v.push_back(8);
    v.push_back(11);
    int num = 0;
    cin >> num;
    cout << count_if(v.begin(), v.end(), bind2nd(my_compare(), num)) << endl;
    cout << count_if(v.begin(), v.end(), my_compare01()) << endl;
    ;
}

int main()
{
    //test1();
    //test2();
    //test3();
    //test4();
    //test5();
    test6();
    return 0;
}