#include <iostream>
#include <string>
using namespace std;

class Building
{
    /*
    ? 让全局好基友函数变成我的好朋友（友元函数）
    ! 友元函数目的：访问类中的私有成员属性
    */
    friend void goodGay(Building *building);

public:
    string m_SittingRoom;

public:
    Building()
    {
        this->m_SittingRoom = "客厅";
        this->m_BedRoom = "卧室";
    }

private:
    string m_BedRoom;
};

//* 全局函数   好基友
void goodGay(Building *building)
{
    cout << "好基友正在进入" << building->m_SittingRoom << endl;
    cout << "好基友正在进入" << building->m_BedRoom << endl;
}

void test1()
{
    Building *building = new Building;
    goodGay(building);
}
int main()
{
    test1();
    return 0;
}