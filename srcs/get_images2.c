/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:25:18 by esafar            #+#    #+#             */
/*   Updated: 2021/12/07 16:25:21 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_chimney_and_dresser(t_test *test)
{
	test->all.chimney.bottom_right.img = mlx_xpm_file_to_image(test->mlx, "textures/chimney_br.xpm", &test->all.chimney.bottom_right.x, &test->all.chimney.bottom_right.y);
    test->all.chimney.bottom_right.addr = mlx_get_data_addr(test->all.chimney.bottom_right.img, &test->all.chimney.bottom_right.bits_per_pixel, &test->all.chimney.bottom_right.line_length, &test->all.chimney.bottom_right.endian);
	test->all.chimney.bottom_left.img = mlx_xpm_file_to_image(test->mlx, "textures/chimney_bl.xpm", &test->all.chimney.bottom_left.x, &test->all.chimney.bottom_left.y);
    test->all.chimney.bottom_left.addr = mlx_get_data_addr(test->all.chimney.bottom_left.img, &test->all.chimney.bottom_left.bits_per_pixel, &test->all.chimney.bottom_left.line_length, &test->all.chimney.bottom_left.endian);
	test->all.chimney.mid_right.img = mlx_xpm_file_to_image(test->mlx, "textures/chimney_mr.xpm", &test->all.chimney.mid_right.x, &test->all.chimney.mid_right.y);
    test->all.chimney.mid_right.addr = mlx_get_data_addr(test->all.chimney.mid_right.img, &test->all.chimney.mid_right.bits_per_pixel, &test->all.chimney.mid_right.line_length, &test->all.chimney.mid_right.endian);
	test->all.chimney.mid_left.img = mlx_xpm_file_to_image(test->mlx, "textures/chimney_ml.xpm", &test->all.chimney.mid_left.x, &test->all.chimney.mid_left.y);
    test->all.chimney.mid_left.addr = mlx_get_data_addr(test->all.chimney.mid_left.img, &test->all.chimney.mid_left.bits_per_pixel, &test->all.chimney.mid_left.line_length, &test->all.chimney.mid_left.endian);
	test->all.chimney.top_right.img = mlx_xpm_file_to_image(test->mlx, "textures/chimney_tr.xpm", &test->all.chimney.top_right.x, &test->all.chimney.top_right.y);
    test->all.chimney.top_right.addr = mlx_get_data_addr(test->all.chimney.top_right.img, &test->all.chimney.top_right.bits_per_pixel, &test->all.chimney.top_right.line_length, &test->all.chimney.top_right.endian);
	test->all.chimney.top_left.img = mlx_xpm_file_to_image(test->mlx, "textures/chimney_tl.xpm", &test->all.chimney.top_left.x, &test->all.chimney.top_left.y);
    test->all.chimney.top_left.addr = mlx_get_data_addr(test->all.chimney.top_left.img, &test->all.chimney.top_left.bits_per_pixel, &test->all.chimney.top_left.line_length, &test->all.chimney.top_left.endian);
	test->all.dresser_topright.img = mlx_xpm_file_to_image(test->mlx, "textures/dresser3_topright.xpm", &test->all.dresser_topright.x, &test->all.dresser_topright.y);
    test->all.dresser_topright.addr = mlx_get_data_addr(test->all.dresser_topright.img, &test->all.dresser_topright.bits_per_pixel, &test->all.dresser_topright.line_length, &test->all.dresser_topright.endian);
    test->all.dresser_topleft.img = mlx_xpm_file_to_image(test->mlx, "textures/dresser3_topleft.xpm", &test->all.dresser_topleft.x, &test->all.dresser_topleft.y);
    test->all.dresser_topleft.addr = mlx_get_data_addr(test->all.dresser_topleft.img, &test->all.dresser_topleft.bits_per_pixel, &test->all.dresser_topleft.line_length, &test->all.dresser_topleft.endian);
    test->all.dresser_downright.img = mlx_xpm_file_to_image(test->mlx, "textures/dresser3_downright.xpm", &test->all.dresser_downright.x, &test->all.dresser_downright.y);
    test->all.dresser_downright.addr = mlx_get_data_addr(test->all.dresser_downright.img, &test->all.dresser_downright.bits_per_pixel, &test->all.dresser_downright.line_length, &test->all.dresser_downright.endian);
    test->all.dresser_downleft.img = mlx_xpm_file_to_image(test->mlx, "textures/dresser3_downleft.xpm", &test->all.dresser_downleft.x, &test->all.dresser_downleft.y);
    test->all.dresser_downleft.addr = mlx_get_data_addr(test->all.dresser_downleft.img, &test->all.dresser_downleft.bits_per_pixel, &test->all.dresser_downleft.line_length, &test->all.dresser_downleft.endian);
}

void	get_collec(t_test *test)
{
	test->collec.newspaper.img = mlx_xpm_file_to_image(test->mlx, "textures/newspaper.xpm", &test->collec.newspaper.x, &test->collec.newspaper.y);
    test->collec.newspaper.addr = mlx_get_data_addr(test->collec.newspaper.img, &test->collec.newspaper.bits_per_pixel, &test->collec.newspaper.line_length, &test->collec.newspaper.endian);
	test->collec.wanted.img = mlx_xpm_file_to_image(test->mlx, "textures/wanted.xpm", &test->collec.wanted.x, &test->collec.wanted.y);
    test->collec.wanted.addr = mlx_get_data_addr(test->collec.wanted.img, &test->collec.wanted.bits_per_pixel, &test->collec.wanted.line_length, &test->collec.wanted.endian);
	test->collec.murder_article.img = mlx_xpm_file_to_image(test->mlx, "textures/murder_article.xpm", &test->collec.murder_article.x, &test->collec.murder_article.y);
    test->collec.murder_article.addr = mlx_get_data_addr(test->collec.murder_article.img, &test->collec.murder_article.bits_per_pixel, &test->collec.murder_article.line_length, &test->collec.murder_article.endian);
}

void	get_piano(t_test *test)
{
	test->all.piano.topright.img = mlx_xpm_file_to_image(test->mlx, "textures/piano_topright.xpm", &test->all.piano.topright.x, &test->all.piano.topright.y);
    test->all.piano.topright.addr = mlx_get_data_addr(test->all.piano.topright.img, &test->all.piano.topright.bits_per_pixel, &test->all.piano.topright.line_length, &test->all.piano.topright.endian);
    test->all.piano.topmid.img = mlx_xpm_file_to_image(test->mlx, "textures/piano_topmid.xpm", &test->all.piano.topmid.x, &test->all.piano.topmid.y);
    test->all.piano.topmid.addr = mlx_get_data_addr(test->all.piano.topmid.img, &test->all.piano.topmid.bits_per_pixel, &test->all.piano.topmid.line_length, &test->all.piano.topmid.endian);
    test->all.piano.topleft.img = mlx_xpm_file_to_image(test->mlx, "textures/piano_topleft.xpm", &test->all.piano.topleft.x, &test->all.piano.topleft.y);
    test->all.piano.topleft.addr = mlx_get_data_addr(test->all.piano.topleft.img, &test->all.piano.topleft.bits_per_pixel, &test->all.piano.topleft.line_length, &test->all.piano.topleft.endian);
	test->all.piano.midright.img = mlx_xpm_file_to_image(test->mlx, "textures/piano_midright.xpm", &test->all.piano.midright.x, &test->all.piano.midright.y);
    test->all.piano.midright.addr = mlx_get_data_addr(test->all.piano.midright.img, &test->all.piano.midright.bits_per_pixel, &test->all.piano.midright.line_length, &test->all.piano.midright.endian);
    test->all.piano.midmid.img = mlx_xpm_file_to_image(test->mlx, "textures/piano_midmid.xpm", &test->all.piano.midmid.x, &test->all.piano.midmid.y);
    test->all.piano.midmid.addr = mlx_get_data_addr(test->all.piano.midmid.img, &test->all.piano.midmid.bits_per_pixel, &test->all.piano.midmid.line_length, &test->all.piano.midmid.endian);
    test->all.piano.midleft.img = mlx_xpm_file_to_image(test->mlx, "textures/piano_midleft.xpm", &test->all.piano.midleft.x, &test->all.piano.midleft.y);
    test->all.piano.midleft.addr = mlx_get_data_addr(test->all.piano.midleft.img, &test->all.piano.midleft.bits_per_pixel, &test->all.piano.midleft.line_length, &test->all.piano.midleft.endian);
	test->all.piano.downright.img = mlx_xpm_file_to_image(test->mlx, "textures/piano_downright.xpm", &test->all.piano.downright.x, &test->all.piano.downright.y);
    test->all.piano.downright.addr = mlx_get_data_addr(test->all.piano.downright.img, &test->all.piano.downright.bits_per_pixel, &test->all.piano.downright.line_length, &test->all.piano.downright.endian);
    test->all.piano.downmid.img = mlx_xpm_file_to_image(test->mlx, "textures/piano_downmid.xpm", &test->all.piano.downmid.x, &test->all.piano.downmid.y);
    test->all.piano.downmid.addr = mlx_get_data_addr(test->all.piano.downmid.img, &test->all.piano.downmid.bits_per_pixel, &test->all.piano.downmid.line_length, &test->all.piano.downmid.endian);
    test->all.piano.downleft.img = mlx_xpm_file_to_image(test->mlx, "textures/piano_downleft.xpm", &test->all.piano.downleft.x, &test->all.piano.downleft.y);
    test->all.piano.downleft.addr = mlx_get_data_addr(test->all.piano.downleft.img, &test->all.piano.downleft.bits_per_pixel, &test->all.piano.downleft.line_length, &test->all.piano.downleft.endian);
}

void	get_remain(t_test *test)
{
	test->all.wall.img = mlx_xpm_file_to_image(test->mlx, "textures/wall.xpm", &test->all.wall.x, &test->all.wall.y);
    test->all.wall.addr = mlx_get_data_addr(test->all.wall.img, &test->all.wall.bits_per_pixel, &test->all.wall.line_length, &test->all.wall.endian);
    test->all.floor.img = mlx_xpm_file_to_image(test->mlx, "textures/floor.xpm", &test->all.floor.x, &test->all.floor.y);
    test->all.floor.addr = mlx_get_data_addr(test->all.floor.img, &test->all.floor.bits_per_pixel, &test->all.floor.line_length, &test->all.floor.endian);
    test->all.floor_half_right.img = mlx_xpm_file_to_image(test->mlx, "textures/floor_half_right.xpm", &test->all.floor_half_right.x, &test->all.floor_half_right.y);
    test->all.floor_half_right.addr = mlx_get_data_addr(test->all.floor_half_right.img, &test->all.floor_half_right.bits_per_pixel, &test->all.floor_half_right.line_length, &test->all.floor_half_right.endian);
    test->all.floor_half_left.img = mlx_xpm_file_to_image(test->mlx, "textures/floor_half_left.xpm", &test->all.floor_half_left.x, &test->all.floor_half_left.y);
    test->all.floor_half_left.addr = mlx_get_data_addr(test->all.floor_half_left.img, &test->all.floor_half_left.bits_per_pixel, &test->all.floor_half_left.line_length, &test->all.floor_half_left.endian);
    test->all.box.img = mlx_xpm_file_to_image(test->mlx, "textures/box.xpm", &test->all.box.x, &test->all.box.y);
    test->all.box.addr = mlx_get_data_addr(test->all.box.img, &test->all.box.bits_per_pixel, &test->all.box.line_length, &test->all.box.endian);
    test->all.pot.img = mlx_xpm_file_to_image(test->mlx, "textures/pot.xpm", &test->all.pot.x, &test->all.pot.y);
    test->all.pot.addr = mlx_get_data_addr(test->all.pot.img, &test->all.pot.bits_per_pixel, &test->all.pot.line_length, &test->all.pot.endian);
    test->all.cardboard.img = mlx_xpm_file_to_image(test->mlx, "textures/cardboard.xpm", &test->all.cardboard.x, &test->all.cardboard.y);
    test->all.cardboard.addr = mlx_get_data_addr(test->all.cardboard.img, &test->all.cardboard.bits_per_pixel, &test->all.cardboard.line_length, &test->all.cardboard.endian);
    test->all.babolex_painting.img = mlx_xpm_file_to_image(test->mlx, "textures/babolex_painting2.xpm", &test->all.babolex_painting.x, &test->all.babolex_painting.y);
    test->all.babolex_painting.addr = mlx_get_data_addr(test->all.babolex_painting.img, &test->all.babolex_painting.bits_per_pixel, &test->all.babolex_painting.line_length, &test->all.babolex_painting.endian);
	test->all.spike.img = mlx_xpm_file_to_image(test->mlx, "textures/spike.xpm", &test->all.spike.x, &test->all.spike.y);
    test->all.spike.addr = mlx_get_data_addr(test->all.spike.img, &test->all.spike.bits_per_pixel, &test->all.spike.line_length, &test->all.spike.endian);
}
