/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:59:16 by esafar            #+#    #+#             */
/*   Updated: 2021/12/13 14:59:29 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	norme1(t_test *test)
{
	test->all.fire.frame_one.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/flame_1.xpm", &test->all.fire.frame_one.x, \
		&test->all.fire.frame_one.y);
	test->all.fire.frame_one.addr = mlx_get_data_addr \
		(test->all.fire.frame_one.img, &test->all.fire.frame_one.\
		bits_per_pixel, &test->all.fire.frame_one.line_length, \
		&test->all.fire.frame_one.endian);
	test->all.fire.frame_two.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/flame_2.xpm", &test->all.fire.frame_two.x, \
		&test->all.fire.frame_two.y);
	test->all.fire.frame_two.addr = mlx_get_data_addr \
		(test->all.fire.frame_two.img, &test->all.fire.frame_two.\
		bits_per_pixel, &test->all.fire.frame_two.line_length, \
		&test->all.fire.frame_two.endian);
	test->all.fire.frame_three.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/flame_3.xpm", &test->all.fire.frame_three.\
		x, &test->all.fire.frame_three.y);
	test->all.fire.frame_three.addr = mlx_get_data_addr \
		(test->all.fire.frame_three.img, &test->all.fire.frame_three.\
		bits_per_pixel, &test->all.fire.frame_three.line_length, \
		&test->all.fire.frame_three.endian);
}

void	norme2(t_test *test)
{
	test->all.fire.frame_four.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/flame_4.xpm", &test->all.fire.frame_four.\
		x, &test->all.fire.frame_four.y);
	test->all.fire.frame_four.addr = mlx_get_data_addr \
		(test->all.fire.frame_four.img, &test->all.fire.frame_four.\
		bits_per_pixel, &test->all.fire.frame_four.line_length, \
		&test->all.fire.frame_four.endian);
	test->all.fire.frame_five.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/flame_5.xpm", &test->all.fire.frame_five.\
		x, &test->all.fire.frame_five.y);
	test->all.fire.frame_five.addr = mlx_get_data_addr \
		(test->all.fire.frame_five.img, &test->all.fire.frame_five.\
		bits_per_pixel, &test->all.fire.frame_five.line_length, \
		&test->all.fire.frame_five.endian);
	test->all.fire.frame_six.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/flame_6.xpm", &test->all.fire.frame_six.\
		x, &test->all.fire.frame_six.y);
	test->all.fire.frame_six.addr = mlx_get_data_addr \
		(test->all.fire.frame_six.img, &test->all.fire.frame_six.\
		bits_per_pixel, &test->all.fire.frame_six.line_length, \
		&test->all.fire.frame_six.endian);
}

void	norme3(t_test *test)
{
	test->intro.one.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/murderer_960.xpm", &test->intro.one.x, \
		&test->intro.one.y);
	test->intro.one.addr = mlx_get_data_addr \
		(test->intro.one.img, &test->intro.one.bits_per_pixel, \
		&test->intro.one.line_length, &test->intro.one.endian);
	test->intro.two.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/dead_wife_960.xpm", &test->intro.two.x, \
		&test->intro.two.y);
	test->intro.two.addr = mlx_get_data_addr \
		(test->intro.two.img, &test->intro.two.bits_per_pixel, \
		&test->intro.two.line_length, &test->intro.two.endian);
	test->intro.three.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/rainy_960.xpm", &test->intro.three.x, \
		&test->intro.three.y);
	test->intro.three.addr = mlx_get_data_addr \
		(test->intro.three.img, &test->intro.three.bits_per_pixel, \
		&test->intro.three.line_length, &test->intro.three.endian);
}

void	norme4(t_test *test)
{
	test->intro.four.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/working_desk_960.xpm", &test->intro.four.x, \
		&test->intro.four.y);
	test->intro.four.addr = mlx_get_data_addr \
		(test->intro.four.img, &test->intro.four.bits_per_pixel, \
		&test->intro.four.line_length, &test->intro.four.endian);
	test->intro.five.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/house_960.xpm", &test->intro.five.x, \
		&test->intro.five.y);
	test->intro.five.addr = mlx_get_data_addr \
		(test->intro.five.img, &test->intro.five.bits_per_pixel, \
		&test->intro.five.line_length, &test->intro.five.endian);
	test->button.e_key.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/key_e.xpm", &test->button.e_key.x, \
		&test->button.e_key.y);
	test->button.e_key.addr = mlx_get_data_addr \
		(test->button.e_key.img, &test->button.e_key.bits_per_pixel, \
		&test->button.e_key.line_length, &test->button.e_key.endian);
}

void	norme5(t_test *test)
{
	test->button.p_key.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/key_p.xpm", &test->button.p_key.x, \
		&test->button.p_key.y);
	test->button.p_key.addr = mlx_get_data_addr \
		(test->button.p_key.img, &test->button.p_key.bits_per_pixel, \
		&test->button.p_key.line_length, &test->button.p_key.endian);
	test->button.o_key.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/key_o.xpm", &test->button.o_key.x, \
		&test->button.o_key.y);
	test->button.o_key.addr = mlx_get_data_addr \
		(test->button.o_key.img, &test->button.o_key.bits_per_pixel, \
		&test->button.o_key.line_length, &test->button.o_key.endian);
	test->dialog_box.right.img = mlx_xpm_file_to_image \
		(test->mlx, "textures/dialog_box_right.xpm", &test->dialog_box.\
		right.x, &test->dialog_box.right.y);
	test->dialog_box.right.addr = mlx_get_data_addr \
		(test->dialog_box.right.img, &test->dialog_box.right.bits_per_pixel, \
		&test->dialog_box.right.line_length, &test->dialog_box.right.endian);
}
