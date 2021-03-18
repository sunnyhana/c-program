#include <iostream>
#include <vector>

using namespace std;

void test1()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
        cout << v.capacity() << endl; //?         查看容器大小。
    }
}
void printVector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << "   ";
    }
    cout << endl;
}
void test2()
{
    vector<int> v;
    int arr[] = {2, 3, 4, 5};
    vector<int> v1(arr, arr + sizeof(arr) / sizeof(int)); //将v[begin(),end()]区间中的元素拷贝给本身
    vector<int> v2(v1.begin(), v1.end());

    vector<int> v3(10, 100); //?   vector<int> v3(n, elem);  构造函数将n个elem拷贝给本身

    vector<int> v4(v3); //?   vector(const vector &vec);   拷贝构造

    v = v4; //?     vector& operator=(const vector &vec);

    v3.swap(v2); //?   将vec与本身元素互换；

    //!  测试V1、V2
    cout << "v的内容：";
    printVector(v);
    cout << "v1的内容：";
    printVector(v1);
    cout << "v2的内容：";
    printVector(v2);
    cout << "v3的内容：";
    printVector(v3);
    cout << "v4的内容：";
    printVector(v4);
}
void test3()
{
    vector<int> v;
    for (int i = 0; i < 10000; i++)
    {
        v.push_back(i);
    }
    cout << "容量：" << v.capacity() << endl;
    cout << "大小" << v.size() << endl;
    v.resize(3);

    cout << "容量： " << v.capacity() << endl;
    cout << "大小: " << v.size() << endl;

    //?   巧用swap
    vector<int>(v).swap(v); //todo     vector<int>(v)利用v初始化匿名对象
    cout << "容量：" << v.capacity() << endl;
    cout << "大小" << v.size() << endl;
}

void test4()
{
    //todo      front();返回容器中第一个元素
    //todo      back();返回容器中最后一个元素
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    cout << "v的front：" << v.front() << endl;
    cout << "v的back：" << v.back() << endl;

    v.insert(v.begin(), 100); //*   insert (const_iterator pos,int count ,ele) 在pos处插入count个ele;
    printVector(v);
    v.pop_back();
    printVector(v);
}
void test5()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    //todo   正序遍历
    printVector(v);

    //todo   逆序遍历，迭代器要使用   reverse_iterator
    for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
    {
        cout << *it << "  ";
    }

    cout << endl;
}

int main()
{
    //test1();
    //test2();
    //test3();
    //test4();
    test5();

    return 0;
}