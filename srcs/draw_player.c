/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:21:10 by esafar            #+#    #+#             */
/*   Updated: 2021/12/07 19:21:23 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_pos_player(t_test *test)
{
	int i;
	int j;

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
				//(j-1)*64 + 12 -> set the position according to the j value in the tab. (+12 is only for more logical player positioning)
				//+(test.data.height - 3) * 64 -> allow you to adjust the player on the x axis depending on the height of the map (every + 1 will need to add 64px to pos_x)
				//-(i-1)*64 -> allow you to adjust the player depending of the y value the player spawn (every +1 will need to remove 64px to print the player closer to the left border) 
				test->player.pos_x = (j-1)*64 + 30 + (test->param.height - 3) * 64 - (i-1)*64; 
				test->player.pos_y = 3 * 64 + (i-1) * 64 - 64 - 25 + 10;
			}
			else if (test->param.map[i][j] == 'C' && test->param.rendered == 0)
				test->collec.amount++;
			j++;
		}	
		i++;
	}
}

void	choose_player_image(t_test *test)
{
	if (test->frame < 17)
	{
		if (test->param.map[test->player.pos_i + 1][test->player.pos_j] == 'T')
		   	test->player.side = &test->player.dmg_front;
		else if (test->param.map[test->player.pos_i - 1][test->player.pos_j] == 'T')
		   	test->player.side = &test->player.dmg_back;
		else if (test->param.map[test->player.pos_i][test->player.pos_j - 1] == 'T')
		   	test->player.side = &test->player.dmg_left;
		else if (test->param.map[test->player.pos_i][test->player.pos_j + 1] == 'T')
		   	test->player.side = &test->player.dmg_right;
	}
	else if (test->frame >= 17)
	{
		if (test->param.map[test->player.pos_i + 1][test->player.pos_j] == 'T')
		   	test->player.side = &test->player.frontside;
		else if (test->param.map[test->player.pos_i - 1][test->player.pos_j] == 'T')
		   	test->player.side = &test->player.backside;
		else if (test->param.map[test->player.pos_i][test->player.pos_j - 1] == 'T')
		   	test->player.side = &test->player.leftside;
		else if (test->param.map[test->player.pos_i][test->player.pos_j + 1] == 'T')
		   	test->player.side = &test->player.rightside;
	}
}

void draw_player(t_test *test)
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