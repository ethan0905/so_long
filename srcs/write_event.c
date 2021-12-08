/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:19:23 by esafar            #+#    #+#             */
/*   Updated: 2021/12/08 17:19:55 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	write_piano_event(t_test *test)
{
	mlx_string_put(test->mlx, test->win, (test->param.width
			/ 2 - 2) * 64 + 4, (test->param.height) * 64
		+ 16, 0xf4fefe, "Hmm strange... This piano seems to be perfectly");
	mlx_string_put(test->mlx, test->win, (test->param.width
			/ 2 - 2) * 64 + 4, (test->param.height) * 64
		+ 32, 0xf4fefe, "working...");
}

void	write_newspaper_event(t_test *test)
{
	mlx_string_put(test->mlx, test->win, (test->param.width
			/ 2 - 2) * 64 + 4, (test->param.height) * 64
		+ 16, 0xf4fefe, "I should take all the newspaper reports with me");
	mlx_string_put(test->mlx, test->win, (test->param.width
			/ 2 - 2) * 64 + 4, (test->param.height) * 64
		+ 32, 0xf4fefe, "before I go further..");
}

void	write_new_item_event(t_test *test)
{
	mlx_string_put(test->mlx, test->win, (test->param.width
			/ 2 - 2) * 64 + 4, (test->param.height) * 64
		+ 16, 0xf4fefe, "You have 1 new item in your inventory!");
}

void	write_press_c_event(t_test *test)
{
	mlx_string_put(test->mlx, test->win, (test->param.width
			/ 2 + 1) * 64 + 8, (test->param.height) * 64
		+ 32 + 16 + 5, 0xf4fefe, "Press C to continue");
}
