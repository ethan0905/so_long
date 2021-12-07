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
	int tex_x = 0;
	int tex_y = 0;
	int	x, y = 0;
	double ratio_x;
	double ratio_y;

	ratio_x = 1.0f;
	ratio_y = 1.0f;
	while (y < 64)
	{
		tex_y = (int)((double)y * ratio_y);
		x = 0;
		while (x < 64)
		{
			tex_x = (int)((double)x * ratio_x);
			if (get_pixel(img, tex_x, tex_y) != (int)0xFF000000)
				my_mlx_pixel_put(test, x + startx, y + starty, get_pixel(img, tex_x, tex_y));
			x++;
		}
		y++;
	}
}

void	draw_on_image_bis(t_test *test, t_data *img, int startx, int starty)
{
	int tex_x = 0;
	int tex_y = 0;
	int	x, y = 0;
	double ratio_x;
	double ratio_y;

	ratio_x = 1.0f;
	ratio_y = 1.0f;
	while (y < 128)
	{
		tex_y = (int)((double)y * ratio_y);
		x = 0;
		while (x < 128)
		{
			tex_x = (int)((double)x * ratio_x);
			if (get_pixel(img, tex_x, tex_y) != (int)0xFF000000)
				my_mlx_pixel_put(test, x + startx, y + starty, get_pixel(img, tex_x, tex_y));
			x++;
		}
		y++;
	}
}

void	draw_on_image_intro(t_test *test, t_data *img, int startx, int starty)
{
	int tex_x = 0;
	int tex_y = 0;
	int	x, y = 0;
	double ratio_x;
	double ratio_y;

	ratio_x = 1.0f;
	ratio_y = 1.0f;
	while (y < 448)
	{
		tex_y = (int)((double)y * ratio_y);
		x = 0;
		while (x < 960)
		{
			tex_x = (int)((double)x * ratio_x);
			my_mlx_pixel_put(test, x + startx, y + starty, get_pixel(img, tex_x, tex_y));
			x++;
		}
		y++;
	}
}