
#include <iostream>
#include <string>
using namespace std;

void test1()
{
    string str;       //?     默认构造
    string str2(str); //?   拷贝构造；
    string str3 = str;

    string str4 = "hana";
    string str5(10, 'a');
    cout << str4 << endl;
    cout << str5 << endl;

    //!  基本赋值
    str = "hello"; //?      string& operator=(const char* s)
    str2 = str4;   //?      string& operator=(const string &s)

    str3.assign("abcde", 4); //?  string& assgin(const char*s,int n);   将s串中前N个字符赋给当前字符串
    cout << str3 << endl;

    //?    string& assgin (const string &s,int start,int n);    将s串从start开始n个字符赋给当前串
    str.assign(str4, 2, 2);
    cout << str << endl;
}

void test2()
{
}

int main()
{
    test1();
    return 0;
}