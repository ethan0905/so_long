/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:20:27 by esafar            #+#    #+#             */
/*   Updated: 2021/12/08 11:20:52 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_event_img(t_test *test)
{
	mlx_destroy_image(test->mlx, test->intro.one.img);
	mlx_destroy_image(test->mlx, test->intro.two.img);
	mlx_destroy_image(test->mlx, test->intro.three.img);
	mlx_destroy_image(test->mlx, test->intro.four.img);
	mlx_destroy_image(test->mlx, test->intro.five.img);
	mlx_destroy_image(test->mlx, test->dialog_box.right.img);
	mlx_destroy_image(test->mlx, test->dialog_box.mid.img);
	mlx_destroy_image(test->mlx, test->dialog_box.left.img);
	mlx_destroy_image(test->mlx, test->stats.full_heart.img);
	mlx_destroy_image(test->mlx, test->stats.empty_heart.img);
	mlx_destroy_image(test->mlx, test->stats.typeface_life.img);
	mlx_destroy_image(test->mlx, test->stats.glass.img);
	mlx_destroy_image(test->mlx, test->stats.step.img);
	mlx_destroy_image(test->mlx, test->button.e_key.img);
	mlx_destroy_image(test->mlx, test->button.p_key.img);
	mlx_destroy_image(test->mlx, test->button.o_key.img);
}

void	destroy_obj_img(t_test *test)
{
	mlx_destroy_image(test->mlx, test->all.box.img);
	mlx_destroy_image(test->mlx, test->all.pot.img);
	mlx_destroy_image(test->mlx, test->all.cardboard.img);
	mlx_destroy_image(test->mlx, test->all.dresser_topright.img);
	mlx_destroy_image(test->mlx, test->all.dresser_topleft.img);
	mlx_destroy_image(test->mlx, test->all.dresser_downright.img);
	mlx_destroy_image(test->mlx, test->all.dresser_downleft.img);
	mlx_destroy_image(test->mlx, test->all.piano.downleft.img);
	mlx_destroy_image(test->mlx, test->all.piano.downmid.img);
	mlx_destroy_image(test->mlx, test->all.piano.downright.img);
	mlx_destroy_image(test->mlx, test->all.piano.midleft.img);
	mlx_destroy_image(test->mlx, test->all.piano.midmid.img);
	mlx_destroy_image(test->mlx, test->all.piano.midright.img);
	mlx_destroy_image(test->mlx, test->all.piano.topleft.img);
	mlx_destroy_image(test->mlx, test->all.piano.topmid.img);
	mlx_destroy_image(test->mlx, test->all.piano.topright.img);
	mlx_destroy_image(test->mlx, test->all.chimney.bottom_right.img);
	mlx_destroy_image(test->mlx, test->all.chimney.bottom_left.img);
	mlx_destroy_image(test->mlx, test->all.chimney.mid_right.img);
	mlx_destroy_image(test->mlx, test->all.chimney.mid_left.img);
	mlx_destroy_image(test->mlx, test->all.chimney.top_right.img);
	mlx_destroy_image(test->mlx, test->all.chimney.top_left.img);
}

void	destroy_collec_floor_wall(t_test *test)
{
	mlx_destroy_image(test->mlx, test->all.wall.img);
	mlx_destroy_image(test->mlx, test->all.floor.img);
	mlx_destroy_image(test->mlx, test->all.floor_half_left.img);
	mlx_destroy_image(test->mlx, test->all.floor_half_right.img);
	mlx_destroy_image(test->mlx, test->all.babolex_painting.img);
	mlx_destroy_image(test->mlx, test->all.spike.img);
	mlx_destroy_image(test->mlx, test->collec.newspaper.img);
	mlx_destroy_image(test->mlx, test->collec.wanted.img);
	mlx_destroy_image(test->mlx, test->collec.murder_article.img);
	mlx_destroy_image(test->mlx, test->all.exit.exit_half_right.img);
	mlx_destroy_image(test->mlx, test->all.exit.exit_half_left.img);
	mlx_destroy_image(test->mlx, test->all.exit.trapdoor_right.img);
	mlx_destroy_image(test->mlx, test->all.exit.trapdoor_left.img);
	mlx_destroy_image(test->mlx, test->all.exit.open_to_right.img);
	mlx_destroy_image(test->mlx, test->all.exit.open_to_left.img);
}

void	destroy_fire_img(t_test *test)
{
	mlx_destroy_image(test->mlx, test->all.fire.frame_one.img);
	mlx_destroy_image(test->mlx, test->all.fire.frame_two.img);
	mlx_destroy_image(test->mlx, test->all.fire.frame_three.img);
	mlx_destroy_image(test->mlx, test->all.fire.frame_four.img);
	mlx_destroy_image(test->mlx, test->all.fire.frame_five.img);
	mlx_destroy_image(test->mlx, test->all.fire.frame_six.img);
	mlx_destroy_image(test->mlx, test->all.fire.frame_seven.img);
	mlx_destroy_image(test->mlx, test->all.fire.frame_eight.img);
}
