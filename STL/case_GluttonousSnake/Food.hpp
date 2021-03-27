#ifndef _FOOD_HEAD
#define _FOOD_HEAD
#include <iostream>
#include "wall.hpp"

class Food
{
public:
    Food(Wall &tampwall);

    void set_food();

    int food_x;
    int food_y;

    Wall &wall;
};

////////////////////////////

Food::Food(Wall &tampwall) : wall(tampwall)
{
}

void Food::set_food()
{
    while (1)
    {
        food_x = rand() % (Wall::X - 2) + 1;
        food_y = rand() % (Wall::Y - 2) + 1;

        if (wall.get_wall(food_x, food_y) != '*' && wall.get_wall(food_x, food_y) != '@')
        {
            wall.set_wall(food_x, food_y, '$');
            break;
        }
    }
}

#endif // _FOOD_HEAD