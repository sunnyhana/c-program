#include <iostream>
#include "MyArray.h"
//#include <MyArray.cpp>
using namespace std;

//*默认构造
MaArry::MaArry()
{
    this->m_Capacity = 100;
    this->m_Size = 0;

    //? 维护出一个capacity大小的数组
    this->pAddress = new int[this->m_Capacity];
    //!cout << "默认构造" << endl;
}

//*有参构造  提供数组容量
MaArry::MaArry(int capacity)
{
    this->m_Capacity = capacity;
    this->m_Size = 0;
    this->pAddress = new int[this->m_Capacity];
    //! cout << "有参构造" << endl;
}

//* 拷贝构造
MaArry::MaArry(const MaArry &array)
{
    this->pAddress = new int[array.m_Capacity]; //? 维护同样容量的数组
    this->m_Size = array.m_Size;                //?              拷贝大小
    this->m_Capacity = array.m_Capacity;        //?        拷贝容量

    //? 拷贝内容
    for (int i = 0; i < array.m_Size; i++)
    {
        this->pAddress[i] = array.pAddress[i];
    }
    cout << "拷贝构造" << endl;
}

//*析构
MaArry::~MaArry()
{
    if (this->pAddress != NULL)
    {
        delete[] this->pAddress;
        this->pAddress = NULL; //! 防止野指针
    }
    cout << "析构" << endl;
}

//!  尾插法
void MaArry::push_Back(int val)
{
    this->pAddress[this->m_Size] = val;
    this->m_Size++;
}

//!  获取值
int MaArry::get_Date(int index)
{
    return this->pAddress[index];
}

//!  设置值

void MaArry::ste_Date(int index, int val)
{
    this->pAddress[index] = val;
}

void in_date(MaArry *array, int test)
{

    for (int i = 0; i < 5; i++)
    {
        array[i] = test * 10 + i;
    }
}

void out_date(MaArry *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array->get_Date(i) << "  ";
    }
}

void test1()
{
    //?堆创建数组
    MaArry *array1 = new MaArry(10);

    // delete array1;
    MaArry *array2 = new MaArry(*array1);
    for (int i = 0; i < 10; i++)
    {
        array2->push_Back(i);
    }
    for (int i = 0; i < 10; i++)
    {
        array2->get_Date(i);
    }
}

int main()
{
    test1();

    return 0;
}
