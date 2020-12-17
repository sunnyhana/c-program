#include <iostream>
using namespace std;

class Animal
{
public:
    int m_age;
};

class Sheep : virtual public Animal
{
};

class Tou : virtual public Animal
{
};

class Sheeptou : public Sheep, public Tou
{
};
//! 菱形继承解决方案：虚继承 virtual
void test1()
{
    Sheeptou t;
    t.Sheep::m_age = 10;
    t.Tou::m_age = 20;
    cout << t.Sheep::m_age << endl;
    cout << t.Tou::m_age << endl;
}

int main()
{
    test1();
    return 0;
}