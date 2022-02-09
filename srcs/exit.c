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

void	destroy_player_img(t_test *test)
{
	mlx_destroy_image(test->mlx, test->player.frontside.img);
	mlx_destroy_image(test->mlx, test->player.backside.img);
	mlx_destroy_image(test->mlx, test->player.rightside.img);
	mlx_destroy_image(test->mlx, test->player.leftside.img);
	mlx_destroy_image(test->mlx, test->player.dmg_front.img);
	mlx_destroy_image(test->mlx, test->player.dmg_back.img);
	mlx_destroy_image(test->mlx, test->player.dmg_right.img);
	mlx_destroy_image(test->mlx, test->player.dmg_left.img);
}

int	close_win_cross(t_test *test)
{
	mlx_loop_end (test->mlx);
	clean_exit(test);
	return (0);
}

void	free_map(t_test *test)
{
	test->iter.i = 0;
	while (test->param.map[test->iter.i])
	{
		free(test->param.map[test->iter.i]);
		test->iter.i++;
	}
	free(test->param.map);
}

void	clean_exit(t_test *test)
{
	mlx_destroy_image(test->mlx, test->data.img);
	destroy_event_img(test);
	destroy_obj_img(test);
	destroy_fire_img(test);
	destroy_player_img(test);
	destroy_collec_floor_wall(test);
	mlx_destroy_window(test->mlx, test->win);
	test->win = NULL;
	mlx_loop_end(test->mlx);
	mlx_destroy_display(test->mlx);
	free(test->mlx);
	free_map(test);
	exit(0);
}
