#ifndef _WALL_HEAD
#define _WALL_HEAD

#include <iostream>

class Wall
{
public:
    enum
    {
        Y = 40,
        X = 20
    };
    void init_wall();    //初始化区域
    void display_wall(); //显示区域
    void set_wall(int, int, char);
    char get_wall(int, int);

private:
    char wall_array[X][Y];
};

//////////////////////////////////

void Wall::init_wall()
{
    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < Y; j++)
        {
            if (i == 0 || j == 0 || i == X - 1 || j == Y - 1)
            {
                wall_array[i][j] = '#';
            }
            else
            {
                wall_array[i][j] = ' ';
            }
        }
    }
}

void Wall::display_wall()
{
    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < Y; j++)
        {
            std::cout << wall_array[i][j] << " ";
        }
        if (i == 9)
        {
            std::cout << "                "
                      << "自 制 贪 吃 蛇";
        }
        else if (i == 11)
        {
            std::cout << "                "
                      << " HANA  出 品";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Wall::set_wall(int i, int j, char c)
{
    wall_array[i][j] = c;
}

char Wall::get_wall(int i, int j)
{
    return wall_array[i][j];
}

#endif