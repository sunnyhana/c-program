//#pragma once
#include <iostream>
using namespace std;

class MaArry
{
public:
    MaArry(); //*  默认构造
    MaArry(int capacity);
    MaArry(const MaArry &array); //*       拷贝构造
    ~MaArry();
    void push_Back(int val);           //*           尾插法
    int get_Date(int index);           //*           索引获取值
    void ste_Date(int index, int val); //*  索引设置值

private:
    int *pAddress;  //* 指向真正存储数据的指针
    int m_Size;     //* 数组的大小
    int m_Capacity; //* 数组的容量
};
