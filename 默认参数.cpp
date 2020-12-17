#include <iostream>
using namespace std;

//函数参数注意事项：
//若有一个位置有了默认参数，那么从这个位置开始，从左往右都必须要有默认参数
//传入参数，如果有参数就用传入的参数，没有参数就用默认值
 void func(int a,int b=20,int c=10)
{
    cout<< "a+b= " << a+b << endl;

}
void test1()
{
    func(1);
}

//函数 占位参数
//若有了占位参数，函数调用时候必须提供这个参数，但是不用参数
//占位参数，没有什么大用途，只有在重载++符号才有点用
//占位参数，可以用默认值
void func1(int a,int)
{

}
void test2()
{
    func1(10,1);
}
int main()
{
    //test1(); 
    test2();
}