//?   list是双向链表    <-:prev   ->:next
//?   begin->h   ，end->null     front()第一个元素     back()最后一个元素
//?   list迭代器不支持随机访问
//?   所有系统不支持随机访问的迭代器，不可以用系统的提供的算法
//todo    如果不支持系统提供的算法，那么这个类内会提供

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

void PrintList(list<int> l)
{
    for (list<int>::iterator it = l.begin(); it != l.end(); it++)
    {
        cout << *it << "  ";
    }
    cout << endl;
}

//todo   sort(MyCompare);中回调函数
bool MyCompare(int v1, int v2)
{
    return v1 > v2;
}

void test1()
{
    list<int> L(10, 10);
    list<int> L2(L.begin(), L.end());

    //?   头插，尾插
    L.push_back(1);
    L.push_back(4);
    L.push_back(3);
    L.push_back(2);
    L2.push_front(100);
    L2.push_front(300);
    L2.push_front(400);
    L2.push_front(200);

    PrintList(L);
    PrintList(L2);

    //?  头删，尾删

    L.pop_back();
    L.pop_back();
    L2.pop_front();
    L2.pop_front();
    cout << "尾删法、头删：" << endl;
    PrintList(L);
    PrintList(L2);

    //?  中间插入
    L.insert(L.begin(), 69);
    L2.insert(L2.end(), 33);
    cout << "insert:" << endl;

    PrintList(L);
    PrintList(L2);

    //?  逆序打印
    cout << "L逆序后：" << endl;
    for (list<int>::reverse_iterator it = L.rbegin(); it != L.rend(); it++)
    {
        cout << *it << "  ";
    }
    cout << endl;

    //? 删除特定值
    L.remove(10); //!   会删除所有符合的值
    cout << "删除特定值后：" << endl;
    PrintList(L);
}

void test2()
{
    list<int> L(10, 10);
    list<int> L2(L.begin(), L.end());

    //?   头插，尾插
    L.push_back(1);
    L.push_back(4);
    L.push_back(3);
    L.push_back(2);
    L2.push_front(100);
    L2.push_front(300);
    L2.push_front(400);
    L2.push_front(200);
    cout << "size:" << L.size() << endl;
    //! 从头开始重新分配空间。
    L.resize(10);
    L2.resize(10);
    PrintList(L);
    PrintList(L2);
    cout << "L2::front: " << L2.front() << "  L2::back: " << L2.back() << endl;
    L.clear();
    PrintList(L);
    for (int i = 0; i < 10; i++)
    {
        L.push_back(i * 10 + i);
    }
    PrintList(L);

    L.reverse(); //!翻转————-改变存储顺序
    PrintList(L);
    cout << "L2排序后: " << endl;
    L2.sort(MyCompare); //*  从大到小。

    PrintList(L2);
}

int main()
{
    //test1();
    test2();
    return 0;
}