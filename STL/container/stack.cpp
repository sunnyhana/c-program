//todo     栈容器

#include <iostream>
#include <stack>
using namespace std;

void test1()
{
    stack<int> st;
    //?放数据   push
    st.push(10);
    st.push(30);
    st.push(20);
    st.push(40);
    stack<int> st1 = st;
    while (st.size() != 0)
    {
        cout << "栈顶元素为： " << st.top() << endl;
        st.pop();
    }
    cout << "size = " << st.size() << endl;

    while (st1.size() != 1)
    {
        cout << "栈顶元素为： " << st1.top() << endl;
        st1.pop();
    }
    cout << "size = " << st1.size() << endl;
}

int main()
{
    test1();
    return 0;
}