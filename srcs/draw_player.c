/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:21:10 by esafar            #+#    #+#             */
/*   Updated: 2022/12/14 14:44:51 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_pos_player(t_test *test)
{
	int	i;
	int	j;

	i = 0;
	while (test->param.map[i])
	{
		j = 0;
		while (test->param.map[i][j])
		{
			if (test->param.map[i][j] == 'P')
			{
				test->player.pos_i = i;
				test->player.pos_j = j;
				test->player.pos_x = (j - 1) * 64 + 30 + (test->param.height - 3) * 64 - (i - 1) * 64;
				test->player.pos_y = 3 * 64 + (i - 1) * 64 - 64 - 25 + 10;
			}
			else if (test->param.map[i][j] == 'C' && test->param.rendered == 0)
				test->collec.amount++;
			j++;
		}	
		i++;
	}
}

void	choose_which_damage_side(t_test *test)
{
	if (test->param.map[test->player.pos_i + 1][test->player.pos_j] == 'T')
		test->player.side = &test->player.dmg_front;
	else if (test->param.map[test->player.pos_i - 1][test->player.pos_j]
		== 'T')
		test->player.side = &test->player.dmg_back;
	else if (test->param.map[test->player.pos_i][test->player.pos_j - 1]
		== 'T')
		test->player.side = &test->player.dmg_left;
	else if (test->param.map[test->player.pos_i][test->player.pos_j + 1]
		== 'T')
		test->player.side = &test->player.dmg_right;
}

void	choose_which_normal_side(t_test *test)
{
	if (test->param.map[test->player.pos_i + 1][test->player.pos_j] == 'T')
		test->player.side = &test->player.frontside;
	else if (test->param.map[test->player.pos_i - 1][test->player.pos_j]
		== 'T')
		test->player.side = &test->player.backside;
	else if (test->param.map[test->player.pos_i][test->player.pos_j - 1]
		== 'T')
		test->player.side = &test->player.leftside;
	else if (test->param.map[test->player.pos_i][test->player.pos_j + 1]
		== 'T')
		test->player.side = &test->player.rightside;
}

void	choose_player_image(t_test *test)
{
	if (test->frame < 17)
		choose_which_damage_side(test);
	else if (test->frame >= 17)
		choose_which_normal_side(test);
}

void	draw_player(t_test *test)
{
	get_pos_player(test);
	if (test->player.hurt == 1)
	{
		test->player.lock_pos = 1;
		choose_player_image(test);
		if (test->frame == 31)
			test->loop++;
		if (test->loop == 4)
		{
			test->player.hurt = 0;
			test->loop = 0;
			test->player.lock_pos = 0;
			test->player.side = &test->player.frontside;
		}
		draw_on_image_bis(test, test->player.side, test->player.pos_x, test->player.pos_y);
	}
	else if (test->player.hurt == 0)
		draw_on_image_bis(test, test->player.side, test->player.pos_x, test->player.pos_y);
}
