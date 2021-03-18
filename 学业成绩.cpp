#include <iostream>
#include <string>
using namespace std;

void test1()
{
    float j_math, j_algo, j_lin, j_en, j_net, j_computer, j_iot; //?绩点：高数、数据结构、线代、英语、计网、组成原理、物联网通信
    float s_math = 4.0, s_algo = 4.5, s_lin = 2.5, s_en = 3.0, s_net = 3.0, s_computer = 4.0, s_iot = 3.0;
    float sum, j, x;

    cout << "请按下面顺序输入绩点：高数、数据结构、线代、英语、计网、组成原理、物联网通信" << endl;
    cin >> j_math >> j_algo >> j_lin >> j_en >> j_net >> j_computer >> j_iot;
    cout << "您输入的个学科绩点如下：" << endl;
    cout << "高数:" << j_math << " 数据结构：" << j_algo << " 线代：" << j_lin << "  英语：" << j_en << "  计网：" << j_net << "  组成原理：" << j_computer << "  物联网通信：" << j_iot << endl;

    sum = j_math * s_math + j_algo * s_algo + j_lin * s_lin + j_en * s_en + j_computer * s_computer + j_iot * s_iot;
    x = s_math + s_algo + s_lin + s_en + s_net + s_computer + s_iot;
    j = ((sum / x) * 10 + 50) * 0.7;
    cout << "该学生的学业成绩为 ： " << j << endl;
    cout << endl;
}

int main()
{
    while (getchar() != 'a')
    {
        test1();
    }
    return 0;
}