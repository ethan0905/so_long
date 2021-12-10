/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_on_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 10:59:23 by esafar            #+#    #+#             */
/*   Updated: 2021/12/07 10:59:26 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_on_image(t_test *test, t_data *img, int startx, int starty)
{
	int	x;
	int	y;

	y = 0;
	while (y < 64)
	{
		test->tex.tex_y = (int)((double)y * test->tex.ratio_y);
		x = 0;
		while (x < 64)
		{
			test->tex.tex_x = (int)((double)x * test->tex.ratio_x);
			if (get_pixel(img, test->tex.tex_x, test->tex.tex_y)
				!= (int)0xFF000000)
				my_mlx_pixel_put(test, x + startx, y + starty, \
					get_pixel(img, test->tex.tex_x, test->tex.tex_y));
			x++;
		}
		y++;
	}
}

void	draw_on_image_bis(t_test *test, t_data *img, int startx, int starty)
{
	int	x;
	int	y;

	y = 0;
	while (y < 128)
	{
		test->tex.tex_y = (int)((double)y * test->tex.ratio_y);
		x = 0;
		while (x < 128)
		{
			test->tex.tex_x = (int)((double)x * test->tex.ratio_x);
			if (get_pixel(img, test->tex.tex_x, test->tex.tex_y)
				!= (int)0xFF000000)
				my_mlx_pixel_put(test, x + startx, y + starty, \
					get_pixel(img, test->tex.tex_x, test->tex.tex_y));
			x++;
		}
		y++;
	}
}

void	draw_on_image_intro(t_test *test, t_data *img, int startx, int starty)
{
	int	x;
	int	y;

	y = 0;
	while (y < 448)
	{
		test->tex.tex_y = (int)((double)y * test->tex.ratio_y);
		x = 0;
		while (x < 960)
		{
			test->tex.tex_x = (int)((double)x * test->tex.ratio_x);
			my_mlx_pixel_put(test, x + startx, y + starty, \
				get_pixel(img, test->tex.tex_x, test->tex.tex_y));
			x++;
		}
		y++;
	}
}
