#include <iostream>
#include "Myarray.hpp"
using namespace std;

void test1()
{
}

int main()
{
    MyArray<int> arr(10);
    for (int i = 0; i < 10; i++)
    {
        arr.push_Back(i + 10);
    }

    for (int i = 0; i < arr.get_Capacity(); i++)
    {
        cout << arr[i] << endl;
    }
    test1();
    return 0;
}