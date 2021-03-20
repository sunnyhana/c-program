#include <iostream>
#include <functional>
using namespace std;

void test1()
{
    //template<class T> T plus <T>           //加法仿函数
    plus<int> p;
    cout << "plus: " << p(10, 20) << endl;

    //template<class T> T negate<T>		  //取反仿函数
    negate<int> ne;
    cout << "negate: " << ne(99) << endl;

    //template<class T> bool logical_and<T>    //逻辑与
    logical_and<int> log;
    cout << "logical_and: " << log(1, 0) << endl;
}

int main()
{
    test1();
    return 0;
}