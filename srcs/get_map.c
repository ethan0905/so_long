/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:31:37 by esafar            #+#    #+#             */
/*   Updated: 2021/11/23 18:31:48 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_map(t_test *test)
{
	int	i;
	int	j;

	i = 0;
	while (test->param.map[i])
	{
		j = 0;
		while (test->param.map[i][j])
		{
			printf("%c ", test->param.map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	count_lines(t_test *test, int fd, char *line)
{
	int	count;

	count = 0;
	while (get_next_line(fd, &line, 0) == 1)
	{
		count++;
		test->param.width = ft_strlen(line);
		free(line);
	}
	free(line);
	close(fd);
	return (count);
}

void	operation(t_test *test, int fd, char *line, int key)
{
	test->iter.j = 0;
	if (key == 0)
		get_next_line(fd, &line, 0);
	else if (key == 1)
		get_next_line(fd, &line, 1);
	while (line[test->iter.j] != '\0')
		test->iter.j++;
	test->param.map[test->iter.i] = get_line(line);
	test->param.map[test->iter.i][test->iter.j] = '\0';
	if (test->iter.i == 0)
		test->param.width_with_x = test->iter.j + test->iter.x - 1;
	test->iter.j = 1;
	test->iter.i++;
	free(line);
}

void	get_line_and_param(t_test *test, char *line, int fd)
{
	test->param.map = (char **)malloc(sizeof(char *) * (test->iter.x + 1));
	test->param.height = test->iter.x;
	test->iter.i = 0;
	while (test->iter.x > 1)
	{
		operation(test, fd, line, 0);
		test->iter.x--;
	}
	operation(test, fd, line, 1);
	test->iter.x--;
}

int	get_map(t_test *test, int ac, char **av)
{
	int		fd;
	char	*line;

	line = NULL;
	if (ac != 2)
		ft_putstr_fd("Error\n", 2);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		exit(ft_putstr_fd("Error. Map file not found.\n", 2));
	initialize(test);
	test->iter.x = count_lines(test, fd, line);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		exit(ft_putstr_fd("Error. Map file not found.\n", 2));
	get_line_and_param(test, line, fd);
	test->param.map[test->iter.i] = NULL;
	close(fd);
	test->param.height_with_wall = test->param.height + 3;
	return (0);
}

//GET_MAP WITH X's
// int    get_map(t_test *test, int ac, char **av)
// {
// 	int     fd;
// 	// int     diff;
// 	char    *line;

// 	if (ac != 2)
// 		ft_putstr_fd("Error\n", 2);
// 	fd = open(av[1], O_RDONLY);
// 	if (fd < 0)
// 	{
// 		ft_putstr_fd("Error\n", 2);
// 		return (-1);
// 	}

// 	//compter mon nombre de lignes
// 	initialize(test);
// 	test->iter.x = count_lines(test, fd, line);

// 	//boucler sur mon nb de lignes pour recup ma map
// 	fd = open(av[1], O_RDONLY);
// 	if (fd < 0)
// 	{
// 		ft_putstr_fd("Error\n", 2);
// 		return (-1);
// 	}

// 	test->param.map = (char **)malloc(sizeof(char *) * (test->iter.x + 1));
// 	test->param.height = test->iter.x;

// 	test->iter.i = 0;
// 	while (test->iter.x > 0)
// 	{
// 		test->iter.j = -1;
// 		get_next_line(fd, &line);
// 		// diff = test->iter.x;
// 		// while (--diff > 0)
// 		// 	printf("X ");
// 		while (line[++test->iter.j] != '\0')
// 		{
// 			printf("%c ", line[test->iter.j]);
// 		}
// 		test->param.map[test->iter.i] = get_line(line);
// 		test->param.map[test->iter.i][test->iter.j] = '\0';
// 		if (test->iter.i == 0)
// 			test->param.width_with_x = test->iter.j + test->iter.x - 1;
// 		test->iter.j = 1;
// 		// while (test->iter.i + --test->iter.j > 0)
// 		// 	printf("X ");
// 		printf("\n");
// 		test->iter.x--;
// 		test->iter.i++;
// 		free(line);
// 	}
// 	test->param.map[test->iter.i] = NULL;
// 	close(fd);
// 	test->param.height_with_wall = test->param.height + 3;
// 	printf("\n");

// 	print_map(test);
//     return (0);
// }