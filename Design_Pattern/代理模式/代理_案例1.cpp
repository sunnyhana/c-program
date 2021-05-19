#include <iostream>
#include <cstring>
using namespace std;

/*


*/

class MySystemCommonReference
{
public:
    virtual void run() = 0;
    virtual void setusernameandpassword(string, string) = 0;
};

class MySystem : public MySystemCommonReference
{
public:
    virtual void run()
    {
        cout << "******** 系 统 启 动 ********" << endl;
    }
    virtual void setusernameandpassword(string, string){}; //!基类中断虚函数在派生类中必须存在，哪怕是空实现
};

class MySystemProxy : public MySystemCommonReference
{
public:
    string m_name;
    string m_password;

    MySystem *my_system;

public:
    MySystemProxy(string username, string password)
    {
        this->m_name = username;
        this->m_password = password;
        my_system = new MySystem;
    }

    virtual void setusernameandpassword(string username, string password)
    {
        this->m_name = username;
        this->m_password = password;
    }

    bool checkusernameandpassword() //*检查用户名和密码
    {
        if (m_name == "root" && m_password == "123456")
            return true;
        return false;
    }

    virtual void run()
    {
        if (checkusernameandpassword())
        {
            cout << "权限通过！！！" << endl;
            my_system->run();
        }
        else
        {
            cout << "用户名或密码错误，权限不足！！！" << endl;
        }
    }

    ~MySystemProxy()
    {
        if (my_system != NULL)
        {
            delete my_system;
        }
    }
};

void test1()
{

    MySystemProxy *my_system_proxy = new MySystemProxy("admin", "123456");
    my_system_proxy->run();
    my_system_proxy->setusernameandpassword("root", "123456");
    my_system_proxy->run();
}

void test2()
{
    MySystemCommonReference *system = new MySystemProxy("root", "123456");
    //system_proxy->setusernameandpassword("root", "123456");
    system->run();
    cout << "重启后>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
    system->setusernameandpassword("admin", "123456");
    system->run();
}

int main()
{
    //test1();
    test2();
    return 0;
}