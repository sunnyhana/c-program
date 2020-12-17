#include <iostream>
#include <string>

using namespace std;

//需求：
//设计立方体类Cube
//求出立方体表面积和体积
//分别用全局函数和成员函数判断两两个立方体是否相等


class Cube 
{
private: 
    int c_l,c_w,c_h,c_s,c_v;

public: 
    void set_l(int l)          //设置立方体长
    {
        c_l = l;
    }

    void set_w(int w)          //设置立方体宽
    {
        c_w = w;
    }
   
    void set_h(int h)           //设置立方体高
    {
        c_h = h;
    }

    int get_l()                 //获取长
    {
        return c_l;   
    }

    int get_w()                  //获取宽
    {
        return c_w;
    }

    int get_h()                   //获取高
    {
        return c_h;
    }

    void get_s()                   //获取立方体表面积
    {
        cout << "立方体表面积为： " << 2*(c_l*c_w+c_l*c_h+c_w*c_h) <<endl;
    }

    void get_v()                    //获取立方体体积
    {
        cout << "立方体体积为： " << c_l*c_w*c_h <<endl;
    }

    //成员函数判断是否相等
    bool compareCubeByClass(Cube & cube)
    {
        bool temp = c_l == cube.get_l() && c_w ==cube.get_w() && c_h == cube.get_h();
        return temp;
    }

    
};

bool copareCube(Cube & c1, Cube & c2)    //对比两个立方体是否相等
{
    if(c1.get_l() == c2.get_l() && c1.get_w() == c2.get_w() && c1.get_h() == c2.get_h() )
    {
        return true;
    }
    return false;
    
}

void test1()
{
    Cube a,b;
    a.set_l(2);
    a.set_w(1);
    a.set_h(1);
    a.get_s();
    a.get_v();
    
    b.set_l(2);
    b.set_w(1);
    b.set_h(1);

    //调用全局函数判断两个立方体是否相等
    bool temp = copareCube(a,b);

    if (temp)
    {
        cout << "1-这两个立方体是一模一样的" <<endl;
    }
    else
    {
        cout << "1-这两个立方体是不一样的" <<endl;
    }

    //调用成员方法判断
    if (a.compareCubeByClass(b))
    {
        cout << "2-这两个立方体是一模一样的" <<endl;
    }
    else
    {
        cout << "2-这两个立方体是不一样的" <<endl;
    }

}
int main()
{
    test1();
    return 0;
}