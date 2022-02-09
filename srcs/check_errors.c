/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:06:40 by esafar            #+#    #+#             */
/*   Updated: 2021/12/14 12:06:54 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_extension(char *map_name)
{
	int		i;
	int		j;
	char	*ext;

	ext = ".ber\0";
	i = 0;
	while (map_name[i] && map_name[i] != '.')
		i++;
	j = 0;
	while (map_name[i + j] && ext[j] && map_name[i + j] == ext[j])
		j++;
	if (j == 4 && map_name[i + j] == '\0' && ext[j] == '\0')
		return (1);
	return (-1);
}

int	check_map_size(t_test *test)
{
	if (test->param.width_with_x * 64 > 42 * 64)
		return (-1);
	if (test->param.height_with_wall * 64 > 23 * 64)
		return (-1);
	return (1);
}

void	which_error_msg_to_print(t_test *test, int event)
{
	if (event == 1)
		ft_putstr_fd("Error. Wrong map extension.\n", 2);
	else if (event == 2)
		ft_putstr_fd("Error. Map is not surrounded by walls.\n", 2);
	else if (event == 3)
		ft_putstr_fd("Error. Map is not rectangular.\n", 2);
	else if (event == 4)
		ft_putstr_fd("Error. Not enough collectibles.\n", 2);
	else if (event == 5)
		ft_putstr_fd("Error. There is no (or too much) exit(s).\n", 2);
	else if (event == 6)
		ft_putstr_fd("Error. There is no (or too much) player(s).\n", 2);
	else if (event == 7)
		ft_putstr_fd \
		("Error. Valid map can contain only [1][0][C][E][P][T].\n", 2);
	else if (event == 8)
		ft_putstr_fd("Error. Wrong map size.\n", 2);
	free_map(test);
	exit(-1);
}

int	check_error(t_test *test, char **av)
{
	if (ft_check_extension(av[1]) == -1)
		which_error_msg_to_print(test, 1);
	else if (map_surounded_by_walls(test, test->param.map) == -1)
		which_error_msg_to_print(test, 2);
	else if (map_is_rectangular(test) == -1)
		which_error_msg_to_print(test, 3);
	else if (min_one_collectible(test) == -1)
		which_error_msg_to_print(test, 4);
	else if (only_one(test, 'E') == -1)
		which_error_msg_to_print(test, 5);
	else if (only_one(test, 'P') == -1)
		which_error_msg_to_print(test, 6);
	else if (check_chars(test) == -1)
		which_error_msg_to_print(test, 7);
	else if (check_map_size(test) == -1)
		which_error_msg_to_print(test, 8);
	return (1);
}
