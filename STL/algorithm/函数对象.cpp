#include <iostream>
using namespace std;

class Myprint
{
public:
    int count = 0;

    void operator()(int num)
    {
        cout << "num:" << num << endl;
        count++;
    }
};

void test1()
{
    Myprint p;
    p(10);

    Myprint()(1000); ////匿名对象
}

//?   函数对象超出普通函数概念内部可以保存状态。
void test2()
{
    Myprint p;
    p(10);
    p(20);
    p(30);
    cout << "count:" << p.count << endl;
}

//?   函数对象做参数
void test3(Myprint p, int num)
{
    p(num);
}

int main()
{
    //test1();
    //test2();
    test3(Myprint(), 999);
    return 0;
}