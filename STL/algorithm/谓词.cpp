#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class GreaterThen20
{
public:
    bool operator()(int val)
    {
        return val > 20;
    }
};

//?  改变sort顺序
class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

void PrintVector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << "  ";
    }
    cout << endl;
}

//?   一元谓词
void test1()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(50);
    v.push_back(40);
    v.push_back(30);

    //?  查找第一个大于20的数字    find_if()返回的是迭代器
    vector<int>::iterator pos = find_if(v.begin(), v.end(), GreaterThen20()); //!仿函数匿名调用。
    if (pos != v.end())
    {
        cout << "找到大于的第一个数字为： " << *pos << endl;
    }
    else
    {
        cout << "找不到大于20的数字" << endl;
    }
}

//?  二元谓词

void test2()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(50);
    v.push_back(40);
    v.push_back(30);

    sort(v.begin(), v.end(), MyCompare());
    PrintVector(v);
    sort(v.begin(), v.end());
    cout << "从小到大排序：" << endl;

    //todo   匿名函数   lamada表达式   [](){}
    for_each(v.begin(), v.end(), [](int val) { cout << val << "  "; });
    cout << endl;
}

int main()
{
    //test1();
    test2();
    return 0;
}