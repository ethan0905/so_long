/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_furnitures_cond.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:50:04 by esafar            #+#    #+#             */
/*   Updated: 2021/12/08 16:50:23 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	isvpcte(t_test *test, int i, int j)
{
	if (test->param.map[i][j] == '0')
		return (1);
	else if (test->param.map[i][j] == 'P')
		return (1);
	else if (test->param.map[i][j] == 'C')
		return (1);
	else if (test->param.map[i][j] == 'T')
		return (1);
	else if (test->param.map[i][j] == 'E')
		return (1);
	return (0);
}

int	cond1(t_test *test)
{
	if (test->param.map[test->iter.i][test->iter.j] == '1'
		&& ((isvpcte(test, test->iter.i, test->iter.j - 1) == 1)
		|| (test->param.map[test->iter.i][test->iter.j - 1] == '1'
		&& test->iter.j - 1 == 0)) && (isvpcte(test, test->iter.i, test->iter.j
		+ 1) == 1 || (test->param.map[test->iter.i][test->iter.j + 1] == '1'
		&& test->iter.j + 1 == test->param.width - 1)) && test->iter.i == 1)
		return (1);
	return (0);
}

int	cond2(t_test *test)
{
	if (test->param.map[test->iter.i][test->iter.j] == '1'
		&& test->param.map[test->iter.i][test->iter.j + 1] == '1'
		&& test->iter.j + 1 != test->param.width - 1
		&& (isvpcte(test, test->iter.i, test->iter.j - 1) == 1
		|| (test->param.map[test->iter.i][test->iter.j - 1] == '1'
		&& test->iter.j - 1 == 0)) && (isvpcte(test, test->iter.i, test->iter.j
		+ 2) == 1 || (test->param.map[test->iter.i][test->iter.j + 2] == '1'
		&& test->iter.j + 2 == test->param.width - 1)))
		return (1);
	return (0);
}

int	cond3(t_test *test)
{
	if (test->param.map[test->iter.i][test->iter.j] == '1'
		&& test->param.map[test->iter.i][test->iter.j + 1] == '1'
		&& test->param.map[test->iter.i][test->iter.j + 2] == '1'
		&& test->iter.j + 1 != test->param.width - 1
		&& (isvpcte(test, test->iter.i, test->iter.j - 1) == 1
		|| (test->param.map[test->iter.i][test->iter.j - 1] == '1'
		&& test->iter.j - 1 == 0)) && (isvpcte(test, test->iter.i, test->iter.j
		+ 3) == 1 || (test->param.map[test->iter.i][test->iter.j + 3] == '1'
		&& test->iter.j + 3 == test->param.width - 1)))
		return (1);
	return (0);
}

int	cond4(t_test *test)
{
	if (test->iter.i == 1 && test->iter.j != test->param.width - 4
		&& test->param.map[test->iter.i][test->iter.j] == '1'
		&& test->param.map[test->iter.i][test->iter.j + 1] == '1'
		&& test->param.map[test->iter.i][test->iter.j + 2] == '1'
		&& test->param.map[test->iter.i][test->iter.j + 3] == '1')
		return (1);
	return (0);
}
