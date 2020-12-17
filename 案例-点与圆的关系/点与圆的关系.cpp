#include <iostream>
#include <string>
using namespace std;

class point     //点类
{
    private: 
        int px,py;

    public: 
        void setpx(int x,int y){px = x; py =y;}
        int getpx(){return px;}
        int getpy(){return py;}
};

class circel
{
    private : 
        int cx,cy,cr;
    public : 
        void setP(int x,int y){cx = x; cy =y;} 
        void setR(int r){cr = r;}
        int getcx(){return cx;}
        int getcy(){return cy;}
        int getcr(){return cr;} 

        void C_P(int px,int py)
        {
            if((px-cx)*(px-cx)+(py-cy)*(py-cy) > cr*cr)
            {
                cout << "此点在圆外" <<endl;
            }
            if ((px-cx)*(px-cx)+(py-cy)*(py-cy) == cr*cr)
            {
                cout << "此点在圆上" <<endl;
            }
            if ((px-cx)*(px-cx)+(py-cy)*(py-cy) < cr*cr)
            {
                cout << "此点在圆内" <<endl;
            }
        }
};
void test0()
{
    point p;
    circel c;

    p.setpx(2,0);

    c.setP(0,0);
    c.setR(2);

    c.C_P(p.getpx(),p.getpy());

}
int main()
{
    test0();
    return 0;
}