/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:23:27 by esafar            #+#    #+#             */
/*   Updated: 2021/11/23 18:23:30 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	clean_exit(t_test *test)
{
	// mlx_destroy_image(test->mlx, test->intro.one.img);
	mlx_destroy_image(test->mlx, test->intro.two.img);
	mlx_destroy_image(test->mlx, test->all.wall.img);
	mlx_destroy_image(test->mlx, test->all.floor.img);
	mlx_destroy_image(test->mlx, test->all.floor_half_left.img);
	mlx_destroy_image(test->mlx, test->all.floor_half_right.img);
	mlx_destroy_image(test->mlx, test->all.box.img);
	mlx_destroy_image(test->mlx, test->all.pot.img);
	mlx_destroy_image(test->mlx, test->all.cardboard.img);
	mlx_destroy_image(test->mlx, test->all.dresser_topright.img);
	mlx_destroy_image(test->mlx, test->all.dresser_topleft.img);
	mlx_destroy_image(test->mlx, test->all.dresser_downright.img);
	mlx_destroy_image(test->mlx, test->all.dresser_downleft.img);
	mlx_destroy_image(test->mlx, test->all.babolex_painting.img);
	mlx_destroy_image(test->mlx, test->all.spike.img);
	mlx_destroy_image(test->mlx, test->collec.newspaper.img);
	mlx_destroy_image(test->mlx, test->collec.wanted.img);
	mlx_destroy_image(test->mlx, test->collec.murder_article.img);
	mlx_destroy_image(test->mlx, test->all.piano.downleft.img);
	mlx_destroy_image(test->mlx, test->all.piano.downmid.img);
	mlx_destroy_image(test->mlx, test->all.piano.downright.img);
	mlx_destroy_image(test->mlx, test->all.piano.midleft.img);
	mlx_destroy_image(test->mlx, test->all.piano.midmid.img);
	mlx_destroy_image(test->mlx, test->all.piano.midright.img);
	mlx_destroy_image(test->mlx, test->all.piano.topleft.img);
	mlx_destroy_image(test->mlx, test->all.piano.topmid.img);
	mlx_destroy_image(test->mlx, test->all.piano.topright.img);
	mlx_destroy_image(test->mlx, test->all.exit.exit_half_right.img);
	mlx_destroy_image(test->mlx, test->all.exit.exit_half_left.img);
	mlx_destroy_image(test->mlx, test->all.exit.trapdoor_right.img);
	mlx_destroy_image(test->mlx, test->all.exit.trapdoor_left.img);
	mlx_destroy_image(test->mlx, test->all.exit.open_t_right.img);
	mlx_destroy_image(test->mlx, test->all.exit.open_t_left.img);
	mlx_destroy_image(test->mlx, test->all.chimney.bottom_right.img);
	mlx_destroy_image(test->mlx, test->all.chimney.bottom_left.img);
	mlx_destroy_image(test->mlx, test->all.chimney.mid_right.img);
	mlx_destroy_image(test->mlx, test->all.chimney.mid_left.img);
	mlx_destroy_image(test->mlx, test->all.chimney.top_right.img);
	mlx_destroy_image(test->mlx, test->all.chimney.top_left.img);
	mlx_destroy_image(test->mlx, test->all.fire.frame_one.img);
	mlx_destroy_image(test->mlx, test->all.fire.frame_two.img);
	mlx_destroy_image(test->mlx, test->all.fire.frame_three.img);
	mlx_destroy_image(test->mlx, test->all.fire.frame_four.img);
	mlx_destroy_image(test->mlx, test->all.fire.frame_five.img);
	mlx_destroy_image(test->mlx, test->all.fire.frame_six.img);
	mlx_destroy_image(test->mlx, test->all.fire.frame_seven.img);
	mlx_destroy_image(test->mlx, test->all.fire.frame_eight.img);
	mlx_destroy_image(test->mlx, test->player.frontside.img);
	mlx_destroy_image(test->mlx, test->player.backside.img);
	mlx_destroy_image(test->mlx, test->player.rightside.img);
	mlx_destroy_image(test->mlx, test->player.leftside.img);
	mlx_destroy_image(test->mlx, test->player.dmg_front.img);
	mlx_destroy_image(test->mlx, test->player.dmg_back.img);
	mlx_destroy_image(test->mlx, test->player.dmg_right.img);
	mlx_destroy_image(test->mlx, test->player.dmg_left.img);
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

	mlx_destroy_window(test->mlx, test->win);
	test->win = NULL;
	// mlx_loop_end(test->mlx);
	mlx_destroy_display(test->mlx);
	free(test->mlx);
	//free du tab
	int i = 0;
	while (test->param.map[i])
	{
		free(test->param.map[i]);
		i++;
	}
	free(test->param.map);
	exit(0);
}
