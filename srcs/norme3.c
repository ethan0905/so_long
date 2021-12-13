/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:04:04 by esafar            #+#    #+#             */
/*   Updated: 2021/12/13 15:04:16 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	norme11(t_test *test)
{
	test->all.chimney.mid_left.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/chimney_ml.xpm", &test->all.chimney.mid_left.x, \
		&test->all.chimney.mid_left.y);
	test->all.chimney.mid_left.addr = mlx_get_data_addr \
		(test->all.chimney.mid_left.img, &test->all.chimney.mid_left.\
		bits_per_pixel, &test->all.chimney.mid_left.line_length, \
		&test->all.chimney.mid_left.endian);
	test->all.chimney.top_right.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/chimney_tr.xpm", &test->all.chimney.top_right.\
		x, &test->all.chimney.top_right.y);
	test->all.chimney.top_right.addr = mlx_get_data_addr \
		(test->all.chimney.top_right.img, &test->all.chimney.top_right.\
		bits_per_pixel, &test->all.chimney.top_right.line_length, \
		&test->all.chimney.top_right.endian);
	test->all.chimney.top_left.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/chimney_tl.xpm", &test->all.chimney.\
		top_left.x, &test->all.chimney.top_left.y);
	test->all.chimney.top_left.addr = mlx_get_data_addr \
		(test->all.chimney.top_left.img, &test->all.chimney.top_left.\
		bits_per_pixel, &test->all.chimney.top_left.line_length, \
		&test->all.chimney.top_left.endian);
}

void	norme12(t_test *test)
{
	test->all.dresser_topright.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/dresser3_topright.xpm", &test->all.\
		dresser_topright.x, &test->all.dresser_topright.y);
	test->all.dresser_topright.addr = mlx_get_data_addr \
		(test->all.dresser_topright.img, &test->all.dresser_topright.\
		bits_per_pixel, &test->all.dresser_topright.line_length, \
		&test->all.dresser_topright.endian);
	test->all.dresser_topleft.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/dresser3_topleft.xpm", &test->all.\
		dresser_topleft.x, &test->all.dresser_topleft.y);
	test->all.dresser_topleft.addr = mlx_get_data_addr \
		(test->all.dresser_topleft.img, &test->all.dresser_topleft.\
		bits_per_pixel, &test->all.dresser_topleft.line_length, \
		&test->all.dresser_topleft.endian);
	test->all.dresser_downright.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/dresser3_downright.xpm", &test->all.\
		dresser_downright.x, &test->all.dresser_downright.y);
	test->all.dresser_downright.addr = mlx_get_data_addr \
		(test->all.dresser_downright.img, &test->all.dresser_downright.\
		bits_per_pixel, &test->all.dresser_downright.line_length, \
		&test->all.dresser_downright.endian);
}

void	norme13(t_test *test)
{
	test->all.piano.topright.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/piano_topright.xpm", &test->all.piano.topright.x, \
		&test->all.piano.topright.y);
	test->all.piano.topright.addr = mlx_get_data_addr \
		(test->all.piano.topright.img, &test->all.piano.topright.\
		bits_per_pixel, &test->all.piano.topright.line_length, \
		&test->all.piano.topright.endian);
	test->all.piano.topmid.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/piano_topmid.xpm", &test->all.piano.topmid.x, \
		&test->all.piano.topmid.y);
	test->all.piano.topmid.addr = mlx_get_data_addr \
		(test->all.piano.topmid.img, &test->all.piano.topmid.bits_per_pixel, \
		&test->all.piano.topmid.line_length, &test->all.piano.topmid.endian);
	test->all.piano.topleft.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/piano_topleft.xpm", &test->all.piano.topleft.x, \
		&test->all.piano.topleft.y);
	test->all.piano.topleft.addr = mlx_get_data_addr \
		(test->all.piano.topleft.img, &test->all.piano.topleft.bits_per_pixel, \
		&test->all.piano.topleft.line_length, &test->all.piano.topleft.endian);
}

void	norme14(t_test *test)
{
	test->all.piano.midright.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/piano_midright.xpm", &test->all.piano.midright.x, \
		&test->all.piano.midright.y);
	test->all.piano.midright.addr = mlx_get_data_addr \
		(test->all.piano.midright.img, &test->all.piano.midright.\
		bits_per_pixel, &test->all.piano.midright.line_length, \
		&test->all.piano.midright.endian);
	test->all.piano.midmid.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/piano_midmid.xpm", &test->all.piano.midmid.x, \
		&test->all.piano.midmid.y);
	test->all.piano.midmid.addr = mlx_get_data_addr \
		(test->all.piano.midmid.img, &test->all.piano.midmid.bits_per_pixel, \
		&test->all.piano.midmid.line_length, &test->all.piano.midmid.endian);
	test->all.piano.midleft.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/piano_midleft.xpm", &test->all.piano.midleft.x, \
		&test->all.piano.midleft.y);
	test->all.piano.midleft.addr = mlx_get_data_addr \
		(test->all.piano.midleft.img, &test->all.piano.midleft.bits_per_pixel, \
		&test->all.piano.midleft.line_length, &test->all.piano.midleft.endian);
}

void	norme15(t_test *test)
{
	test->all.wall.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/wall.xpm", &test->all.wall.x, \
		&test->all.wall.y);
	test->all.wall.addr = mlx_get_data_addr \
		(test->all.wall.img, &test->all.wall.bits_per_pixel, &test->all.wall.\
		line_length, &test->all.wall.endian);
	test->all.floor.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/floor.xpm", &test->all.floor.x, \
		&test->all.floor.y);
	test->all.floor.addr = mlx_get_data_addr \
		(test->all.floor.img, &test->all.floor.bits_per_pixel, &test->all.\
		floor.line_length, &test->all.floor.endian);
	test->all.floor_half_right.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/floor_half_right.xpm", &test->all.\
		floor_half_right.x, &test->all.floor_half_right.y);
	test->all.floor_half_right.addr = mlx_get_data_addr \
		(test->all.floor_half_right.img, &test->all.floor_half_right.\
		bits_per_pixel, &test->all.floor_half_right.line_length, \
		&test->all.floor_half_right.endian);
}
