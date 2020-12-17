#include <iostream>
using namespace std ;

class Person
{
    public :            //构造函数和析构函数比必须在public权限下
    // 构造函数写法
    //与类名相同，没有返回值，不写void ,可以重载,可以有参数
    Person ()    //构造函数 ,编译器自动调用，而不是手动，而且只能调用一次。
    {
        cout << "构造函数" << endl;
    }

    //析构函数写法：
    //析构函数名是在类名前面+“～”组成，没有返回值，不能有void，不能有参数，不能重载。
    ~Person()            //编译器自动调用，且只能调用一次；
    {
        cout << "析构函数" << endl;
    }

};
void test()
{
    Person ren;         //默认调用了构造和析构，是系统提供的两个空实现的函数


}
int main()
{
    test();

    return 0;
}