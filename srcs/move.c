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
	        test->player.side = &test->player.rightside;
            test->player.pos_x += 64;
            test->player.pos_y += 0;        
        }
        else if (test->param.map[test->player.pos_i][test->player.pos_j + 1] == 'E' && test->collec.count != test->collec.amount)
        {
	        test->player.side = &test->player.rightside;
            printf("Not enought items to go out.\n");
        }
        else if (test->param.map[test->player.pos_i][test->player.pos_j + 1] == 'E' && test->collec.count == test->collec.amount)
        {
	        test->player.side = &test->player.rightside;
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
	        test->player.side = &test->player.rightside;
            test->player.pos_x += 64;
            test->player.pos_y += 0;
        }
    }
    else
        test->player.side = &test->player.rightside;
}

void    move_left(t_test *test)
{
    if (test->player.pos_j != 0 && test->param.map[test->player.pos_i][test->player.pos_j - 1] != '1')
    {
        if (test->param.map[test->player.pos_i][test->player.pos_j - 1] == 'C')
        {
            test->collec.count++;
            printf("%d object in your inventory\n", test->collec.count);
            test->param.map[test->player.pos_i][test->player.pos_j] = '0';
            test->param.map[test->player.pos_i][test->player.pos_j - 1] = 'P';
            test->player.lastpos_j = test->player.pos_j;
            test->player.pos_j--;
	        test->player.side = &test->player.leftside;
            test->player.pos_x -= 64;
            test->player.pos_y += 0;
        }
        else if (test->param.map[test->player.pos_i][test->player.pos_j - 1] == 'E' && test->collec.count != test->collec.amount)
        {
	        test->player.side = &test->player.leftside;
            printf("Not enought items to go out.\n");
        }
        else if (test->param.map[test->player.pos_i][test->player.pos_j - 1] == 'E' && test->collec.count == test->collec.amount)
        {
	        test->player.side = &test->player.leftside;
            printf("Good job! You finished the game \n");
            test->collec.exit = 1;
            clean_exit(test);
        }
        else
        {
            test->param.map[test->player.pos_i][test->player.pos_j] = '0';
            test->param.map[test->player.pos_i][test->player.pos_j - 1] = 'P';
            test->player.lastpos_j = test->player.pos_j;
            test->player.pos_j--;
	        test->player.side = &test->player.leftside;
            test->player.pos_x -= 64;
            test->player.pos_y += 0;
        }
    }
    else
        test->player.side = &test->player.leftside;
}

void    move_down(t_test *test/*, int wtd*/)
{
    if (test->player.pos_i + 1 != 0 && test->param.map[test->player.pos_i + 1][test->player.pos_j] != '1')
    {
        if (test->param.map[test->player.pos_i + 1][test->player.pos_j] == 'C')
        {
            test->collec.count++;
            printf("%d object in your inventory\n", test->collec.count);
            test->param.map[test->player.pos_i][test->player.pos_j] = '0';
            test->param.map[test->player.pos_i + 1][test->player.pos_j] = 'P';
            test->player.lastpos_i = test->player.pos_i;
            test->player.pos_i++;
	        test->player.side = &test->player.frontside;
            test->player.pos_x -= 64;
            test->player.pos_y += 64;
        }
        else if (test->param.map[test->player.pos_i + 1][test->player.pos_j] == 'E' && test->collec.count != test->collec.amount)
        {
	        test->player.side = &test->player.frontside;
            printf("Not enought items to go out.\n");
        }
        else if (test->param.map[test->player.pos_i + 1][test->player.pos_j] == 'E' && test->collec.count == test->collec.amount)
        {
	        test->player.side = &test->player.frontside;
            printf("Good job! You finished the game \n");
            test->collec.exit = 1;
            clean_exit(test);
        }
        else
        {
            test->param.map[test->player.pos_i][test->player.pos_j] = '0';
            test->param.map[test->player.pos_i + 1][test->player.pos_j] = 'P';
            test->player.lastpos_i = test->player.pos_i;
            test->player.pos_i++;
		    test->player.side = &test->player.frontside;
            test->player.pos_x -= 64;
            test->player.pos_y += 64;
        }
    }
    else
		test->player.side = &test->player.frontside;
}

void    move_up(t_test *test)
{
    if (test->param.map[test->player.pos_i - 1][test->player.pos_j] != '1')
    {
        if (test->param.map[test->player.pos_i - 1][test->player.pos_j] == 'C')
        {
            test->collec.count++;
            printf("%d object in your inventory\n", test->collec.count);
            test->param.map[test->player.pos_i][test->player.pos_j] = '0';
            test->param.map[test->player.pos_i - 1][test->player.pos_j] = 'P';
            test->player.lastpos_i = test->player.pos_i;
            test->player.pos_i--;
		    test->player.side = &test->player.backside;
            test->player.pos_x += 64;
            test->player.pos_y -= 64;
        }
        else if (test->param.map[test->player.pos_i - 1][test->player.pos_j] == 'E' && test->collec.count != test->collec.amount)
        {
		    test->player.side = &test->player.backside;
            printf("Not enought items to go out.\n");
        }
        else if (test->param.map[test->player.pos_i - 1][test->player.pos_j] == 'E' && test->collec.count == test->collec.amount)
        {
		    test->player.side = &test->player.backside;
            printf("Good job! You finished the game \n");
            test->collec.exit = 1;
            clean_exit(test);
        }
        else
        {
            test->param.map[test->player.pos_i][test->player.pos_j] = '0';
            test->param.map[test->player.pos_i - 1][test->player.pos_j] = 'P';
            test->player.lastpos_i = test->player.pos_i;
            test->player.pos_i--;
	        test->player.side = &test->player.backside;
            test->player.pos_x += 64;
            test->player.pos_y -= 64;
        }
    }
    else
	    test->player.side = &test->player.backside;
}