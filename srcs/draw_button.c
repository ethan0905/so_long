/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_button.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 09:49:54 by esafar            #+#    #+#             */
/*   Updated: 2021/12/08 09:50:04 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_which_player_side(t_test *test)
{
	if (test->param.map[test->player.pos_i][test->player.pos_j + 1] == 'C')
		test->player.side = &test->player.rightside;
	else if (test->param.map[test->player.pos_i][test->player.pos_j - 1] == 'C')
		test->player.side = &test->player.leftside;
	else if (test->param.map[test->player.pos_i - 1][test->player.pos_j] == 'C')
		test->player.side = &test->player.backside;
	else if (test->param.map[test->player.pos_i + 1][test->player.pos_j] == 'C')
		test->player.side = &test->player.frontside;
}

void	make_collec_key_event(t_test *test)
{
	if (test->button.time % 2 == 0)
	{
     	draw_on_image(test, &test->button.e_key, test->player.pos_x + 32, test->player.pos_y - 42);
		while (test->iter.i < 45000000)
			test->iter.i++;
		test->button.time = 1;
	}
	else if (test->button.time % 2 == 1)
	{
		draw_walls(test);
		draw_floors(test);
		draw_trap(test);
		draw_exit(test);
		draw_furnitures(test);
		draw_collectibles(test);
		check_which_player_side(test);
		draw_player(test);
		draw_score(test);
		while (test->iter.i < 240000000)
			test->iter.i++;
		test->button.time = 0;
	}
}

void	make_piano_key_event(t_test *test)
{
	if (test->button.time % 2 == 0 && test->player.lock_pos == 0)
	{
       	draw_on_image(test, &test->button.p_key, test->player.pos_x + 32, test->player.pos_y - 42);
		while (test->iter.i < 45000000)
			test->iter.i++;
		test->button.time = 1;
	}
	else if (test->button.time % 2 == 1)
	{
		draw_walls(test);
		draw_floors(test);
		draw_trap(test);
		draw_exit(test);
		draw_furnitures(test);
		draw_collectibles(test);
		test->player.side = &test->player.backside;
		draw_player(test);
		draw_score(test);
		while (test->iter.i < 240000000)
			test->iter.i++;
		test->button.time = 0;
	}
}

void	make_exit_key_event(t_test *test)
{
	if (test->button.time % 2 == 0)
	{
       	draw_on_image(test, &test->button.o_key, test->player.pos_x + 32, test->player.pos_y - 42);
		while (test->iter.i < 45000000)
			test->iter.i++;
		test->button.time = 1;
		test->player.lock_pos = 1;
	}
	else if (test->button.time % 2 == 1)
	{
		draw_walls(test);
		draw_floors(test);
		draw_trap(test);
		draw_exit(test);
		draw_furnitures(test);
		draw_collectibles(test);
		draw_player(test);
		draw_score(test);
		while (test->iter.i < 240000000)
			test->iter.i++;
		test->button.time = 0;
	}
}

void	draw_button(t_test *test)
{
	test->iter.i = 0;
    if ((test->param.map[test->player.pos_i][test->player.pos_j + 1] == 'C' || test->param.map[test->player.pos_i][test->player.pos_j - 1] == 'C' || test->param.map[test->player.pos_i - 1][test->player.pos_j] == 'C' || test->param.map[test->player.pos_i + 1][test->player.pos_j] == 'C'))
		make_collec_key_event(test);
	else if (test->param.map[test->player.pos_i - 1][test->player.pos_j] == '1' && test->param.map[test->player.pos_i - 1][test->player.pos_j + 1] == '1' && test->param.map[test->player.pos_i - 1][test->player.pos_j + 2] == '0' && test->player.pos_j + 1 < test->param.width - 1 && test->param.map[test->player.pos_i - 1][test->player.pos_j - 1] == '1' && test->param.map[test->player.pos_i - 1][test->player.pos_j - 2] == '0')
		make_piano_key_event(test);
	else if (test->collec.exit == 1 && test->all.exit.opened == 0)
		make_exit_key_event(test);
}