#ifndef _SNAKE_HEAD
#define _SNAKE_HEAD
#include <iostream>
#include "wall.hpp"
#include "Food.hpp"

class snake
{
public:
    struct Point
    {
        int x;
        int y;

        Point *next;
    };

    enum
    {
        UP = 'w',
        DOWN = 's',
        LEFT = 'a',
        RIGHT = 'd'
    };

    snake(Wall &tempwall, Food &tempfood);

    void init_snake(); //初始化

    void destroy_snake(); //   删除蛇身体

    void add_point(int, int); //增加节点

    void del_point(); //删除尾节点

    bool move(char key); //移动蛇操作，返回值代表是是否游戏结束

    Point *p_head;

    Wall &wall;
    Food &food;
};

///////////////////////////////

snake::snake(Wall &tempwall, Food &tempfood) : wall(tempwall), food(tempfood)
{
    p_head = NULL;
}

void snake::init_snake()
{
    destroy_snake();
    add_point(4, 3);
    add_point(5, 3);
    add_point(5, 4);
    add_point(5, 5);
    add_point(6, 5);
}

//销毁蛇节点
void snake::destroy_snake()
{
    Point *p = p_head;

    while (p_head != NULL)
    {
        p = p_head->next;
        delete p_head;
        p_head = p;
    }
}

void snake::add_point(int i, int j)
{
    Point *new_point = new Point;
    new_point->x = i;
    new_point->y = j;

    new_point->next = NULL;

    if (p_head != NULL)
    {
        wall.set_wall(p_head->x, p_head->y, '*');
    }
    new_point->next = p_head;
    p_head = new_point;

    wall.set_wall(p_head->x, p_head->y, '@');
}

void snake::del_point()
{
    //?    两个节点以上再做删除操作
    if (p_head == NULL && p_head->next == NULL)
    {
        return;
    }

    Point *p, *q;
    p = p_head;
    q = p->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    wall.set_wall(q->x, q->y, ' ');
    delete q;
    q = NULL;
    //todo  在释放节点够不可以再通过相邻指针求其进行操作了
    //wall.set_wall(p->next->x, p->next->y, ' ');

    p->next = NULL;
}

bool snake::move(char key)
{
    int x = p_head->x, y = p_head->y; //获取蛇头的位置
    switch (key)
    {
    case UP:
        x -= 1;
        break;
    case DOWN:
        x += 1;
        break;
    case LEFT:
        y -= 1;
        break;
    case RIGHT:
        y += 1;
        break;
    default:
        break;
    }

    //?  判断用户到达的位置是否成功

    if (wall.get_wall(x, y) == '#' || wall.get_wall(x, y) == '*')
    {
        std::cout << "   GAME OVER！！！   " << std::endl;
        return false;
    }
    if (wall.get_wall(x, y) == '$')
    {
        add_point(x, y);
        food.set_food();
    }
    else
    {
        add_point(x, y);
        del_point();
    }
    return true;
}

#endif
