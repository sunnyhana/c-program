#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
class Person
{
public:
    deque<int> d;
    float score;
    static bool mycompany(int v1, int v2)
    {
        return v1 > v2;
    }
    void printDeque()
    {
        for (deque<int>::iterator it = this->d.begin(); it != this->d.end(); it++)
        {
            cout << *it << "  ";
        }
        cout << endl;
    }
    void func()
    {
        int sum = 0, count = 0;
        sort(this->d.begin(), this->d.end(), this->mycompany); //!    类内调用回调函数必须为静态
        cout << "排序后的成绩为：" << endl;
        this->d.pop_back();
        this->d.pop_front();
        for (deque<int>::iterator it = this->d.begin(); it != this->d.end(); it++)
        {
            sum += (*it);
            count++;
        }
        this->score = sum / count;
    }
};

void test()
{
    Person p1, p2, p3, p4, p5;
    vector<Person> v;
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    for (vector<Person>::iterator itv = v.begin(); itv != v.end(); itv++)
    {
        for (int i = 0; i < 10; i++)
        {
            itv->d.push_back(rand() % 61 + 60);
        }
    }
    int i = 0;
    for (vector<Person>::iterator itv = v.begin(); itv != v.end(); itv++)
    {
        i++;
        cout << "第" << i << "名选手";
        itv->func();
        itv->printDeque();
        cout << "第" << i << "名选手的平均分为：  " << itv->score << endl;
    }
}

int main()
{

    test();
    return 0;
}