/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_functionnalities.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:52:13 by esafar            #+#    #+#             */
/*   Updated: 2021/12/08 10:52:24 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_intro(t_test *test)
{
	test->intro.one.img = NULL;
	test->intro.one.addr = NULL;
	test->intro.two.img = NULL;
	test->intro.two.addr = NULL;
	test->intro.three.img = NULL;
	test->intro.three.addr = NULL;
	test->intro.four.img = NULL;
	test->intro.four.addr = NULL;
	test->intro.five.img = NULL;
	test->intro.five.addr = NULL;
}

void	init_stats(t_test *test)
{
	test->stats.lives = 3;
	test->stats.damages = 0;
	test->stats.typeface_life.img = NULL;
	test->stats.typeface_life.addr = NULL;
	test->stats.full_heart.img = NULL;
	test->stats.full_heart.addr = NULL;
	test->stats.empty_heart.img = NULL;
	test->stats.empty_heart.addr = NULL;
	test->stats.glass.img = NULL;
	test->stats.glass.addr = NULL;
	test->stats.step.img = NULL;
	test->stats.step.addr = NULL;
}

void	init_event(t_test *test)
{
	test->button.time = 0;
	test->button.e_key.img = NULL;
	test->button.e_key.addr = NULL;
	test->button.p_key.img = NULL;
	test->button.p_key.addr = NULL;
	test->button.o_key.img = NULL;
	test->button.o_key.addr = NULL;
	test->dialog_box.keep = 0;
	test->dialog_box.right.img = NULL;
	test->dialog_box.right.addr = NULL;
	test->dialog_box.mid.img = NULL;
	test->dialog_box.mid.addr = NULL;
	test->dialog_box.left.img = NULL;
	test->dialog_box.left.addr = NULL;
}

void	init_param(t_test *test)
{
	test->param.map = NULL;
	test->param.height = 0;
	test->param.height_with_wall = 0;
	test->param.width = 0;
	test->param.width_with_x = 0;
	test->param.rendered = 0;
}
