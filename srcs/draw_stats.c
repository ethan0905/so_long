/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_stats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:51:57 by esafar            #+#    #+#             */
/*   Updated: 2021/12/07 11:52:09 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_string(char *steps, char *collec, char *amount)
{
	if (steps)
	{
		free(steps);
		steps = NULL;
	}
	if (collec)
	{
		free(collec);
		collec = NULL;
	}
	if (amount)
	{
		free(amount);
		amount = NULL;
	}
}

void	draw_score(t_test *test)
{
	char *steps;
	char *collec;
	char *amount;

	steps = ft_itoa(test->player.steps);
	if (!steps)
		clean_exit(test);
	mlx_string_put(test->mlx, test->win, 25 - 3 - ft_strlen(steps), 20 + 10, 0xf4fefe, steps);
	draw_on_image(test, &test->stats.step, 40 - 8, -10);
	collec = ft_itoa(test->collec.count);
	if (!collec)
		clean_exit(test);
	amount = ft_itoa(test->collec.amount);
	if (!amount)
		clean_exit(test);
	mlx_string_put(test->mlx, test->win, 158 - 100 - 32 - 10, 25 + 32 - 7 + 20, 0xfefefe, collec);
	mlx_string_put(test->mlx, test->win, 166 - 100 - 32 - 10 + (ft_strlen(collec) - 1) * 6, 25 + 32 - 7 + 20, 0xfefefe, "/");
	mlx_string_put(test->mlx, test->win, 173 - 100 - 32 - 10 + (ft_strlen(collec) - 1) * 7, 25 + 32 - 7 + 20, 0xfefefe, amount);
	draw_on_image(test, &test->stats.glass, 173 - 100 - 32 - 10 + (ft_strlen(collec) - 1) * 7, 15 + 20);
	free_string(steps, collec, amount);
}

void	draw_life(t_test *test)
{
	int i;
	int j;

	draw_on_image(test, &test->stats.typeface_life, 7, 28 + 64);
	i = test->stats.lives;
	test->stats.damages = 3 - test->stats.lives;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			draw_on_image(test, &test->stats.full_heart, 7 + j * 24, -5 + 64);
			j++;
		}
		while (test->stats.damages > 0)
		{
			draw_on_image(test, &test->stats.empty_heart, 7 + ((test->stats.damages - 1) + test->stats.lives)* 24, -5 + 64);
			test->stats.damages--;
		}
		i--;
	}
}