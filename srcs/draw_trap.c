/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_trap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:41:38 by esafar            #+#    #+#             */
/*   Updated: 2021/12/07 20:41:47 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_spike(t_test *test)
{
	draw_on_image(test, &test->all.spike, test->iter.x
		+ 16, test->iter.y - 32 - 8);
	draw_on_image(test, &test->all.spike, test->iter.x + 8, test->iter.y - 32);
	draw_on_image(test, &test->all.spike, test->iter.x, test->iter.y - 16 - 8);
	draw_on_image(test, &test->all.spike, test->iter.x - 8, test->iter.y - 16);
}

void	draw_trap(t_test *test)
{
	test->iter.i = 1;
	while (test->param.map[test->iter.i + 1])
	{
		test->iter.j = 1;
		while (test->param.map[test->iter.i][test->iter.j + 1])
		{
			test->iter.x = (64 + (test->param.height - 2
						- test->iter.i) * 64 + (test->iter.j - 1) * 64);
			test->iter.y = (192 + (test->iter.i - 1) * 64);
			if (test->param.map[test->iter.i][test->iter.j] == 'T')
				draw_spike(test);
			test->iter.j++;
		}
		test->iter.i++;
	}
}
