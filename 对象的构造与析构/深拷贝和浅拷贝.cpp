#include <iostream>
#include <cstring>
using namespace std;

class Person 
{
    public :  
        char * m_Name;
        int m_Age;

        Person(){}
        Person (const char* name,int age)
        {
            m_Name = (char*)malloc(strlen(name));
            strcpy(m_Name ,name);
            m_Age = age;
        }

        //拷贝构造，系统会提供默认拷贝构造，就是简单的值拷贝。即浅拷贝
        //自己提供拷贝构造，原因简单的浅拷贝会释放堆空间两次，导致崩溃

        Person(const Person & p)    //深拷贝
        {
            m_Age = p.m_Age;
            m_Name = (char*)malloc(strlen(p.m_Name)+1);    //拷贝地址
            strcpy(m_Name,p.m_Name);                       //拷贝值
 
        }


    ~Person ()
    {
        cout << "析构函数" << endl;
        if (m_Name != NULL)
        {
            free(m_Name);
            m_Name = NULL;
        }
    }


};

void test1()
{
    Person p1( "蔡文姬",10);
    Person p2 (p1);
    cout << "P2的名字： " << p2.m_Name <<endl;
    cout << "P2的年龄： " <<p2.m_Age <<endl;

}
int main()
{
    test1();
    return 0;

}