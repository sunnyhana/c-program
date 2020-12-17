#include <iostream>
using namespace std;



class Person 
{
    public :  
        int m_A;
        static int m_Age;    //静态成员变量，会共享数据
        //在类内声明，类外进行初始化
        //静态成员变量也是有权限的

        //静态成员函数
        
        static void func()
        {
            //m_A = 10;                //不可以访问普通成员变量
            m_Age = 0;
            cout << "func调用" << endl ;
        }
        //普通成员函数既可以访问普通成员变量，也可以访问静态成员变量
        void myFunc()
        {
            m_A = 10;    //普通成员变量
            m_Age = 1;   //静态成员变量
        }

    private :  
        static int m_other;


};
int Person::m_other = 100;  // 类外可以通过类名初始化私有属性
int Person:: m_Age = 0;    //类外初始化——>  类型名 类名::静态变量名 = 数据 ；

void test1()
{
    Person p1;
    p1.m_Age = 10;
     
    Person p2;
    p2.m_Age = 20;

    cout << "p1= " << p1.m_Age << endl;
    cout << "p2= " << p2.m_Age << endl;


    //静态成员函数调用
    p1.func();
    p2.func();
    Person::func();

    cout << "通过类名访问Age:" << Person::m_Age << endl;  //通过类名访问属性
    //cout << "通过类名访问other:" << Person::m_other<< endl;   //私有权限在类外无法访问的

    
}

int main()
{
    test1();
    return 0;
}