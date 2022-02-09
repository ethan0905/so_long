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
	ft_putstr_fd("This hurt....\nlives left : ", 1);
	ft_putnbr_fd(test->stats.lives, 1);
	ft_putstr_fd("\n", 1);
	if (test->stats.lives == 0)
	{
		ft_putstr_fd("GAME OVER :(\n", 1);
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
		ft_putstr_fd("Good job! You finished the game\n", 1);
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
	ft_putstr_fd("Not enought items to go out.\n", 1);
	test->dialog_box.event = 3;
	draw_dialog_box(test);
	test->dialog_box.keep = 1;
}
