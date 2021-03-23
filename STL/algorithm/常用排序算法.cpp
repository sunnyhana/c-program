#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

/*
!   merge      容器合并，并存储到另一个容器中
?   参数1       容器1开始迭代器
?   参数2       容器1结束迭代器
?   参数3       容器2开始迭代器
?   参数4       容器2结束迭代器
?   参数5       目标容器开始迭代器     
?   return     返回元素个数
*/
void test1()
{
    std::vector<int> v1, v2;
    for (int i = 0; i < 10; i += 2)
    {
        v1.push_back(i);
        v2.push_back(i + 1);
    }
    std::vector<int> vTarget;

    vTarget.resize(10);
    std::for_each(v1.begin(), v1.end(), [](int v) { std::cout << v << "  "; });
    std::cout << std::endl;
    std::for_each(v2.begin(), v2.end(), [](int v) { std::cout << v << "  "; });

    std::cout << std::endl;
    std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    std::for_each(vTarget.begin(), vTarget.end(), [](int v) { std::cout << v << "  "; });
}

/*
!   sort       容器元素排序
?   参数1       容器1开始迭代器
?   参数2       容器1结束迭代器
?   参数3       回调函数或者谓词     
?   return     void
*/

/*
!   random_shuffle       对指定范围内的元素随机调整次序
?   参数1       容器开始迭代器
?   参数2       容器结束迭代器    
?   return     void
*/

/*
!   reverse     反转指定范围的容器
?   参数1       容器1开始迭代器
?   参数2       容器1结束迭代器   
?   return     void
*/

int main()
{
    test1();
    return 0;
}
