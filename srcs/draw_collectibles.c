/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_collectibles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:31:50 by esafar            #+#    #+#             */
/*   Updated: 2021/12/07 18:32:03 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_which_collectible(t_test *test, int i, int x, int y)
{
	if (i % 2 == 0)
		draw_on_image(test, &test->collec.newspaper, x, y);
	else if (i % 2 == 1)
		draw_on_image(test, &test->collec.murder_article, x, y);
}

void	draw_collectibles(t_test *test)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 1;
	while (test->param.map[i + 1])
	{
		j = 1;
		while (test->param.map[i][j + 1])
		{
			x = (64 + (test->param.height - 2 - i) * 64 + (j - 1) * 64);
			y = (192 + (i - 1) * 64);
			if (test->param.map[i][j] == 'C' && j % 2 == 0)
				check_which_collectible(test, i, x, y);
			else if (test->param.map[i][j] == 'C' && j % 2 == 1)
				draw_on_image(test, &test->collec.wanted, x, y);
			j++;
		}
		i++;
	}
}
