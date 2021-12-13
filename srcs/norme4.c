/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:05:28 by esafar            #+#    #+#             */
/*   Updated: 2021/12/13 15:05:37 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	norme16(t_test *test)
{
	test->all.floor_half_left.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/floor_half_left.xpm", &test->all.\
		floor_half_left.x, &test->all.floor_half_left.y);
	test->all.floor_half_left.addr = mlx_get_data_addr \
		(test->all.floor_half_left.img, &test->all.floor_half_left.\
		bits_per_pixel, &test->all.floor_half_left.line_length, \
		&test->all.floor_half_left.endian);
	test->all.box.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/box.xpm", &test->all.box.x, \
		&test->all.box.y);
	test->all.box.addr = mlx_get_data_addr \
		(test->all.box.img, &test->all.box.bits_per_pixel, &test->all.\
		box.line_length, &test->all.box.endian);
	test->all.pot.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/pot.xpm", &test->all.pot.x, \
		&test->all.pot.y);
	test->all.pot.addr = mlx_get_data_addr \
		(test->all.pot.img, &test->all.pot.bits_per_pixel, &test->all.\
		pot.line_length, &test->all.pot.endian);
}

void	init_img1(t_test *test)
{
	test->stats.full_heart.img = mlx_xpm_file_to_image(test->mlx, \
		"textures/white_full_heart.xpm", &test->stats.full_heart.x, \
		&test->stats.full_heart.y);
	test->stats.full_heart.addr = mlx_get_data_addr(test->stats.full_heart.img, \
		&test->stats.full_heart.bits_per_pixel, \
		&test->stats.full_heart.line_length, &test->stats.full_heart.endian);
}
