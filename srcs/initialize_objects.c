/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_objects.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:54:55 by esafar            #+#    #+#             */
/*   Updated: 2021/12/08 10:55:04 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_fire(t_test *test)
{
	test->all.fire.frame_one.img = NULL;
	test->all.fire.frame_one.addr = NULL;
	test->all.fire.frame_two.img = NULL;
	test->all.fire.frame_two.addr = NULL;
	test->all.fire.frame_three.img = NULL;
	test->all.fire.frame_three.addr = NULL;
	test->all.fire.frame_four.img = NULL;
	test->all.fire.frame_four.addr = NULL;
	test->all.fire.frame_five.img = NULL;
	test->all.fire.frame_five.addr = NULL;
	test->all.fire.frame_six.img = NULL;
	test->all.fire.frame_six.addr = NULL;
	test->all.fire.frame_seven.img = NULL;
	test->all.fire.frame_seven.addr = NULL;
	test->all.fire.frame_eight.img = NULL;
	test->all.fire.frame_eight.addr = NULL;
}

void	init_chimney_dresser(t_test *test)
{
	test->all.dresser_downleft.img = NULL;
	test->all.dresser_downleft.addr = NULL;
	test->all.dresser_downright.img = NULL;
	test->all.dresser_downright.addr = NULL;
	test->all.dresser_topleft.img = NULL;
	test->all.dresser_topleft.addr = NULL;
	test->all.dresser_topright.img = NULL;
	test->all.dresser_topright.addr = NULL;
	test->all.chimney.bottom_right.img = NULL;
	test->all.chimney.bottom_right.addr = NULL;
	test->all.chimney.bottom_left.img = NULL;
	test->all.chimney.bottom_left.addr = NULL;
	test->all.chimney.mid_right.img = NULL;
	test->all.chimney.mid_right.addr = NULL;
	test->all.chimney.mid_left.img = NULL;
	test->all.chimney.mid_left.addr = NULL;
	test->all.chimney.top_right.img = NULL;
	test->all.chimney.top_right.addr = NULL;
	test->all.chimney.top_left.img = NULL;
	test->all.chimney.top_left.addr = NULL;
}

void	init_collec_exit(t_test *test)
{
	test->collec.amount = 0;
	test->collec.count = 0;
	test->collec.exit = 0;
	test->collec.random = 0;
	test->collec.newspaper.img = NULL;
	test->collec.newspaper.addr = NULL;
	test->collec.wanted.img = NULL;
	test->collec.wanted.addr = NULL;
	test->all.exit.exit_half_left.img = NULL;
	test->all.exit.exit_half_left.addr = NULL;
	test->all.exit.exit_half_right.img = NULL;
	test->all.exit.exit_half_right.addr = NULL;
	test->all.exit.trapdoor_left.img = NULL;
	test->all.exit.trapdoor_left.addr = NULL;
	test->all.exit.trapdoor_right.img = NULL;
	test->all.exit.trapdoor_right.addr = NULL;
	test->all.exit.open_to_left.img = NULL;
	test->all.exit.open_to_left.addr = NULL;
	test->all.exit.open_to_right.img = NULL;
	test->all.exit.open_to_right.addr = NULL;
	test->all.exit.opened = 0;
}

void	init_all_remain(t_test *test)
{
	test->all.wall.img = NULL;
	test->all.wall.addr = NULL;
	test->all.floor.img = NULL;
	test->all.floor.addr = NULL;
	test->all.floor_half_left.img = NULL;
	test->all.floor_half_left.addr = NULL;
	test->all.floor_half_right.img = NULL;
	test->all.floor_half_right.addr = NULL;
	test->all.box.img = NULL;
	test->all.box.addr = NULL;
	test->all.pot.img = NULL;
	test->all.pot.addr = NULL;
	test->all.cardboard.img = NULL;
	test->all.cardboard.addr = NULL;
	test->all.babo = 0;
	test->all.ispiano = 0;
	test->all.random_obj = 0;
	test->all.babolex_painting.img = NULL;
	test->all.babolex_painting.addr = NULL;
	test->all.spike.img = NULL;
	test->all.spike.addr = NULL;
}
