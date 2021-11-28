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
	mlx_destroy_image(test->mlx, test->all.spike.img);
	// mlx_destroy_image(test->mlx, test->all.hole_left.img);
	// mlx_destroy_image(test->mlx, test->all.hole_right.img);
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
	mlx_destroy_image(test->mlx, test->all.exit_half_right.img);
	mlx_destroy_image(test->mlx, test->all.exit_half_left.img);
	mlx_destroy_image(test->mlx, test->player.frontside.img);
	mlx_destroy_image(test->mlx, test->player.backside.img);
	mlx_destroy_image(test->mlx, test->player.rightside.img);
	mlx_destroy_image(test->mlx, test->player.leftside.img);
	mlx_destroy_image(test->mlx, test->dialog_box.right.img);
	mlx_destroy_image(test->mlx, test->dialog_box.mid.img);
	mlx_destroy_image(test->mlx, test->dialog_box.left.img);
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
