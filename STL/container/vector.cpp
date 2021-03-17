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

int main()
{
    //test1();
    test2();
    return 0;
}