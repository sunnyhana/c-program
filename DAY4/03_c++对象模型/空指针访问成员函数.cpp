#include <iostream>
using namespace std;


class Person
{
        int m_age;
    public :   
        void show ()
            {
                cout << "Person" <<endl; 
            }
        void showage()
        {
            //if(this == NULL) return ;   //防止有空指针访问
            cout << m_age <<endl;     //this->m_age传过来的this指向NULL;所以自然就报错了
        }
};
void test1()
{
    Person *p = NULL;
    p->show();
    p->showage();      
}

int main()
{
    test1();
    return 0;
}