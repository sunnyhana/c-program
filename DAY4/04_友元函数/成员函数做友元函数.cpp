#include <iostream>
#include <string>
using namespace std;

class goodGay;
class Building;

class goodGay
{
public:
    goodGay(); //?构造函数声明
    void visit();
    void visit1();

private:
    Building *building;
};

class Building
{
    friend void goodGay::visit1();

public:
    Building(); //?构造函数声明

public:
    string m_SittingRoom;

private:
    string m_BedRoom;
};

//!goodGay 类构造函数定义
goodGay::goodGay()
{
    building = new Building; //? 1、goodGay 默认构造中创建Building 对象
}

//! visit无法访问building 中私有属性！
void goodGay::visit()
{
    cout << "好基友正在进入 " << this->building->m_SittingRoom << endl; //? 3、gg的this指针指向building对象，从而获取属性
    //cout << "好基友正在进入 " << this->building->m_BedRoom << endl;
}

//! 只让visit1做友元函数，可访问Building私有属性；
void goodGay::visit1()
{
    cout << "好基友1正在进入 " << this->building->m_SittingRoom << endl; //? 3、gg的this指针指向building对象，从而获取属性
    cout << "好基友1正在进入 " << this->building->m_BedRoom << endl;
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
    gg.visit1();
}

int main()
{
    test1();
    return 0;
}