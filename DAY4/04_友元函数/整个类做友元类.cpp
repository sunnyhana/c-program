#include <iostream>
#include <string>
using namespace std;

class Building
{
    //! 让好基友类成为building的好朋友 （友元类）
    friend class goodGay; //?    友元类声明
public:
    Building(); //?构造函数声明

public:
    string m_SittingRoom;

private:
    string m_BedRoom;
};

class goodGay
{
public:
    goodGay(); //?构造函数声明
    void visit();

private:
    Building *building;
};

//!goodGay 类构造函数定义
goodGay::goodGay()
{
    building = new Building; //? 1、goodGay 默认构造中创建Building 对象
}

void goodGay::visit()
{
    cout << "好基友正在进入 " << this->building->m_SittingRoom << endl; //? 3、gg的this指针指向building对象，从而获取属性
    cout << "好基友正在进入 " << this->building->m_BedRoom << endl;
}

//* Building 构造函数定义
Building::Building() //? 2、Building 默认构造中为其成员属性赋值
{
    this->m_SittingRoom = "客厅";
    this->m_BedRoom = "卧室";
}

void test1()
{
    goodGay gg;
    gg.visit();
    /*
? 1、在创建gg对象时，goodGay 默认构造中创建Building 对象
? 2、Building 默认构造中为其成员属性赋值
? 3、gg的this指针指向building对象，从而获取属性

?总结： 在前一个类的构造中创建后一个类对象，并在后类中将前类声明为友元类（feriend class name）,从而使前一个类可以获取友元类的属性以及方法
*/
}

int main()
{
    test1();
    return 0;
}