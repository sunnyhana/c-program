#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//
class MyPrint
{
public:
    void operator()(int val)
    {
        cout << val << "  ";
    }
};
void test1()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;
}

class MyPrint01
{
public:
    void operator()(int val)
    {
        cout << val << "  ";
        count++;
    }
    int count = 0;
};
//?  for_each 可以保存内部记录
void test2()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    MyPrint01 mp = for_each(v.begin(), v.end(), MyPrint01());
    cout << endl;
    cout << mp.count << endl;
}

//!   tranform   将指定容器区间元素搬运到另一容器里
//!   tranform   不会给目标容器分配内存 ，所以需要提前分配好内存
//参数1  源容器开始迭代器  ；参数2   源容器结束迭代器；    参数3  目标容器开始迭代器    参数4   回调函数或函数对象      return  返回目标容器迭代器
class TansForm
{
public:
    int operator()(int v)
    {
        return v + 10;
    }
};

void test3()
{
    vector<int> v; //?   源容器
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    vector<int> vTarget;
    vTarget.resize(10);                                         //!   分配内存
    transform(v.begin(), v.end(), vTarget.begin(), TansForm()); //!   必须有回调函数或者函数对象
    for_each(vTarget.begin(), vTarget.end(), [](int val) { cout << val << "  "; });
    cout << endl;
}

//!    tranform 第二种用法   将两个容器数据搬运到目标容器
class TansForm4
{
public:
    int operator()(int v1, int v2)
    {
        return v1 + v2;
    }
};
void test4()
{
    vector<int> v1, v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i * 10);
    }
    v2.push_back(100);
    vector<int> vTarget;
    vTarget.resize(20);
    transform(v1.begin(), v1.end(), v2.begin(), vTarget.begin(), TansForm4());
    for_each(vTarget.begin(), vTarget.end(), [](int val) { cout << val << "  "; });
    cout << endl;
}

int main()
{
    //test1();
    //test2();
    //test3();
    test4();
    return 0;
}