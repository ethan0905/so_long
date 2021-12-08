/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:32:34 by esafar            #+#    #+#             */
/*   Updated: 2021/12/08 10:32:35 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_right(t_test *test)
{
	if (test->player.lock_pos == 0 && test->player.pos_j < test->param.width
		&& test->player.pos_i < test->param.height
		&& test->param.map[test->player.pos_i][test->player.pos_j + 1] != '1')
	{
		if (test->param.map[test->player.pos_i][test->player.pos_j + 1] == 'C')
		{
			test->player.side = &test->player.rightside;
			printf("Press E to take the item\n");
		}
		else if (test->param.map[test->player.pos_i][test->player.pos_j + 1]
			== 'E' && test->collec.count != test->collec.amount)
			exec_not_all_items(test, 1);
		else if (test->param.map[test->player.pos_i][test->player.pos_j + 1]
			== 'E' && test->collec.count == test->collec.amount)
			exec_exit(test, 1);
		else if (test->param.map[test->player.pos_i][test->player.pos_j + 1]
			== 'T')
			exec_trap(test, 1);
		else
			exec_right(test);
		test->player.steps++;
	}
	else
		test->player.side = &test->player.rightside;
	draw_score(test);
}

void	move_left(t_test *test)
{
	if (test->player.lock_pos == 0 && test->player.pos_j != 0
		&& test->param.map[test->player.pos_i][test->player.pos_j - 1] != '1')
	{
		if (test->param.map[test->player.pos_i][test->player.pos_j - 1] == 'C')
		{
			test->player.side = &test->player.leftside;
			printf("Press E to take the item\n");
		}
		else if (test->param.map[test->player.pos_i][test->player.pos_j - 1]
			== 'E' && test->collec.count != test->collec.amount)
			exec_not_all_items(test, 2);
		else if (test->param.map[test->player.pos_i][test->player.pos_j - 1]
			== 'E' && test->collec.count == test->collec.amount)
			exec_exit(test, 2);
		else if (test->param.map[test->player.pos_i][test->player.pos_j - 1]
			== 'T')
			exec_trap(test, 2);
		else
			exec_left(test);
		test->player.steps++;
	}
	else
		test->player.side = &test->player.leftside;
	draw_score(test);
}

void	move_down(t_test *test)
{
	if (test->player.lock_pos == 0 && test->player.pos_i + 1 != 0
		&& test->param.map[test->player.pos_i + 1][test->player.pos_j] != '1')
	{
		if (test->param.map[test->player.pos_i + 1][test->player.pos_j] == 'C')
		{
			test->player.side = &test->player.frontside;
			printf("Press E to take the item\n");
		}
		else if (test->param.map[test->player.pos_i + 1][test->player.pos_j]
			== 'E' && test->collec.count != test->collec.amount)
			exec_not_all_items(test, 4);
		else if (test->param.map[test->player.pos_i + 1][test->player.pos_j]
			== 'E' && test->collec.count == test->collec.amount)
			exec_exit(test, 4);
		else if (test->param.map[test->player.pos_i + 1][test->player.pos_j]
			== 'T')
			exec_trap(test, 4);
		else
			exec_down(test);
		test->player.steps++;
	}
	else
		test->player.side = &test->player.frontside;
	draw_score(test);
}

void	move_up(t_test *test)
{
	if (test->player.lock_pos == 0
		&& test->param.map[test->player.pos_i - 1][test->player.pos_j] != '1')
	{
		if (test->param.map[test->player.pos_i - 1][test->player.pos_j] == 'C')
		{
			test->player.side = &test->player.backside;
			printf("Press E to take the item\n");
		}
		else if (test->param.map[test->player.pos_i - 1][test->player.pos_j]
			== 'E' && test->collec.count != test->collec.amount)
			exec_not_all_items(test, 3);
		else if (test->param.map[test->player.pos_i - 1][test->player.pos_j]
			== 'E' && test->collec.count == test->collec.amount)
			exec_exit(test, 3);
		else if (test->param.map[test->player.pos_i - 1][test->player.pos_j]
			== 'T')
			exec_trap(test, 3);
		else
			exec_up(test);
		test->player.steps++;
	}
	else
		test->player.side = &test->player.backside;
	draw_score(test);
}
