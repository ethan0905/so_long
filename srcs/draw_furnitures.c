/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_furnitures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:07:14 by esafar            #+#    #+#             */
/*   Updated: 2021/12/07 20:07:24 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_flames(t_test *test, int x, int y)
{
	draw_on_image(test, test->all.fire.frame, x, y);
}

void	draw_dresser(t_test *test, int x, int y)
{
	draw_on_image(test, &test->all.dresser_downleft, x, y - 24);
	draw_on_image(test, &test->all.dresser_downright, x + 64, y - 24);
	draw_on_image(test, &test->all.dresser_topleft, x, y - 64 - 24);
	draw_on_image(test, &test->all.dresser_topright, x + 64, y - 64 - 24);
}

int		draw_chimney(t_test *test, int random_obj, int x, int y)
{
	if (random_obj == 0)
	{
		draw_on_image(test, &test->all.chimney.bottom_left, x, y - 32 - 16 + 8);
		draw_on_image(test, &test->all.chimney.bottom_right, x + 64, y - 32 - 16 + 8);
		draw_on_image(test, &test->all.chimney.mid_left, x, y - 32 - 16 - 64 + 8);
		draw_on_image(test, &test->all.chimney.mid_right, x + 64, y - 32 - 16 - 64 + 8);
		draw_on_image(test, &test->all.chimney.top_left, x, y - 32 - 16 - 128 + 8);
		draw_on_image(test, &test->all.chimney.top_right, x + 64, y - 32 - 16 - 128 + 8);
		if (test->frame < 8)
			test->all.fire.frame = &test->all.fire.frame_one;
		else if (test->frame < 16 && test->frame >= 8)
			test->all.fire.frame = &test->all.fire.frame_three;
		else if (test->frame < 24 && test->frame >= 16)
			test->all.fire.frame = &test->all.fire.frame_five;
		else if (test->frame >= 24)
			test->all.fire.frame = &test->all.fire.frame_seven;
		draw_flames(test, x + 16, y - 51);
		random_obj = 1;
	}
	else if (random_obj == 1)
		draw_dresser(test, x, y);
	return (random_obj);
}

void draw_furnitures(t_test *test)
{
	test->iter.i = 0;
	while (test->param.map[++test->iter.i + 1])
	{
		test->iter.j = 0;
		while (test->param.map[test->iter.i][++test->iter.j + 1])
		{
			test->iter.x = (64 + (test->param.height - 2 - test->iter.i)*64 + (test->iter.j-1)*64);
			test->iter.y = (192 + (test->iter.i-1)*64);
			if (test->param.map[test->iter.i][test->iter.j] == '1' && test->iter.i != 1)
				draw_on_image(test, &test->all.box, test->iter.x, test->iter.y);
			else if (test->param.map[test->iter.i][test->iter.j] == '1' && ((test->param.map[test->iter.i][test->iter.j - 1] == '0' || test->param.map[test->iter.i][test->iter.j - 1] == 'P') || (test->param.map[test->iter.i][test->iter.j - 1] == '1' && test->iter.j - 1 == 0)) && ((test->param.map[test->iter.i][test->iter.j + 1] == '0' || test->param.map[test->iter.i][test->iter.j + 1] == 'P') || (test->param.map[test->iter.i][test->iter.j + 1] == '1' && test->iter.j + 1 == test->param.width - 1)) && test->iter.i == 1)
				draw_pot(test, test->all.random_obj, test->iter.x, test->iter.y);
			else if (test->param.map[test->iter.i][test->iter.j] == '1' && test->param.map[test->iter.i][test->iter.j + 1] == '1' && test->iter.j + 1 != test->param.width - 1 && ((test->param.map[test->iter.i][test->iter.j - 1] == '0' || test->param.map[test->iter.i][test->iter.j - 1] == 'P') || (test->param.map[test->iter.i][test->iter.j - 1] == '1' && test->iter.j - 1 == 0)) && ((test->param.map[test->iter.i][test->iter.j + 2] == '0' || test->param.map[test->iter.i][test->iter.j + 2] == 'P') || (test->param.map[test->iter.i][test->iter.j + 2] == '1' && test->iter.j + 2 == test->param.width - 1)))
				test->all.random_obj = draw_chimney(test, test->all.random_obj, test->iter.x, test->iter.y);
			else if (test->param.map[test->iter.i][test->iter.j] == '1' && test->param.map[test->iter.i][test->iter.j + 1] == '1' && test->param.map[test->iter.i][test->iter.j + 2] == '1' && test->iter.j + 1 != test->param.width - 1 && ((test->param.map[test->iter.i][test->iter.j - 1] == '0' || test->param.map[test->iter.i][test->iter.j - 1] == 'P') || (test->param.map[test->iter.i][test->iter.j - 1] == '1' && test->iter.j - 1  == 0)) && ((test->param.map[test->iter.i][test->iter.j + 3] == '0' || test->param.map[test->iter.i][test->iter.j + 3] == 'P') || (test->param.map[test->iter.i][test->iter.j + 3] == '1' && test->iter.j + 3 == test->param.width - 1)))
				test->all.ispiano = draw_piano(test, test->all.ispiano, test->iter.x, test->iter.y);
			else if (test->iter.i == 1 && test->iter.j != test->param.width - 4 && test->param.map[test->iter.i][test->iter.j] == '1' && test->param.map[test->iter.i][test->iter.j + 1] == '1' && test->param.map[test->iter.i][test->iter.j + 2] == '1' && test->param.map[test->iter.i][test->iter.j + 3] == '1')
				four_pot_line(test, test->iter.x, test->iter.y);
		}
	}
	test->all.babo = 0;
	test->all.ispiano = 0;
	test->all.random_obj = 0;
}