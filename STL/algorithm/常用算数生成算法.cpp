#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

/*
!   accumulate  计算容器中累计总和
?   参数1       容器1开始迭代器
?   参数2       容器1结束迭代器
?   参数3       累加值    
?   
*/
void test1()
{
    std::vector<int> v; //?   源容器
    for (int i = 0; i <= 10; i++)
    {
        v.push_back(i);
    }
    std::cout << std::accumulate(v.begin(), v.end(), 0) << std::endl;
    std::for_each(v.begin(), v.end(), [](int v) { std::cout << v << "  "; });
    std::cout << std::endl;
}
/*
!   fill        向容器中添加元素
?   参数1       容器1开始迭代器
?   参数2       容器1结束迭代器
?   参数3       填充元素     
*/

void test2()
{
    std::vector<int> v; //?   源容器
    v.resize(10);
    std::for_each(v.begin(), v.end(), [](int v) { std::cout << v << "  "; });
    std::cout << std::endl;
    std::fill(v.begin(), v.end(), 99);
    std::for_each(v.begin(), v.end(), [](int v) { std::cout << v << "  "; });
    std::cout << std::endl;
}

int main()
{
    test1();
    test2();
    return 0;
}