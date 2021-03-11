#include <iostream>
using namespace std;

template <class T>
class MyArray
{
private:
    T *pAddress;    //指向堆区指针
    int m_Capacity; //容量
    int m_Size;

public:
    explicit MyArray(int capacity) //!    防止隐式类型转换   防止MyAddress arr = 10； 写法！
    {
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity];
    }
    MyArray(const MyArray &array)
    {
        this->m_Capacity = array.m_Capacity;
        this->m_Size = array.m_Size;
        this->pAddress = new T[this->m_Capacity];
        for (int i = 0; i < array.m_Size; i++)
        {
            this->pAddress[i] = array[i];
        }
    }
    ~MyArray()
    {
        if (this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
        }
    }

    //?赋值操作符重载

    MyArray &operator=(MyArray &array)
    {
        //? 先判断原始数据，有就清空。
        if (this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
        }

        this->m_Capacity = array.m_Capacity;
        this->m_Size = array.m_Size;
        this->pAddress = new T[this->m_Capacity];
        for (int i = 0; i < array.m_Size; i++)
        {
            this->pAddress[i] = array[i];
        }
    }

    //? []重载

    T &operator[](int index)
    {
        return this->pAddress[index];
    }

    //?  尾插法

    void push_Back(T val)
    {
        this->pAddress[this->m_Size] = val;
        this->m_Size++;
    }

    //?获取容量

    int get_Capacity()
    {
        return this->m_Capacity;
    }
};
