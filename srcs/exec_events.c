/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:29:27 by esafar            #+#    #+#             */
/*   Updated: 2021/12/08 10:29:36 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
