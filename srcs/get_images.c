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
	test->all.fire.frame_one.img = mlx_xpm_file_to_image(test->mlx, "textures/flame_1.xpm", &test->all.fire.frame_one.x, &test->all.fire.frame_one.y);
    test->all.fire.frame_one.addr = mlx_get_data_addr(test->all.fire.frame_one.img, &test->all.fire.frame_one.bits_per_pixel, &test->all.fire.frame_one.line_length, &test->all.fire.frame_one.endian);
	test->all.fire.frame_two.img = mlx_xpm_file_to_image(test->mlx, "textures/flame_2.xpm", &test->all.fire.frame_two.x, &test->all.fire.frame_two.y);
    test->all.fire.frame_two.addr = mlx_get_data_addr(test->all.fire.frame_two.img, &test->all.fire.frame_two.bits_per_pixel, &test->all.fire.frame_two.line_length, &test->all.fire.frame_two.endian);
	test->all.fire.frame_three.img = mlx_xpm_file_to_image(test->mlx, "textures/flame_3.xpm", &test->all.fire.frame_three.x, &test->all.fire.frame_three.y);
    test->all.fire.frame_three.addr = mlx_get_data_addr(test->all.fire.frame_three.img, &test->all.fire.frame_three.bits_per_pixel, &test->all.fire.frame_three.line_length, &test->all.fire.frame_three.endian);
	test->all.fire.frame_four.img = mlx_xpm_file_to_image(test->mlx, "textures/flame_4.xpm", &test->all.fire.frame_four.x, &test->all.fire.frame_four.y);
    test->all.fire.frame_four.addr = mlx_get_data_addr(test->all.fire.frame_four.img, &test->all.fire.frame_four.bits_per_pixel, &test->all.fire.frame_four.line_length, &test->all.fire.frame_four.endian);
	test->all.fire.frame_five.img = mlx_xpm_file_to_image(test->mlx, "textures/flame_5.xpm", &test->all.fire.frame_five.x, &test->all.fire.frame_five.y);
    test->all.fire.frame_five.addr = mlx_get_data_addr(test->all.fire.frame_five.img, &test->all.fire.frame_five.bits_per_pixel, &test->all.fire.frame_five.line_length, &test->all.fire.frame_five.endian);
	test->all.fire.frame_six.img = mlx_xpm_file_to_image(test->mlx, "textures/flame_6.xpm", &test->all.fire.frame_six.x, &test->all.fire.frame_six.y);
    test->all.fire.frame_six.addr = mlx_get_data_addr(test->all.fire.frame_six.img, &test->all.fire.frame_six.bits_per_pixel, &test->all.fire.frame_six.line_length, &test->all.fire.frame_six.endian);
	test->all.fire.frame_seven.img = mlx_xpm_file_to_image(test->mlx, "textures/flame_7.xpm", &test->all.fire.frame_seven.x, &test->all.fire.frame_seven.y);
    test->all.fire.frame_seven.addr = mlx_get_data_addr(test->all.fire.frame_seven.img, &test->all.fire.frame_seven.bits_per_pixel, &test->all.fire.frame_seven.line_length, &test->all.fire.frame_seven.endian);
	test->all.fire.frame_eight.img = mlx_xpm_file_to_image(test->mlx, "textures/flame_8.xpm", &test->all.fire.frame_eight.x, &test->all.fire.frame_eight.y);
    test->all.fire.frame_eight.addr = mlx_get_data_addr(test->all.fire.frame_eight.img, &test->all.fire.frame_eight.bits_per_pixel, &test->all.fire.frame_eight.line_length, &test->all.fire.frame_eight.endian);
}

void	get_player(t_test *test)
{
	test->player.frontside.img = mlx_xpm_file_to_image(test->mlx, "textures/detective_frontside.xpm", &test->player.frontside.x, &test->player.frontside.y);
	test->player.frontside.addr = mlx_get_data_addr(test->player.frontside.img, &test->player.frontside.bits_per_pixel, &test->player.frontside.line_length, &test->player.frontside.endian);
	test->player.backside.img = mlx_xpm_file_to_image(test->mlx, "textures/detective_backside.xpm", &test->player.backside.x, &test->player.backside.y);
	test->player.backside.addr = mlx_get_data_addr(test->player.backside.img, &test->player.backside.bits_per_pixel, &test->player.backside.line_length, &test->player.backside.endian);
	test->player.rightside.img = mlx_xpm_file_to_image(test->mlx, "textures/detective_sideright.xpm", &test->player.rightside.x, &test->player.rightside.y);
	test->player.rightside.addr = mlx_get_data_addr(test->player.rightside.img, &test->player.rightside.bits_per_pixel, &test->player.rightside.line_length, &test->player.rightside.endian);
	test->player.leftside.img = mlx_xpm_file_to_image(test->mlx, "textures/detective_sideleft.xpm", &test->player.leftside.x, &test->player.leftside.y);
	test->player.leftside.addr = mlx_get_data_addr(test->player.leftside.img, &test->player.leftside.bits_per_pixel, &test->player.leftside.line_length, &test->player.leftside.endian);
	test->player.dmg_front.img = mlx_xpm_file_to_image(test->mlx, "textures/damages_front.xpm", &test->player.dmg_front.x, &test->player.dmg_front.y);
	test->player.dmg_front.addr = mlx_get_data_addr(test->player.dmg_front.img, &test->player.dmg_front.bits_per_pixel, &test->player.dmg_front.line_length, &test->player.dmg_front.endian);
	test->player.dmg_back.img = mlx_xpm_file_to_image(test->mlx, "textures/damages_back.xpm", &test->player.dmg_back.x, &test->player.dmg_back.y);
	test->player.dmg_back.addr = mlx_get_data_addr(test->player.dmg_back.img, &test->player.dmg_back.bits_per_pixel, &test->player.dmg_back.line_length, &test->player.dmg_back.endian);
	test->player.dmg_right.img = mlx_xpm_file_to_image(test->mlx, "textures/damages_sideright.xpm", &test->player.dmg_right.x, &test->player.dmg_right.y);
	test->player.dmg_right.addr = mlx_get_data_addr(test->player.dmg_right.img, &test->player.dmg_right.bits_per_pixel, &test->player.dmg_right.line_length, &test->player.dmg_right.endian);
	test->player.dmg_left.img = mlx_xpm_file_to_image(test->mlx, "textures/damages_sideleft.xpm", &test->player.dmg_left.x, &test->player.dmg_left.y);
	test->player.dmg_left.addr = mlx_get_data_addr(test->player.dmg_left.img, &test->player.dmg_left.bits_per_pixel, &test->player.dmg_left.line_length, &test->player.dmg_left.endian);
}

void	get_event(t_test *test)
{
	test->intro.one.img = mlx_xpm_file_to_image(test->mlx, "textures/murderer_960.xpm", &test->intro.one.x, &test->intro.one.y);
	test->intro.one.addr = mlx_get_data_addr(test->intro.one.img, &test->intro.one.bits_per_pixel, &test->intro.one.line_length, &test->intro.one.endian);
	test->intro.two.img = mlx_xpm_file_to_image(test->mlx, "textures/dead_wife_960.xpm", &test->intro.two.x, &test->intro.two.y);
	test->intro.two.addr = mlx_get_data_addr(test->intro.two.img, &test->intro.two.bits_per_pixel, &test->intro.two.line_length, &test->intro.two.endian);
	test->intro.three.img = mlx_xpm_file_to_image(test->mlx, "textures/rainy_960.xpm", &test->intro.three.x, &test->intro.three.y);
	test->intro.three.addr = mlx_get_data_addr(test->intro.three.img, &test->intro.three.bits_per_pixel, &test->intro.three.line_length, &test->intro.three.endian);
	test->intro.four.img = mlx_xpm_file_to_image(test->mlx, "textures/working_desk_960.xpm", &test->intro.four.x, &test->intro.four.y);
	test->intro.four.addr = mlx_get_data_addr(test->intro.four.img, &test->intro.four.bits_per_pixel, &test->intro.four.line_length, &test->intro.four.endian);
	test->intro.five.img = mlx_xpm_file_to_image(test->mlx, "textures/house_960.xpm", &test->intro.five.x, &test->intro.five.y);
	test->intro.five.addr = mlx_get_data_addr(test->intro.five.img, &test->intro.five.bits_per_pixel, &test->intro.five.line_length, &test->intro.five.endian);
    test->button.e_key.img = mlx_xpm_file_to_image(test->mlx, "textures/key_e.xpm", &test->button.e_key.x, &test->button.e_key.y);
    test->button.e_key.addr = mlx_get_data_addr(test->button.e_key.img, &test->button.e_key.bits_per_pixel, &test->button.e_key.line_length, &test->button.e_key.endian);
	test->button.p_key.img = mlx_xpm_file_to_image(test->mlx, "textures/key_p.xpm", &test->button.p_key.x, &test->button.p_key.y);
    test->button.p_key.addr = mlx_get_data_addr(test->button.p_key.img, &test->button.p_key.bits_per_pixel, &test->button.p_key.line_length, &test->button.p_key.endian);
	test->button.o_key.img = mlx_xpm_file_to_image(test->mlx, "textures/key_o.xpm", &test->button.o_key.x, &test->button.o_key.y);
    test->button.o_key.addr = mlx_get_data_addr(test->button.o_key.img, &test->button.o_key.bits_per_pixel, &test->button.o_key.line_length, &test->button.o_key.endian);
	test->dialog_box.right.img = mlx_xpm_file_to_image(test->mlx, "textures/dialog_box_right.xpm", &test->dialog_box.right.x, &test->dialog_box.right.y);
    test->dialog_box.right.addr = mlx_get_data_addr(test->dialog_box.right.img, &test->dialog_box.right.bits_per_pixel, &test->dialog_box.right.line_length, &test->dialog_box.right.endian);
	test->dialog_box.mid.img = mlx_xpm_file_to_image(test->mlx, "textures/dialog_box_mid.xpm", &test->dialog_box.mid.x, &test->dialog_box.mid.y);
    test->dialog_box.mid.addr = mlx_get_data_addr(test->dialog_box.mid.img, &test->dialog_box.mid.bits_per_pixel, &test->dialog_box.mid.line_length, &test->dialog_box.mid.endian);
	test->dialog_box.left.img = mlx_xpm_file_to_image(test->mlx, "textures/dialog_box_left.xpm", &test->dialog_box.left.x, &test->dialog_box.left.y);
    test->dialog_box.left.addr = mlx_get_data_addr(test->dialog_box.left.img, &test->dialog_box.left.bits_per_pixel, &test->dialog_box.left.line_length, &test->dialog_box.left.endian);
}

void	get_stats(t_test *test)
{
	test->stats.full_heart.img = mlx_xpm_file_to_image(test->mlx, "textures/white_full_heart.xpm", &test->stats.full_heart.x, &test->stats.full_heart.y);
	test->stats.full_heart.addr = mlx_get_data_addr(test->stats.full_heart.img, &test->stats.full_heart.bits_per_pixel, &test->stats.full_heart.line_length, &test->stats.full_heart.endian);
	test->stats.empty_heart.img = mlx_xpm_file_to_image(test->mlx, "textures/white_empty_heart.xpm", &test->stats.empty_heart.x, &test->stats.empty_heart.y);
	test->stats.empty_heart.addr = mlx_get_data_addr(test->stats.empty_heart.img, &test->stats.empty_heart.bits_per_pixel, &test->stats.empty_heart.line_length, &test->stats.empty_heart.endian);
	test->stats.typeface_life.img = mlx_xpm_file_to_image(test->mlx, "textures/typeface_life_2.xpm", &test->stats.typeface_life.x, &test->stats.typeface_life.y);
	test->stats.typeface_life.addr = mlx_get_data_addr(test->stats.typeface_life.img, &test->stats.typeface_life.bits_per_pixel, &test->stats.typeface_life.line_length, &test->stats.typeface_life.endian);
	test->stats.glass.img = mlx_xpm_file_to_image(test->mlx, "textures/glass_rotated.xpm", &test->stats.glass.x, &test->stats.glass.y);
	test->stats.glass.addr = mlx_get_data_addr(test->stats.glass.img, &test->stats.glass.bits_per_pixel, &test->stats.glass.line_length, &test->stats.glass.endian);
	test->stats.step.img = mlx_xpm_file_to_image(test->mlx, "textures/shoes.xpm", &test->stats.step.x, &test->stats.step.y);
	test->stats.step.addr = mlx_get_data_addr(test->stats.step.img, &test->stats.step.bits_per_pixel, &test->stats.step.line_length, &test->stats.step.endian);
}

void	get_exit(t_test *test)
{
	test->all.exit.exit_half_left.img = mlx_xpm_file_to_image(test->mlx, "textures/CUT_ladder.xpm", &test->all.exit.exit_half_left.x, &test->all.exit.exit_half_left.y);
    test->all.exit.exit_half_left.addr = mlx_get_data_addr(test->all.exit.exit_half_left.img, &test->all.exit.exit_half_left.bits_per_pixel, &test->all.exit.exit_half_left.line_length, &test->all.exit.exit_half_left.endian);
	test->all.exit.exit_half_right.img = mlx_xpm_file_to_image(test->mlx, "textures/CUT_ladder_right.xpm", &test->all.exit.exit_half_right.x, &test->all.exit.exit_half_right.y);
    test->all.exit.exit_half_right.addr = mlx_get_data_addr(test->all.exit.exit_half_right.img, &test->all.exit.exit_half_right.bits_per_pixel, &test->all.exit.exit_half_right.line_length, &test->all.exit.exit_half_right.endian);
	test->all.exit.trapdoor_right.img = mlx_xpm_file_to_image(test->mlx, "textures/FINAL2_right.xpm", &test->all.exit.trapdoor_right.x, &test->all.exit.trapdoor_right.y);
    test->all.exit.trapdoor_right.addr = mlx_get_data_addr(test->all.exit.trapdoor_right.img, &test->all.exit.trapdoor_right.bits_per_pixel, &test->all.exit.trapdoor_right.line_length, &test->all.exit.trapdoor_right.endian);
	test->all.exit.trapdoor_left.img = mlx_xpm_file_to_image(test->mlx, "textures/FINAL2_left.xpm", &test->all.exit.trapdoor_left.x, &test->all.exit.trapdoor_left.y);
    test->all.exit.trapdoor_left.addr = mlx_get_data_addr(test->all.exit.trapdoor_left.img, &test->all.exit.trapdoor_left.bits_per_pixel, &test->all.exit.trapdoor_left.line_length, &test->all.exit.trapdoor_left.endian);
	test->all.exit.open_to_right.img = mlx_xpm_file_to_image(test->mlx, "textures/trapdoor_oriented_right.xpm", &test->all.exit.open_to_right.x, &test->all.exit.open_to_right.y);
    test->all.exit.open_to_right.addr = mlx_get_data_addr(test->all.exit.open_to_right.img, &test->all.exit.open_to_right.bits_per_pixel, &test->all.exit.open_to_right.line_length, &test->all.exit.open_to_right.endian);
	test->all.exit.open_to_left.img = mlx_xpm_file_to_image(test->mlx, "textures/trapdoor_oriented_left.xpm", &test->all.exit.open_to_left.x, &test->all.exit.open_to_left.y);
    test->all.exit.open_to_left.addr = mlx_get_data_addr(test->all.exit.open_to_left.img, &test->all.exit.open_to_left.bits_per_pixel, &test->all.exit.open_to_left.line_length, &test->all.exit.open_to_left.endian);
}