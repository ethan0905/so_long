/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:00:37 by esafar            #+#    #+#             */
/*   Updated: 2021/12/13 15:00:51 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	norme6(t_test *test)
{
	test->stats.empty_heart.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/white_empty_heart.xpm", &test->stats.empty_heart.\
		x, &test->stats.empty_heart.y);
	test->stats.empty_heart.addr = mlx_get_data_addr \
		(test->stats.empty_heart.img, &test->stats.empty_heart.bits_per_pixel, \
		&test->stats.empty_heart.line_length, &test->stats.empty_heart.endian);
	test->stats.typeface_life.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/typeface_life_2.xpm", &test->stats.typeface_life.\
		x, &test->stats.typeface_life.y);
	test->stats.typeface_life.addr = mlx_get_data_addr \
		(test->stats.typeface_life.img, &test->stats.typeface_life.\
		bits_per_pixel, &test->stats.typeface_life.line_length, \
		&test->stats.typeface_life.endian);
}

void	norme7(t_test *test)
{
	test->all.exit.exit_half_left.img = mlx_xpm_file_to_image(test->mlx, \
		"textures/CUT_ladder.xpm", &test->all.exit.exit_half_left.x, \
		&test->all.exit.exit_half_left.y);
	test->all.exit.exit_half_left.addr = mlx_get_data_addr \
		(test->all.exit.exit_half_left.img, &test->all.exit.exit_half_left.\
		bits_per_pixel, &test->all.exit.exit_half_left.line_length, \
		&test->all.exit.exit_half_left.endian);
	test->all.exit.exit_half_right.img = mlx_xpm_file_to_image(test->mlx, \
		"textures/CUT_ladder_right.xpm", &test->all.exit.exit_half_right.x, \
		&test->all.exit.exit_half_right.y);
	test->all.exit.exit_half_right.addr = mlx_get_data_addr \
		(test->all.exit.exit_half_right.img, &test->all.exit.exit_half_right.\
		bits_per_pixel, &test->all.exit.exit_half_right.line_length, \
		&test->all.exit.exit_half_right.endian);
	test->all.exit.trapdoor_right.img = mlx_xpm_file_to_image(test->mlx, \
		"textures/FINAL2_right.xpm", &test->all.exit.trapdoor_right.x, \
		&test->all.exit.trapdoor_right.y);
	test->all.exit.trapdoor_right.addr = mlx_get_data_addr \
		(test->all.exit.trapdoor_right.img, &test->all.exit.trapdoor_right.\
		bits_per_pixel, &test->all.exit.trapdoor_right.line_length, &test->all.\
		exit.trapdoor_right.endian);
}

void	norme8(t_test *test)
{
	test->player.frontside.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/detective_frontside.xpm", &test->player.\
		frontside.x, &test->player.frontside.y);
	test->player.frontside.addr = mlx_get_data_addr \
		(test->player.frontside.img, &test->player.frontside.bits_per_pixel, \
		&test->player.frontside.line_length, &test->player.frontside.endian);
	test->player.backside.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/detective_backside.xpm", &test->player.backside.\
		x, &test->player.backside.y);
	test->player.backside.addr = mlx_get_data_addr \
		(test->player.backside.img, &test->player.backside.bits_per_pixel, \
		&test->player.backside.line_length, &test->player.backside.endian);
	test->player.rightside.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/detective_sideright.xpm", &test->player.rightside.\
		x, &test->player.rightside.y);
	test->player.rightside.addr = mlx_get_data_addr \
		(test->player.rightside.img, &test->player.rightside.bits_per_pixel, \
		&test->player.rightside.line_length, &test->player.rightside.endian);
}

void	norme9(t_test *test)
{
	test->player.leftside.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/detective_sideleft.xpm", &test->player.leftside.\
		x, &test->player.leftside.y);
	test->player.leftside.addr = mlx_get_data_addr \
		(test->player.leftside.img, &test->player.leftside.bits_per_pixel, \
		&test->player.leftside.line_length, &test->player.leftside.endian);
	test->player.dmg_front.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/damages_front.xpm", &test->player.dmg_front.x, \
		&test->player.dmg_front.y);
	test->player.dmg_front.addr = mlx_get_data_addr \
		(test->player.dmg_front.img, &test->player.dmg_front.bits_per_pixel, \
		&test->player.dmg_front.line_length, &test->player.dmg_front.endian);
	test->player.dmg_back.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/damages_back.xpm", &test->player.dmg_back.x, \
		&test->player.dmg_back.y);
	test->player.dmg_back.addr = mlx_get_data_addr \
		(test->player.dmg_back.img, &test->player.dmg_back.bits_per_pixel, \
		&test->player.dmg_back.line_length, &test->player.dmg_back.endian);
}

void	norme10(t_test *test)
{
	test->all.chimney.bottom_right.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/chimney_br.xpm", &test->all.chimney.bottom_right.\
		x, &test->all.chimney.bottom_right.y);
	test->all.chimney.bottom_right.addr = mlx_get_data_addr \
		(test->all.chimney.bottom_right.img, &test->all.chimney.bottom_right.\
		bits_per_pixel, &test->all.chimney.bottom_right.line_length, &test->all.\
		chimney.bottom_right.endian);
	test->all.chimney.bottom_left.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/chimney_bl.xpm", &test->all.chimney.bottom_left.\
		x, &test->all.chimney.bottom_left.y);
	test->all.chimney.bottom_left.addr = mlx_get_data_addr \
		(test->all.chimney.bottom_left.img, &test->all.chimney.bottom_left.\
		bits_per_pixel, &test->all.chimney.bottom_left.line_length, &test->all.\
		chimney.bottom_left.endian);
	test->all.chimney.mid_right.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/chimney_mr.xpm", &test->all.chimney.mid_right.x, \
		&test->all.chimney.mid_right.y);
	test->all.chimney.mid_right.addr = mlx_get_data_addr \
		(test->all.chimney.mid_right.img, &test->all.chimney.mid_right.\
		bits_per_pixel, &test->all.chimney.mid_right.line_length, &test->all.\
		chimney.mid_right.endian);
}
