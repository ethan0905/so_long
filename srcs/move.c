#include "../so_long.h"

void move_right(t_test *test)
{   
    if (test->player.lock_pos == 0 && test->player.pos_j < test->param.width && test->player.pos_i < test->param.height && test->param.map[test->player.pos_i][test->player.pos_j + 1] != '1')
    {
        if (test->param.map[test->player.pos_i][test->player.pos_j + 1] == 'C')
        {
	        test->player.side = &test->player.rightside;
            printf("Press E to take the item\n");      
        }
        else if (test->param.map[test->player.pos_i][test->player.pos_j + 1] == 'E' && test->collec.count != test->collec.amount)
        {
	        test->player.side = &test->player.rightside;
            printf("Not enought items to go out.\n");
		    test->dialog_box.event = 3;
	    	draw_dialog_box(test);
	    	test->dialog_box.keep = 1;
        }
        else if (test->param.map[test->player.pos_i][test->player.pos_j + 1] == 'E' && test->collec.count == test->collec.amount)
        {
	        test->player.side = &test->player.rightside;
            // printf("Good job! You finished the game\n");
            test->collec.exit = 1;
            if (test->all.exit.opened == 1)
                clean_exit(test);
        }
        else if (test->param.map[test->player.pos_i][test->player.pos_j + 1] == 'T')
        {
	        test->player.side = &test->player.rightside;
            test->stats.lives--;
            printf("What a good way to loose stats\nlives left : %d\n", test->stats.lives);
            if (test->stats.lives == 0)
            {
                printf("GAME OVER :(\n");
                clean_exit(test);
            }
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
        test->player.steps++;
    }
    else
        test->player.side = &test->player.rightside;
    draw_score(test);
}

void    move_left(t_test *test)
{
    if (test->player.lock_pos == 0 && test->player.pos_j != 0 && test->param.map[test->player.pos_i][test->player.pos_j - 1] != '1')
    {
        if (test->param.map[test->player.pos_i][test->player.pos_j - 1] == 'C')
        {
	        test->player.side = &test->player.leftside;
            printf("Press E to take the item\n");
        }
        else if (test->param.map[test->player.pos_i][test->player.pos_j - 1] == 'E' && test->collec.count != test->collec.amount)
        {
	        test->player.side = &test->player.leftside;
            printf("Not enought items to go out.\n");
		    test->dialog_box.event = 3;
	    	draw_dialog_box(test);
	    	test->dialog_box.keep = 1;
        }
        else if (test->param.map[test->player.pos_i][test->player.pos_j - 1] == 'E' && test->collec.count == test->collec.amount)
        {
	        test->player.side = &test->player.leftside;
            printf("Good job! You finished the game \n");
            test->collec.exit = 1;
            if (test->all.exit.opened == 1)
                clean_exit(test);
        }
        else if (test->param.map[test->player.pos_i][test->player.pos_j - 1] == 'T')
        {
	        test->player.side = &test->player.leftside;
            test->stats.lives--;
            printf("What a good way to loose stats\nlives left : %d\n", test->stats.lives);
            if (test->stats.lives == 0)
            {
                printf("GAME OVER :(\n");
                clean_exit(test);
            }
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
        test->player.steps++;
    }
    else
        test->player.side = &test->player.leftside;
    draw_score(test);
}

void    move_down(t_test *test)
{
    if (test->player.lock_pos == 0 && test->player.pos_i + 1 != 0 && test->param.map[test->player.pos_i + 1][test->player.pos_j] != '1')
    {
        if (test->param.map[test->player.pos_i + 1][test->player.pos_j] == 'C')
        {
	        test->player.side = &test->player.frontside;
            printf("Press E to take the item\n");
        }
        else if (test->param.map[test->player.pos_i + 1][test->player.pos_j] == 'E' && test->collec.count != test->collec.amount)
        {
	        test->player.side = &test->player.frontside;
            printf("Not enought items to go out.\n");
		    test->dialog_box.event = 3;
	    	draw_dialog_box(test);
	    	test->dialog_box.keep = 1;
        }
        else if (test->param.map[test->player.pos_i + 1][test->player.pos_j] == 'E' && test->collec.count == test->collec.amount)
        {
	        test->player.side = &test->player.frontside;
            printf("Good job! You finished the game \n");
            test->collec.exit = 1;
            if (test->all.exit.opened == 1)
                clean_exit(test);
        }
        else if (test->param.map[test->player.pos_i + 1][test->player.pos_j] == 'T')
        {
	        test->player.side = &test->player.frontside;
            test->stats.lives--;
            printf("What a good way to loose stats\nlives left : %d\n", test->stats.lives);
            if (test->stats.lives == 0)
            {
                printf("GAME OVER :(\n");
                clean_exit(test);
            }
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
        test->player.steps++;
    }
    else
		test->player.side = &test->player.frontside;
    draw_score(test);
}

void    move_up(t_test *test)
{
    if (test->player.lock_pos == 0 && test->param.map[test->player.pos_i - 1][test->player.pos_j] != '1')
    {
        if (test->param.map[test->player.pos_i - 1][test->player.pos_j] == 'C')
        {
	        test->player.side = &test->player.backside;
            printf("Press E to take the item\n");
        }
        else if (test->param.map[test->player.pos_i - 1][test->player.pos_j] == 'E' && test->collec.count != test->collec.amount)
        {
		    test->player.side = &test->player.backside;
            printf("Not enought items to go out.\n");
		    test->dialog_box.event = 3;
	    	draw_dialog_box(test);
	    	test->dialog_box.keep = 1;
        }
        else if (test->param.map[test->player.pos_i - 1][test->player.pos_j] == 'E' && test->collec.count == test->collec.amount)
        {
		    test->player.side = &test->player.backside;
            printf("Good job! You finished the game \n");
            test->collec.exit = 1;
            if (test->all.exit.opened == 1)
                clean_exit(test);
        }
        else if (test->param.map[test->player.pos_i - 1][test->player.pos_j] == 'T')
        {
		    test->player.side = &test->player.backside;
            test->stats.lives--;
            printf("What a good way to loose stats\nlives left : %d\n", test->stats.lives);
            if (test->stats.lives == 0)
            {
                printf("GAME OVER :(\n");
                clean_exit(test);
            }
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
        test->player.steps++;
    }
    else
    {
	    test->player.side = &test->player.backside; 
    }
    draw_score(test);

}
