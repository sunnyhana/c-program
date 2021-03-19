#include <iostream>
#include <queue>
using namespace std;

void test1()
{
    queue<int> q;
    q.push(10);
    q.push(40);
    q.push(30);
    q.push(20);
    queue<int> q1 = q;

    while (q.size() != 0)
    {
        /* code */
        cout << "对头元素为： " << q.front() << "   队尾元素为： " << q.back() << endl;
        q.pop();
        cout << "size = " << q.size() << endl;
    }
}

int main()
{
    test1();
    return 0;
}