#include "../so_long.h"

void    exec_right(t_test *test)
{
    test->param.map[test->player.pos_i][test->player.pos_j] = '0';
    test->param.map[test->player.pos_i][test->player.pos_j + 1] = 'P';
    test->player.lastpos_j = test->player.pos_j;
    test->player.pos_j++;
    test->player.side = &test->player.rightside;
    test->player.pos_x += 64;
    test->player.pos_y += 0;
}

void    exec_left(t_test *test)
{
    test->param.map[test->player.pos_i][test->player.pos_j] = '0';
    test->param.map[test->player.pos_i][test->player.pos_j - 1] = 'P';
    test->player.lastpos_j = test->player.pos_j;
    test->player.pos_j--;
	test->player.side = &test->player.leftside;
    test->player.pos_x -= 64;
    test->player.pos_y += 0;
}

void    exec_up(t_test *test)
{
    test->param.map[test->player.pos_i][test->player.pos_j] = '0';
    test->param.map[test->player.pos_i - 1][test->player.pos_j] = 'P';
    test->player.lastpos_i = test->player.pos_i;
    test->player.pos_i--;
	test->player.side = &test->player.backside;
    test->player.pos_x += 64;
    test->player.pos_y -= 64;
}

void    exec_down(t_test *test)
{
    test->param.map[test->player.pos_i][test->player.pos_j] = '0';
    test->param.map[test->player.pos_i + 1][test->player.pos_j] = 'P';
    test->player.lastpos_i = test->player.pos_i;
    test->player.pos_i++;
	test->player.side = &test->player.frontside;
    test->player.pos_x -= 64;
    test->player.pos_y += 64;
}

void	exec_trap(t_test *test, int direction)
{
	if (direction == 1)
		test->player.side = &test->player.rightside;
	if (direction == 2)
		test->player.side = &test->player.leftside;
	if (direction == 3)
		test->player.side = &test->player.backside;
	if (direction == 4)
		test->player.side = &test->player.frontside;
    test->player.hurt = 1;
    test->stats.lives--;
    printf("This hurt....\nlives left : %d\n", test->stats.lives);
    if (test->stats.lives == 0)
    {
        printf("GAME OVER :(\n");
        clean_exit(test);
    }
}

void	exec_exit(t_test *test, int direction)
{
	if (direction == 1)
		test->player.side = &test->player.rightside;
	if (direction == 2)
		test->player.side = &test->player.leftside;
	if (direction == 3)
		test->player.side = &test->player.backside;
	if (direction == 4)
		test->player.side = &test->player.frontside;
	test->collec.exit = 1;
    if (test->all.exit.opened == 1)
	{
	    printf("Good job! You finished the game\n");
        clean_exit(test);
	}
}

void	exec_not_all_items(t_test *test, int direction)
{
	if (direction == 1)
		test->player.side = &test->player.rightside;
	if (direction == 2)
		test->player.side = &test->player.leftside;
	if (direction == 3)
		test->player.side = &test->player.backside;
	if (direction == 4)
		test->player.side = &test->player.frontside;
    printf("Not enought items to go out.\n");
	test->dialog_box.event = 3;
	draw_dialog_box(test);
	test->dialog_box.keep = 1;
}

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
			exec_not_all_items(test, 1);
        else if (test->param.map[test->player.pos_i][test->player.pos_j + 1] == 'E' && test->collec.count == test->collec.amount)
			exec_exit(test, 1);
        else if (test->param.map[test->player.pos_i][test->player.pos_j + 1] == 'T')
			exec_trap(test, 1);
        else
            exec_right(test);
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
			exec_not_all_items(test, 2);
        else if (test->param.map[test->player.pos_i][test->player.pos_j - 1] == 'E' && test->collec.count == test->collec.amount)
			exec_exit(test, 2);
        else if (test->param.map[test->player.pos_i][test->player.pos_j - 1] == 'T')
			exec_trap(test, 2);
        else
            exec_left(test);
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
			exec_not_all_items(test, 4);
        else if (test->param.map[test->player.pos_i + 1][test->player.pos_j] == 'E' && test->collec.count == test->collec.amount)
			exec_exit(test, 4);
        else if (test->param.map[test->player.pos_i + 1][test->player.pos_j] == 'T')
			exec_trap(test, 4);
        else
			exec_down(test);
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
			exec_not_all_items(test, 3);
        else if (test->param.map[test->player.pos_i - 1][test->player.pos_j] == 'E' && test->collec.count == test->collec.amount)
			exec_exit(test, 3);
        else if (test->param.map[test->player.pos_i - 1][test->player.pos_j] == 'T')
			exec_trap(test, 3);
        else
			exec_up(test);
        test->player.steps++;
    }
    else
	    test->player.side = &test->player.backside; 
    draw_score(test);
}
