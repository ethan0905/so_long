/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_furnitures2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:11:24 by esafar            #+#    #+#             */
/*   Updated: 2021/12/07 20:11:37 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

void	four_pot_line(t_test *test, int x, int y)
{
	draw_on_image(test, &test->all.pot, x, y - 32);
	draw_on_image(test, &test->all.pot, x + 64, y - 32);	
	draw_on_image(test, &test->all.pot, x + 128, y - 32);
	draw_on_image(test, &test->all.pot, x + 192, y - 32);
}