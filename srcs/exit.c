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
