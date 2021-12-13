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
	norme10(test);
	norme11(test);
	norme12(test);
	test->all.dresser_downleft.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/dresser3_downleft.xpm", &test->all.\
		dresser_downleft.x, &test->all.dresser_downleft.y);
	test->all.dresser_downleft.addr = mlx_get_data_addr \
		(test->all.dresser_downleft.img, &test->all.dresser_downleft.\
		bits_per_pixel, &test->all.dresser_downleft.line_length, \
		&test->all.dresser_downleft.endian);
}

void	get_collec(t_test *test)
{
	test->collec.newspaper.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/newspaper.xpm", &test->collec.newspaper.x, \
		&test->collec.newspaper.y);
	test->collec.newspaper.addr = mlx_get_data_addr \
		(test->collec.newspaper.img, &test->collec.newspaper.bits_per_pixel, \
		&test->collec.newspaper.line_length, &test->collec.newspaper.endian);
	test->collec.wanted.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/wanted.xpm", &test->collec.wanted.x, \
		&test->collec.wanted.y);
	test->collec.wanted.addr = mlx_get_data_addr \
		(test->collec.wanted.img, &test->collec.wanted.bits_per_pixel, \
		&test->collec.wanted.line_length, &test->collec.wanted.endian);
	test->collec.murder_article.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/murder_article.xpm", &test->collec.murder_article.\
		x, &test->collec.murder_article.y);
	test->collec.murder_article.addr = mlx_get_data_addr \
		(test->collec.murder_article.img, &test->collec.murder_article.\
		bits_per_pixel, &test->collec.murder_article.line_length, \
		&test->collec.murder_article.endian);
}

void	get_piano(t_test *test)
{
	norme13(test);
	norme14(test);
	test->all.piano.downright.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/piano_downright.xpm", &test->all.piano.\
		downright.x, &test->all.piano.downright.y);
	test->all.piano.downright.addr = mlx_get_data_addr \
		(test->all.piano.downright.img, &test->all.piano.downright.\
		bits_per_pixel, &test->all.piano.downright.line_length, \
		&test->all.piano.downright.endian);
	test->all.piano.downmid.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/piano_downmid.xpm", &test->all.piano.downmid.x, \
		&test->all.piano.downmid.y);
	test->all.piano.downmid.addr = mlx_get_data_addr \
		(test->all.piano.downmid.img, &test->all.piano.downmid.\
		bits_per_pixel, &test->all.piano.downmid.line_length, \
		&test->all.piano.downmid.endian);
	test->all.piano.downleft.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/piano_downleft.xpm", &test->all.piano.\
		downleft.x, &test->all.piano.downleft.y);
	test->all.piano.downleft.addr = mlx_get_data_addr \
		(test->all.piano.downleft.img, &test->all.piano.downleft.\
		bits_per_pixel, &test->all.piano.downleft.line_length, \
		&test->all.piano.downleft.endian);
}

void	get_remain(t_test *test)
{
	norme15(test);
	norme16(test);
	test->all.cardboard.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/cardboard.xpm", &test->all.cardboard.\
		x, &test->all.cardboard.y);
	test->all.cardboard.addr = mlx_get_data_addr \
		(test->all.cardboard.img, &test->all.cardboard.bits_per_pixel, \
		&test->all.cardboard.line_length, &test->all.cardboard.endian);
	test->all.babolex_painting.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/babolex_painting2.xpm", &test->all.\
		babolex_painting.x, &test->all.babolex_painting.y);
	test->all.babolex_painting.addr = mlx_get_data_addr \
		(test->all.babolex_painting.img, &test->all.babolex_painting.\
		bits_per_pixel, &test->all.babolex_painting.line_length, \
		&test->all.babolex_painting.endian);
	test->all.spike.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/spike.xpm", &test->all.spike.x, \
		&test->all.spike.y);
	test->all.spike.addr = mlx_get_data_addr \
		(test->all.spike.img, &test->all.spike.bits_per_pixel, &test->all.\
		spike.line_length, &test->all.spike.endian);
}
