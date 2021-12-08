/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:38:06 by esafar            #+#    #+#             */
/*   Updated: 2021/12/07 20:38:14 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_ladder(t_test *test)
{
	draw_on_image(test, &test->all.exit.exit_half_right, test->iter.x
		+ 23, test->iter.y);
	draw_on_image(test, &test->all.exit.exit_half_left, test->iter.x
		- 64 + 27, test->iter.y);
}

void	draw_trapdoor_closed(t_test *test)
{
	draw_on_image(test, &test->all.exit.trapdoor_right, test->iter.x
		+ 23, test->iter.y);
	draw_on_image(test, &test->all.exit.trapdoor_left, test->iter.x
		- 64 + 23, test->iter.y);
}

void	draw_trapdoor_opened(t_test *test, int x, int y)
{
	draw_on_image(test, &test->all.exit.open_to_right, x, y);
	draw_on_image(test, &test->all.exit.open_to_left, x - 64, y);
}

void	check_how_to_draw_exit(t_test *test)
{
	if (test->param.map[test->iter.i][test->iter.j] == 'E')
	{
		draw_ladder(test);
		if (test->all.exit.opened == 0)
			draw_trapdoor_closed(test);
		else if (test->all.exit.opened == 1
			&& test->param.map[test->iter.i - 1][test->iter.j] != '1')
			draw_trapdoor_opened(test, test->iter.x + 23 + 64
				- 16, test->iter.y - 64 + 12);
		else if (test->all.exit.opened == 1 && test->param.map[test->iter.i
				- 1][test->iter.j] == '1')
		{
			if (test->param.map[test->iter.i][test->iter.j + 1] == '0'
				|| test->param.map[test->iter.i][test->iter.j + 1] == 'P')
				draw_trapdoor_opened(test, test->iter.x + 23 + 64
					- 8, test->iter.y + 12);
		}
	}
}

void	draw_exit(t_test *test)
{
	test->iter.i = 0;
	while (test->param.map[++test->iter.i + 1])
	{
		test->iter.j = 0;
		while (test->param.map[test->iter.i][++test->iter.j + 1])
		{
			test->iter.x = (64 + (test->param.height - 2
						- test->iter.i) * 64 + (test->iter.j - 1) * 64);
			test->iter.y = (192 + (test->iter.i - 1) * 64);
			check_how_to_draw_exit(test);
		}
	}
}
