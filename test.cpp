#include <iostream>
#include <string>
using namespace std;
void test01()
{
	int a=10;
	int &b = a;
	b=20;
	cout<<b<<endl;

}
const double pi = 3.14;
//创建圆类
class Circle
{
public://公共权限

	//
	int m_r;    //成员属性：半径

	//成员函数：类里面函数；
	double calculate()
	{
		return 2 * pi * m_r;
	}

};

void test02()
{
	Circle c0;       //通过类，创建对象；
	c0.m_r = 10;     //为对象赋值
	cout<< "c0的周长： " << c0.calculate() <<endl; //输出对象c0的周长
}
int main(void)
{
	/*
	string user_name;
	cout << "please enter your name:";
	cin >> user_name;
	cout <<"hello,"<<user_name<<",,,,and ,goodbye!"<<'\n';
	*/
	//test01();
	test02();
	return 0;
	
}

