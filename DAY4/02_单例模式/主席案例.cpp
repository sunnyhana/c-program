#include <iostream>
using namespace std;

//需求：
//单例模式，为了创建类中对象，保证只有一个对象，

class ChairMan
{
    public :  
        static ChairMan* getInstance()     //get方法返回singleMan
        {
            return singleMan;
        }
    private :  
        ChairMan()    //第一步：构造函数私有化
        {
            cout<< "创建国家主席" << endl;
        } 

        ChairMan(const ChairMan& p)    //第三步：拷贝构造私有化 
        {

        }    
        
        static ChairMan * singleMan;    //第二步：静态类指针变量私有化
};
ChairMan * ChairMan::singleMan = new ChairMan;    //静态变量，类外初始化，类内声明

void test1()
{
    //ChairMan c1;
    //ChairMan * c2 = new ChairMan;
    //ChairMan::singlMan;

    ChairMan * m1 = ChairMan::getInstance();
    ChairMan *m2 = ChairMan::getInstance();
    if (m1 == m2 )
    {
        cout << "m1与m2相同" << endl;
    }
    else
    {
        
        cout << "m1与m2不相同" << endl;
    }

    ChairMan *m3 = new ChairMan(*m2);    //m2为指针，*m2就取本体。
    
      if (m3 == m2 )
    {
        cout << "m3与m2相同" << endl;
    }
    else
    {
        
        cout << "m3与m2不相同" << endl;
    }

}

int main()
{
    test1();
    return 0;
}

/*
总结：

1、将默认构造和拷贝构造进行私有化
2、内部维护一个对象的指针，并私有化，再对外提供getinstance()获取指针
3、保证只能实例化出一个对象


*/