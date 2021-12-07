/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_dialogbox.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:35:07 by esafar            #+#    #+#             */
/*   Updated: 2021/12/07 19:35:21 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_box(t_test *test)
{
	draw_on_image(test, &test->dialog_box.left, (test->param.width/2-2) * 64, (test->param.height) * 64);
	draw_on_image(test, &test->dialog_box.mid, (test->param.width/2-1) * 64, (test->param.height) * 64);
	draw_on_image(test, &test->dialog_box.mid, (test->param.width/2) * 64, (test->param.height) * 64);
	draw_on_image(test, &test->dialog_box.mid, (test->param.width/2+1) * 64, (test->param.height) * 64);
	draw_on_image(test, &test->dialog_box.right, (test->param.width/2+2) * 64, (test->param.height) * 64);
}

void 	draw_dialog_box(t_test *test)
{
	print_box(test);
	if (test->dialog_box.event == 1)
	{
		mlx_string_put(test->mlx, test->win, (test->param.width/2-2) * 64 + 4, (test->param.height) * 64 + 16, 0xf4fefe, "Hmm strange... This piano seems to be perfectly");
		mlx_string_put(test->mlx, test->win, (test->param.width/2-2) * 64 + 4, (test->param.height) * 64 + 32, 0xf4fefe, "working...");
		test->player.lock_pos = 1;
	}
	else if (test->dialog_box.event == 2)
	{
		mlx_string_put(test->mlx, test->win, (test->param.width/2-2) * 64 + 4, (test->param.height) * 64 + 16, 0xf4fefe, "You have 1 new item in your inventory!");
		test->player.lock_pos = 1;
	}
	else if (test->dialog_box.event == 3)
	{
		mlx_string_put(test->mlx, test->win, (test->param.width/2-2) * 64 + 4, (test->param.height) * 64 + 16, 0xf4fefe, "I should take all the newspaper reports with me");
		mlx_string_put(test->mlx, test->win, (test->param.width/2-2) * 64 + 4, (test->param.height) * 64 + 32, 0xf4fefe, "before I go further..");
		test->player.lock_pos = 1;
	}
	mlx_string_put(test->mlx, test->win, (test->param.width/2+1) * 64 + 8, (test->param.height) * 64 + 32 + 16 + 5, 0xf4fefe, "Press C to continue");
}