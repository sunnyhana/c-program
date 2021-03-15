#include <iostream>
using namespace std;
class myException
{
public:
    void printError()
    {
        cout << "自定义异常" << endl;
    }
};

int mydevide(int a, int b)
{
    if (b == 0)
    {
        //eturn -1;
        //throw -1;    //!抛出整型异常
        //throw 1.34; //!  抛出double异常，异常必须处理，
        //throw 'a';
        throw myException(); //!  匿名对象
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
        throw; //? 如果不想处理异常可以继续向上抛出
        cout << "捕获double型异常" << endl;
    }

    catch (myException e)
    {
        e.printError();
    }

    catch (...)
    {
        cout << "其他类型异常捕获" << endl;
    }
}

int main()
{
    try
    {
        test1();
    }
    catch (double) //!   如果异常都没有处理，那么编译器会调出terminate函数,使程序中断。
    {
        cout << "main 捕获double型异常" << endl;
    }
    return 0;
}