#include <iostream>
using namespace std;

int mydevide(int a, int b)
{
    if (b == 0)
    {
        //eturn -1;
        //throw -1;    //!抛出整型异常
        throw 1.34; //!  抛出double异常，异常必须处理，
    }
    return a / b;
}

void test1()
{
    int a = 10, b = 0;

    //int ret = mydevide(a, b);   //?早期返回-1，无法判断是结果还是异常
    try
    {
        int ret = mydevide(a, b); /* code */
    }
    catch (int) //?    捕获异常
    {
        cout << "捕获int类型异常" << endl;
    }
    catch (double)
    {
        cout << "捕获double型异常" << endl;
    }
}

int main()
{
    test1();
    return 0;
}