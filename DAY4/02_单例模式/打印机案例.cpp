#include <iostream>
#include <string>

using namespace std;

class Printer
{
private:
    Printer() { count = 0; };
    Printer(const Printer &P){}; //1、将默认构造和拷贝构造进行私有化
    static Printer *onePrinter;  //2、内部维护一个对象的指针，并私有化，再对外提供getinstance()获取指针
    int count;

public:
    static Printer *getInstance()
    {
        return onePrinter;
    }
    void printer(string text)
    {
        count++;
        cout << "打印机第" << count << "次启动成功，打印了：" << text << endl;
    }
};
Printer *Printer::onePrinter = new Printer;

void test1()
{
    Printer *p1 = Printer::getInstance();
    p1->printer("测试！");
    (*p1).printer("测试！");
}

int main()
{
    test1();
    return 0;
}