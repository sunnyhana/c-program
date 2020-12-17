#include <iostream>
#include <string>
using namespace std;

class Phone
{
    public : 

        string m_Phonename;

        Phone()
        {
            cout <<"手机的默认构造函数调用" << endl;
        }

        Phone (string name)
        {
            m_Phonename = name;
            cout << "手机的有参构造函数" << endl ;
        }

        ~Phone()
        {
            cout << "手机的析构函数调用" <<endl;
        }


};
class Game 
{
    public :  
        
        string m_game;

        Game()
        {
            cout <<"游戏的默认构造函数" << endl;
        }

        Game (string name)
        {
            m_game = name;
            cout << "游戏的有参构造函数" << endl ;
        }

        ~Game()
        {
            cout << "游戏的析构函数" << endl;
        }
};

class Person 
{
    public : 
        string m_name;
        Phone m_phone;
        Game m_game;

        Person()
        {
            cout << "人的默认构造函数" << endl ;
        }
         
        Person(string name,string phoneName, string gameName ) : m_name( name ), m_phone( phoneName ),m_game( gameName )
        {
           // m_name = name;
           cout << "人的有参构造函数" << endl ;
        }

        ~Person()
        {
            cout << "人的析构函数" << endl ;
        }

        void PlayGame()
        {
            cout << m_name << "拿着" << m_phone.m_Phonename << "的新款手机，玩着" << m_game.m_game <<endl ;
        }

};

//类对象作为类成员时，构造顺序是，先将类对象一一构造，再构造自己，析构的顺序是相反的
void test1()
{
    Person p("张三","一加","王者荣耀");
   // p.m_phone.m_Phonename= "一加";
   // p.m_game.m_game = "王者农药";
    //p.m_name = 
    p.PlayGame();

}


int main()
{
    test1();
    return 0;
}