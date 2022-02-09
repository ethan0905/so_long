/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:12:05 by esafar            #+#    #+#             */
/*   Updated: 2021/12/14 12:12:15 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_surounded_by_walls(t_test *test, char **map)
{
	int	i;

	i = 0;
	while (map[0][i] != '\0' && map[0][i] == '1')
		i++;
	if (i != test->param.width)
		return (-1);
	i = 0;
	while (map[test->param.height - 1][i] != '\0' && \
		map[test->param.height - 1][i] == '1')
		i++;
	if (i != test->param.width)
		return (-1);
	i = 0;
	while (i < test->param.height && map[i][0] != '\0' && map[i][0] == '1')
		i++;
	if (i != test->param.height)
		return (-1);
	i = 0;
	while (i < test->param.height && map[i][test->param.width - 1] != \
		'\0' && map[i][test->param.width - 1] == '1')
		i++;
	if (i != test->param.height)
		return (-1);
	return (1);
}

int	min_one_collectible(t_test *test)
{
	int	i;
	int	j;
	int	coll;

	i = 0;
	coll = 0;
	while (test->param.map[i])
	{
		j = 0;
		while (test->param.map[i][j])
		{
			if (test->param.map[i][j] == 'C')
				coll++;
			j++;
		}
		i++;
	}
	if (coll == 0)
		return (-1);
	return (1);
}

int	only_one(t_test *test, char to_check)
{
	int	i;
	int	j;
	int	one;

	i = 0;
	one = 0;
	while (test->param.map[i])
	{
		j = 0;
		while (test->param.map[i][j])
		{
			if (test->param.map[i][j] == to_check)
				one++;
			if (one > 1)
				return (-1);
			j++;
		}
		i++;
	}
	if (one == 0)
		return (-1);
	return (1);
}

int	map_is_rectangular(t_test *test)
{
	int		i;
	size_t	tmp;

	i = 1;
	tmp = ft_strlen(test->param.map[0]);
	while (test->param.map[i])
	{
		if (ft_strlen(test->param.map[i]) != tmp)
			return (-1);
		i++;
	}
	return (1);
}

int	check_chars(t_test *test)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (test->param.map[i])
	{
		j = 0;
		while (test->param.map[i][j])
		{
			if (test->param.map[i][j] == '1' || test->param.map[i][j] == \
				'0' || test->param.map[i][j] == 'E' || test->param.\
				map[i][j] == 'C' || test->param.map[i][j] == 'P' || \
				test->param.map[i][j] == 'T')
				count++;
			j++;
		}
		i++;
	}
	if (count == test->param.width * test->param.height)
		return (1);
	return (-1);
}
