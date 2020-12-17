#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;

struct Person   //c++中可以将属性和行为一起封装
{
    /* data */
    char mName[64];
    int mAge;

    void PersonEat()
    {
        cout<< mName << "吃人饭" << endl;

    }
};

struct Dog
{
    /* data */
    char dName[64];
    int dAge;
    
    void DogEat()
    {
        cout<< dName<< "吃狗粮"<< endl;
    }
};

void test01()
{
    Person p1;
    strcpy(p1.mName,"老王");
    p1.PersonEat();
    //p1.DogEat();
}
//c++中的封装严格类型转换检测，让属性和行为绑定到一起
//属性和行为作为一个整体来表示生活中的事物
//控制权限：公有权限public  保护权限protected   私有权限private

//struct和class 是一个意思，唯一的不同的：默认权限。struct是public，但是class默认权限private
class Animal    
{
    //默认权限为：private
private:
    int mAge = 0;   //年龄  只读
    string mName;   //公有权限 读写
    string mLove;   //情人


public:
    int mHeight;

   /* void setAge(int age)     //通过public方法设置private属性
    {
        mAge = age;
    } */

    int getAge()           //获取年龄  读权限
    {
        return mAge;
    }

//读姓名
    string getName()
    {
        return mName;
    }

//写姓名
    void setName(string name)
    {
        mName = name ;
    }

//只写情人
    void setLove(string lover)
    {
        mLove = lover;
    }

protected:         //保护权限：类内部可以访问，当前类的子类可以访问，类外不可以访问
    int mWeight;

void sctWeight(){mWeight = 160;}


};


//
void test02()
{
    Animal an;
    //an.mAge=18;         私有权限类外不可访问

    //an.mWeight = 150;   保护权限在类外也不可以访问

    an.mHeight = 170;
}

void test03()
{
    Animal person ;
    person.setName("老王");
    cout << "一号人类的名字： " << person.getName() << endl;

//年龄
    cout << "年龄： " << person.getAge() <<endl;

//情人
    person.setLove ("东施");
}

int main()
{
    //test01();
    test03();
    return 0;
}