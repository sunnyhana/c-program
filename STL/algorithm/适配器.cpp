#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class MyPrint : public binary_function<int, int, void> //!     注意：<>
{
public:
    void operator()(int val, int start) const
    {
        cout << start + val << endl;
    }
};

//todo     第一步绑定数据，bin2nd
//todo     继承类  binary_function<参数类型1，参数类型2，返回值类型>
//todo     加const修饰

void test1()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    cout << "请输入起始值：" << endl;
    int num = 0;
    cin >> num;
    for_each(v.begin(), v.end(), bind2nd(MyPrint(), num));
    cout << endl;
}

//?   取反适配器
class GreaterThenFive : public unary_function<int, bool> //!   一元适配器继承的类
{
public:
    bool operator()(int v) const
    {
        return v > 5;
    }
};

void test2()
{
    //?  一元取反
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    cout << *find_if(v.begin(), v.end(), not1(GreaterThenFive())) << endl;
}

int main()
{
    //test1();
    test2();
    return 0;
}