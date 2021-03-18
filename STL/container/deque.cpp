#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void printDeque(deque<int> &d)
{
    for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << "  ";
    }
    cout << endl;
}

//todo    排序规则

bool myCompare(int v1, int v2)
{
    return v1 > v2;
}

void test1()
{
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_back(40);

    printDeque(d);

    deque<int> d1(d.begin(), d.end());
    d1.push_back(1000);

    printDeque(d1);

    d.swap(d1);
    cout << "交换后：" << endl;
    printDeque(d);
    printDeque(d1);

    if (d1.empty())
    {
        cout << "d1为空" << endl;
    }
    else
    {
        cout << "d1不为空！大小为： " << d1.size() << endl;
    }
    d.insert(d.begin() + 2, 55);
    cout << "插入后：" << endl;
    printDeque(d);

    sort(d.begin(), d.end());
    cout << "sort从小到大排序后：" << endl;
    printDeque(d);

    sort(d.begin(), d.end(), myCompare); //?
    cout << "sort从大到小排序后：" << endl;
    printDeque(d);
}

int main()
{
    test1();
    return 0;
}