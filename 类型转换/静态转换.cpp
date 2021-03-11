#include <iostream>
using namespace std;

void test1()
{
    char a = 'a';
    double b = static_cast<double>(a);
    cout << "b = " << b << endl;
}

class Base
{
};
class Child : public Base
{
};
class Other
{
};

void test02()
{
    Base *base = NULL;
    Child *child = NULL;
    //? 把父类转为子类，向下  不安全
    //Child *child1 = static_cast<Base *>(base);
    //?把子类转换成父类，向上   安全
    Base *base1 = static_cast<Child *>(child);
}
int main()
{
    test1();
    test02();
    return 0;
}