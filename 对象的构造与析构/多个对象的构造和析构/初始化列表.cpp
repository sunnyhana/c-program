#include <iostream>
using namespace std;
 
 class Person
 {
     public :  
        int m_A,m_B,m_C;

        Person(){}    //有参构造用于初始化数据；
       /* Person(int a,int b,int c )     
        {
            m_A = a;
            m_B = b;
            m_C = c;
        }*/
//利用初始化列表初始化数据：
//构造函数 + ： 属性（参数），属性（参数），属性（参数）
        Person(int a,int b , int c ) : m_A(a),m_B(b),m_C(c)
        {}

 };

 void test1()
 {
     Person p1(1,2,3);
     cout << p1.m_A+p1.m_B+p1.m_C <<endl ;
 }
 int main()
 {
     test1();
     return 0;
 }