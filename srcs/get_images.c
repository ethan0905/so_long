/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:19:16 by esafar            #+#    #+#             */
/*   Updated: 2021/12/07 16:19:29 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_fire(t_test *test)
{
	norme1(test);
	norme2(test);
	test->all.fire.frame_seven.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/flame_7.xpm", &test->all.fire.frame_seven.x, \
		&test->all.fire.frame_seven.y);
	test->all.fire.frame_seven.addr = mlx_get_data_addr \
		(test->all.fire.frame_seven.img, &test->all.fire.frame_seven.\
		bits_per_pixel, &test->all.fire.frame_seven.line_length, \
		&test->all.fire.frame_seven.endian);
	test->all.fire.frame_eight.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/flame_8.xpm", &test->all.fire.frame_eight.\
		x, &test->all.fire.frame_eight.y);
	test->all.fire.frame_eight.addr = mlx_get_data_addr \
		(test->all.fire.frame_eight.img, &test->all.fire.frame_eight.\
		bits_per_pixel, &test->all.fire.frame_eight.line_length, \
		&test->all.fire.frame_eight.endian);
}

void	get_player(t_test *test)
{
	norme8(test);
	norme9(test);
	test->player.dmg_right.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/damages_sideright.xpm", &test->player.dmg_right.\
		x, &test->player.dmg_right.y);
	test->player.dmg_right.addr = mlx_get_data_addr \
		(test->player.dmg_right.img, &test->player.dmg_right.bits_per_pixel, \
		&test->player.dmg_right.line_length, &test->player.dmg_right.endian);
	test->player.dmg_left.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/damages_sideleft.xpm", &test->player.dmg_left.x, \
		&test->player.dmg_left.y);
	test->player.dmg_left.addr = mlx_get_data_addr \
		(test->player.dmg_left.img, &test->player.dmg_left.bits_per_pixel, \
		&test->player.dmg_left.line_length, &test->player.dmg_left.endian);
}

void	get_event(t_test *test)
{
	norme3(test);
	norme4(test);
	norme5(test);
	test->dialog_box.mid.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/dialog_box_mid.xpm", &test->dialog_box.mid.x, \
		&test->dialog_box.mid.y);
	test->dialog_box.mid.addr = mlx_get_data_addr \
		(test->dialog_box.mid.img, &test->dialog_box.mid.bits_per_pixel, \
		&test->dialog_box.mid.line_length, &test->dialog_box.mid.endian);
	test->dialog_box.left.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/dialog_box_left.xpm", &test->dialog_box.left.\
		x, &test->dialog_box.left.y);
	test->dialog_box.left.addr = mlx_get_data_addr \
		(test->dialog_box.left.img, &test->dialog_box.left.bits_per_pixel, \
		&test->dialog_box.left.line_length, &test->dialog_box.left.endian);
}

void	get_stats(t_test *test)
{
	init_img1(test);
	norme6(test);
	test->stats.glass.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/glass_rotated.xpm", &test->stats.glass.x, \
		&test->stats.glass.y);
	test->stats.glass.addr = mlx_get_data_addr \
		(test->stats.glass.img, &test->stats.glass.bits_per_pixel, &test->stats.\
		glass.line_length, &test->stats.glass.endian);
	test->stats.step.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/shoes.xpm", &test->stats.step.x, \
		&test->stats.step.y);
	test->stats.step.addr = mlx_get_data_addr \
		(test->stats.step.img, &test->stats.step.bits_per_pixel, \
		&test->stats.step.line_length, &test->stats.step.endian);
}

void	get_exit(t_test *test)
{
	norme7(test);
	test->all.exit.trapdoor_left.img = mlx_xpm_file_to_image(test->mlx, \
		"textures/FINAL2_left.xpm", &test->all.exit.trapdoor_left.x, \
		&test->all.exit.trapdoor_left.y);
	test->all.exit.trapdoor_left.addr = mlx_get_data_addr \
		(test->all.exit.trapdoor_left.img, &test->all.exit.trapdoor_left.\
		bits_per_pixel, &test->all.exit.trapdoor_left.line_length, \
		&test->all.exit.trapdoor_left.endian);
	test->all.exit.open_to_right.img = mlx_xpm_file_to_image(test->mlx, \
		"textures/trapdoor_oriented_right.xpm", &test->all.exit.open_to_right.\
		x, &test->all.exit.open_to_right.y);
	test->all.exit.open_to_right.addr = mlx_get_data_addr \
		(test->all.exit.open_to_right.img, &test->all.exit.open_to_right.\
		bits_per_pixel, &test->all.exit.open_to_right.line_length, \
		&test->all.exit.open_to_right.endian);
	test->all.exit.open_to_left.img = mlx_xpm_file_to_image(test->mlx, \
		"textures/trapdoor_oriented_left.xpm", &test->all.exit.open_to_left.\
		x, &test->all.exit.open_to_left.y);
	test->all.exit.open_to_left.addr = mlx_get_data_addr \
		(test->all.exit.open_to_left.img, &test->all.exit.open_to_left.\
		bits_per_pixel, &test->all.exit.open_to_left.line_length, \
		&test->all.exit.open_to_left.endian);
}
