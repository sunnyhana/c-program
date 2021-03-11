#include <iostream>
using namespace std;

int mydevide(int a, int b)
{
    if (b == 0)
    {
        return -1;
    }
    return a / b;
}

void test1()
{
    int a = 10, b = 0;

    int ret = mydevide(a, b);
}

int main()
{
    test1();
    return 0;
}