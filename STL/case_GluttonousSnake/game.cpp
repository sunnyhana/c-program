#include <iostream>
#include <ctime>
#include <unistd.h>
#include "wall.hpp"
#include "snake.hpp"
#include "Food.hpp"
int main()
{
    //随机种子
    srand((unsigned int)time(NULL));
    Wall wa;
    bool isDead = false;
    wa.init_wall();

    Food food(wa);
    food.set_food();

    snake sna(wa, food);
    sna.init_snake();

    /*   测试移动
    sna.move('s');
    sna.move('s');
    sna.move('d');
    sna.move('w');

    */

    //sna.del_point(); //*   删除尾节点

    wa.display_wall();

    while (!isDead)
    {
        char key = getchar();

        //!  BUG！无法检测键盘   接受键盘控制必须按回车键

        do
        {
            if (sna.move(key) == true)
            {
                system("clear"); //*   linux 中清屏：clear     windows中为cls
                wa.display_wall();
                sleep(1);
            }
            else
            {
                isDead = true;
                break;
            }
        } while (9);
    }

    return 0;
}