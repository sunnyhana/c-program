#include <iostream>
using namespace std;

class Person
{
    public :

        int Age;

        Person()
        {
            cout << "默认构造函数" << endl;
        }

        Person(int a)
        {
            cout << "有参构造函数" << endl;
        }

        Person(const Person & p)
        {
            cout << "拷贝构造函数" << endl;
        }

        ~Person()
        {
            cout << "析构函数" << endl;
        }


};

//拷贝调用的时机：
//1：用已经创建好的对象来初始化新的对象；
void test1()      
{
    Person p1;
    p1.Age = 10;
    
    Person p2(p1);
}
//2：以值传递的方式给函数参数传值
void doWork (Person p1)    //Person p1 = Person(p)
{
        
}
void test2()
{
    Person p;
    p.Age = 100;
    doWork(p);
}

//3：以值方式返回局部对象
Person dowork2()
{
    Person p1;
    return p1;
}

void test3()
{
     Person p = dowork2();
}
//Release下编译器自动优化：
/*优化成下面情况：

    Person p ；   不调用默认结构
    dowork2(p);

    void dowork2(Person &p)
    {
        Person P1;   调用默认构造函数
    }
*/

int main()
{
    //test1();     //1：用已经创建好的对象来初始化新的对象；
    //test2();    //2：以值传递的方式给函数参数传值
    test3();     //3：以值方式返回局部对象
    return 0;

}