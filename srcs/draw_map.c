/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:03:46 by esafar            #+#    #+#             */
/*   Updated: 2021/12/07 11:03:58 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_background(t_test *test)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < (test->param.height - 2) * 64 + 3 * 64)
	{
		x = 0;
		while (x < test->param.width_with_x * 64 - (2 * 64))
		{
			my_mlx_pixel_put(test, x, y, 0xFF000000);
			x++;
		}
		y++;
	}
}

void	draw_walls(t_test *test)
{
	int	y;
	int	x;

	y = 0;
	while (y < 3)
	{
		x = test->param.width_with_x - test->param.width - 1;
		while (x < test->param.width_with_x - 2)
		{
			draw_on_image(test, &test->all.wall, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	draw_floors(t_test *test)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	count = 0;
	while (y < test->param.height - 2)
	{
		x = test->param.width_with_x - test->param.width - count - 1 - 1;
		while (x < test->param.width_with_x - 2 - count)
		{
			if (x == test->param.width_with_x - test->param.width
				- count - 1 - 1)
				draw_on_image(test, &test->all.floor_half_right, x
					* 64, 3 * 64 + y * 64);
			else if (x == test->param.width_with_x - 2 - count - 1)
				draw_on_image(test, &test->all.floor_half_left, x
					* 64, 3 * 64 + y * 64);
			else
				draw_on_image(test, &test->all.floor, x * 64, 3 * 64 + y * 64);
			x++;
		}
		count++;
		y++;
	}
}
