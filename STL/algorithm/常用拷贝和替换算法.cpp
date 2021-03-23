#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

/*
!   replace     江南容器内指定范围内的旧元素修改为新元素
?   参数1       容器1开始迭代器
?   参数2       容器1结束迭代器
?   参数3       旧元素
?   参数4       新元素
*/
void test1()
{
    std::vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), [](int val) { std::cout << val << "  "; });
    std::cout << std::endl;
    std::replace(v.begin(), v.end(), 8, 10);
    std::cout << "replace: " << std::endl;
    for_each(v.begin(), v.end(), [](int val) { std::cout << val << "  "; });
}

/*
!   replace_if     将容器内指定范围内满足条件的的旧元素修改为新元素
?   参数1       容器1开始迭代器
?   参数2       容器1结束迭代器
?   参数3       回调函数或者谓词
?   参数4       新元素
*/
class my_replace : public std::binary_function<int, int, bool>
{
public:
    bool operator()(int v1, int v2) const
    {
        if (v1 <= v2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
void test2()
{
    std::vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), [](int val) { std::cout << val << "  "; });
    std::cout << std::endl;

    int num; //?  replace_if of value
    std::cin >> num;

    std::replace_if(v.begin(), v.end(), std::bind2nd(my_replace(), num), 10);
    std::cout << "replace: " << std::endl;
    for_each(v.begin(), v.end(), [](int val) { std::cout << val << "  "; });
}
/*
!   copy       将容器内指定范围的元素拷贝到另一个容器中
?   参数1       容器1开始迭代器
?   参数2       容器1结束迭代器
?   参数3       目标容器开始迭代器    
*/

/*
!   swap        互换两个容器的元素
?   参数1       容器1开始迭代器
?   参数2       容器1结束迭代器   

*/

int main()
{
    //test1();
    //test2();
    return 0;
}
