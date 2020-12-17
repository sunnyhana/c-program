#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//c语言采用结构体进行封装

struct Person
{
    char mName[64];
    int mAge;

};

struct Dog
{
    char dName[64];
    int dAge;
};

void PersonEat(struct Person *p)
{
    printf("%s在吃人饭\n",p->mName);

}

void DogEat(struct Dog *dog)
{
    printf("%s在吃狗粮\n",dog->dName);

}

void test01()
{
    struct Person p1;
    strcpy(p1.mName,"雅典娜");
    PersonEat(&p1);


}

void test02()
{
    struct Dog dog1;
    strcpy(dog1.dName,"二哈");
    DogEat(&dog1);

    struct Person p2;
    strcpy(p2.mName,"憨憨");
    DogEat(&p2);

}

//c语言封装属性和行为分开处理
//类型检测不够严格

int main()
{
    test01();
    test02();
    return 0;
}