/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:00:41 by esafar            #+#    #+#             */
/*   Updated: 2021/12/08 11:00:43 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_player_pos(t_test *test)
{
	test->player.pos_i = 0;
	test->player.lastpos_i = 0;
	test->player.hurt = 0;
	test->player.pos_j = 0;
	test->player.lastpos_j = 0;
	test->player.pos_x = 0;
	test->player.pos_y = 0;
	test->player.steps = 0;
	test->player.lock_pos = 0;
}

void	init_player(t_test *test)
{
	init_player_pos(test);
	test->player.frontside.img = NULL;
	test->player.frontside.addr = NULL;
	test->player.backside.img = NULL;
	test->player.backside.addr = NULL;
	test->player.rightside.img = NULL;
	test->player.rightside.addr = NULL;
	test->player.leftside.img = NULL;
	test->player.leftside.addr = NULL;
	test->player.dmg_front.img = NULL;
	test->player.dmg_front.addr = NULL;
	test->player.dmg_back.img = NULL;
	test->player.dmg_back.addr = NULL;
	test->player.dmg_right.img = NULL;
	test->player.dmg_right.addr = NULL;
	test->player.dmg_left.img = NULL;
	test->player.dmg_left.addr = NULL;
}

void	initialize(t_test *test)
{
	test->mlx = NULL;
	test->win = NULL;
	test->frame = 0;
	test->loop = 1;
	test->intro_or_not = 1;
	test->data.img = NULL;
	test->data.addr = NULL;
	init_stats(test);
	init_event(test);
	init_param(test);
	init_intro(test);
	init_player(test);
	init_fire(test);
	init_chimney_dresser(test);
	init_collec_exit(test);
	init_all_remain(test);
	test->tex.tex_x = 0;
	test->tex.tex_y = 0;
	test->tex.ratio_x = 1.0f;
	test->tex.ratio_y = 1.0f;
}
