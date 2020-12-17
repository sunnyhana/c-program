#include<iostream>
using namespace std;
void test0()  //引用的基本使用
{
    int a=10;
    int &b=a;    //引用必须初始化，之后不可修改
    b=200;
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
}

void test1()     //对数组建立引用
{
    int arr[10];
    for(int i=0;i<10;i++)
    {
        arr[i]=i;
    }
    int (&parr)[10]=arr;    //给数组起别名

    for(int i=0;i<10;i++)
    {
        cout<<parr[i]<<"   ";
    }
    cout<<endl;
    //第二种方式 起别名
    typedef int (ARRAYREY)[10];  //一个具有十个元素的int型数组
    ARRAYREY &parr2=arr;
    for(int i=0;i<10;i++)
    {
        cout<<parr2[i]<<"   ";
    }
    cout<<endl;

}

//引用传递参数；

void myswap(int &a,int &b)
{
    int t;
    a=t;a=b;b=t;
}
void test2()
{
    int a=10,b=20;
    cout <<"原始："<<"a="<<a<<"    "
        <<"b="<<b<<endl;
    myswap(a,b);
    cout <<"调换："<<"a="<<a<<"    "
        <<"b="<<b<<endl;
}

//指针的引用

struct person    //定义结构体
{
    int p_age;
};
void allcoatmenory(person **p) //开辟存储空间，并初始化
{
    *p = (person *)malloc(sizeof(person));
    (*p)->p_age = 100;        
}

//利用指针引用开辟空间
void allocatMamoryByRey(person* &p)
{
    p=(person*)malloc(sizeof(person));
    p->p_age = 200;
}
void test3()
{
    person *p =0;
    allcoatmenory(&p);
    cout<< "p的年龄： "<<p->p_age<<endl;
    allocatMamoryByRey(p);
    cout<< "p的年龄： "<<p->p_age<<endl;
}


// 常量的引用
//常量引用的场景-----用来修饰形参，防止被修改。
void showValue(const int &val)     
{
    //val +=1000;   //如果只想显示内容，而不修改内容，那么就用const修饰形参
    cout<< "VAL= " << val <<endl;
}
void test4()
{
    //int &ref =10;  //错误，引用了不合法的内存

    const int &ref=10;
    //加入const后，编译器处理方式为：int temp=10; const int &ref=temp;
    //ref=10;   不可直接修改；可用指针修改
    int* p = (int*)&ref;  //此时&为取地址符
    *p = 1000;
    cout << "REF= " << ref <<endl;

    int a = 10;
    showValue(a);
}
int main() 
{   
    //test0();  //引用的基本使用
    //test1();  //对数组的引用
    //test2();  //y引用传递参数
    //test3();  //指针的引用
    test4();
    //system("pause");   //阻塞功能
    return EXIT_SUCCESS;

}
