/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_furnitures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:25:56 by esafar            #+#    #+#             */
/*   Updated: 2021/12/07 18:26:07 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

int	draw_piano(t_test *test, int piano, int x, int y)
{
	if (piano == 0)
	{
		draw_on_image(test, &test->all.piano.downleft, x, y - 26);
		draw_on_image(test, &test->all.piano.midleft, x, y - 64 - 26);
		draw_on_image(test, &test->all.piano.topleft, x + 9, y - 128 - 26);
		draw_on_image(test, &test->all.piano.downmid, x + 64, y - 26);
		draw_on_image(test, &test->all.piano.midmid, x + 64, y - 64 - 26);
		draw_on_image(test, &test->all.piano.topmid, x + 64, y - 128 - 26);
		draw_on_image(test, &test->all.piano.downright, x + 128, y - 26);
		draw_on_image(test, &test->all.piano.midright, x + 128, y - 64 - 26);
		draw_on_image(test, &test->all.piano.topright, x + 128, y - 128 - 26);
		piano++;
	}
	else
	{
		draw_on_image(test, &test->all.pot, x, y - 32);
		draw_on_image(test, &test->all.pot, x + 64, y - 32);
		draw_on_image(test, &test->all.pot, x + 128, y - 32);
	}
	return (piano);
}

void	draw_pot(t_test *test, int random_obj, int x, int y)
{
	if (random_obj == 0)
	{
		draw_on_image(test, &test->all.pot, x, y - 32);
		if (test->all.babo == 0)
		{
			draw_on_image(test, &test->all.babolex_painting, x + 32, y-128);
			test->all.babo = 1;
		}
	}
}

void draw_furnitures(t_test *test)
{
	int i;
	int j;
	int x;
	int y;
	int random_obj;
	int piano;

	i = 1;
	piano = 0;
	random_obj = 0;
	while (test->param.map[i + 1])
	{
		j = 1;
		while (test->param.map[i][j + 1])
		{
			x = (64 + (test->param.height - 2 - i)*64 + (j-1)*64);
			y = (192 + (i-1)*64);
			if (test->param.map[i][j] == '1' && i != 1)
				draw_on_image(test, &test->all.box, x, y);
			else if (test->param.map[i][j] == '1' && ((test->param.map[i][j - 1] == '0' || test->param.map[i][j - 1] == 'P') || (test->param.map[i][j - 1] == '1' && j - 1 == 0)) && ((test->param.map[i][j + 1] == '0' || test->param.map[i][j + 1] == 'P') || (test->param.map[i][j + 1] == '1' && j + 1 == test->param.width - 1)) && i == 1)
				draw_pot(test, random_obj, x, y);
			else if (test->param.map[i][j] == '1' && test->param.map[i][j + 1] == '1' && j + 1 != test->param.width - 1 && ((test->param.map[i][j - 1] == '0' || test->param.map[i][j - 1] == 'P') || (test->param.map[i][j - 1] == '1' && j - 1 == 0)) && ((test->param.map[i][j + 2] == '0' || test->param.map[i][j + 2] == 'P') || (test->param.map[i][j + 2] == '1' && j + 2 == test->param.width - 1)))
				random_obj = draw_chimney(test, random_obj, x, y);
			else if (test->param.map[i][j] == '1' && test->param.map[i][j + 1] == '1' && test->param.map[i][j + 2] == '1' && j + 1 != test->param.width - 1 && ((test->param.map[i][j - 1] == '0' || test->param.map[i][j - 1] == 'P') || (test->param.map[i][j - 1] == '1' && j - 1  == 0)) && ((test->param.map[i][j + 3] == '0' || test->param.map[i][j + 3] == 'P') || (test->param.map[i][j + 3] == '1' && j + 3 == test->param.width - 1)))
				piano = draw_piano(test, piano, x, y);
			else if (i == 1 && j != test->param.width - 4 && test->param.map[i][j] == '1' && test->param.map[i][j + 1] == '1' && test->param.map[i][j + 2] == '1' && test->param.map[i][j + 3] == '1')
			{
				draw_on_image(test, &test->all.pot, x, y - 32);
				draw_on_image(test, &test->all.pot, x + 64, y - 32);
				draw_on_image(test, &test->all.pot, x + 128, y - 32);
				draw_on_image(test, &test->all.pot, x + 192, y - 32);
			}
			j++;
		}
		i++;
	}
	test->all.babo = 0;
}