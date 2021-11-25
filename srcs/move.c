#include "../so_long.h"

void move_right(t_test *test/*, int wtd*/)
{   
    // printf("Position = %d %d\n", test->player.pos_i, test->player.pos_j);
    if (test->player.pos_j < test->param.width && test->player.pos_i < test->param.height && test->param.map[test->player.pos_i][test->player.pos_j + 1] != '1')
    {
        if (test->param.map[test->player.pos_i][test->player.pos_j + 1] == 'C')
        {
            test->collec.count++;
            printf("%d object in your inventory\n", test->collec.count);
            test->param.map[test->player.pos_i][test->player.pos_j] = '0';
            test->param.map[test->player.pos_i][test->player.pos_j + 1] = 'P';
            test->player.lastpos_j = test->player.pos_j;
            test->player.pos_j++;
            // print_map(test);
            // mlx_put_image_to_window(test->mlx, test->win, test->image.player_sideright, test->player.pos_x+64, test->player.pos_y);
            // mlx_put_image_to_window(test->mlx, test->win, test->player.right_side.img, test->player.pos_x+64, test->player.pos_y);
            draw_on_image_bis(test, &test->player.frontside, test->player.pos_x+64, test->player.pos_y);
            test->player.pos_x += 64;
            test->player.pos_y += 0;        
        }
        else if (test->param.map[test->player.pos_i][test->player.pos_j + 1] == 'E' && test->collec.count != test->collec.amount)
        {
            printf("Not enought items to go out.\n");
        }
        else if (test->param.map[test->player.pos_i][test->player.pos_j + 1] == 'E' && test->collec.count == test->collec.amount)
        {
            printf("Good job! You finished the game \n");
            test->collec.exit = 1;
            clean_exit(test);
        }
        else
        {
            test->param.map[test->player.pos_i][test->player.pos_j] = '0';
            test->param.map[test->player.pos_i][test->player.pos_j + 1] = 'P';
            test->player.lastpos_j = test->player.pos_j;
            test->player.pos_j++;
            // smart_print(test, wtd);
            // mlx_put_image_to_window(test->mlx, test->win, test->image.player_sideright, test->player.pos_x+64, test->player.pos_y);
            draw_on_image_bis(test, &test->player.frontside, test->player.pos_x+64, test->player.pos_y);
            test->player.pos_x += 64;
            test->player.pos_y += 0;
        }
    }
}
