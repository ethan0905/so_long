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
	int i;
	int j;

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
	int count;

	count = 0;
	while (get_next_line(fd, &line) != 0)
	{
		count++;
		test->param.width = ft_strlen(line);
		free(line);
	}
	free(line);
	close(fd);
	return (count);
}

int    get_map(t_test *test, int ac, char **av)
{
	int     fd;
	int     diff;
	char    *line;

	if (ac != 2)
		ft_putstr_fd("Error\n", 2);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}

	//compter mon nombre de lignes
	initialize(test);
	test->iter.x = count_lines(test, fd, line);

	//boucler sur mon nb de lignes pour recup ma map
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}

	test->param.map = (char **)malloc(sizeof(char *) * (test->iter.x + 1));
	test->param.height = test->iter.x;

	test->iter.i = 0;
	while (test->iter.x > 0)
	{
		test->iter.j = -1;
		get_next_line(fd, &line);
		diff = test->iter.x;
		while (--diff > 0)
			printf("X ");
		while (line[++test->iter.j] != '\0')
		{
			printf("%c ", line[test->iter.j]);
		}
		test->param.map[test->iter.i] = get_line(line);
		test->param.map[test->iter.i][test->iter.j] = '\0';
		if (test->iter.i == 0)
			test->param.width_with_x = test->iter.j + test->iter.x - 1;
		test->iter.j = 1;
		while (test->iter.i + --test->iter.j > 0)
			printf("X ");
		printf("\n");
		test->iter.x--;
		test->iter.i++;
		free(line);
	}
	test->param.map[test->iter.i] = NULL;
	close(fd);
	test->param.height_with_wall = test->param.height + 3;
	printf("\n");

	print_map(test);
    return (0);
}

/////save : |v|
// int    get_map(t_test *test, int ac, char **av)
// {
// 	int     i;
// 	int     fd;
// 	int     diff;
// 	int     count;
// 	int     j;
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
// 	count = count_lines(test, fd, line);

// 	//boucler sur mon nb de lignes pour recup ma map
// 	fd = open(av[1], O_RDONLY);
// 	if (fd < 0)
// 	{
// 		ft_putstr_fd("Error\n", 2);
// 		return (-1);
// 	}

// 	test->param.map = (char **)malloc(sizeof(char *) * (count + 1));
// 	j = 0;
// 	test->param.height = count;
// 	while (count > 0)
// 	{
// 		i = -1;
// 		get_next_line(fd, &line);
// 		diff = count;
// 		while (--diff > 0)
// 			printf("X ");
// 		while (line[++i] != '\0')
// 		{
// 			printf("%c ", line[i]);
// 		}
// 		test->param.map[j] = get_line(line);
// 		test->param.map[j][i] = '\0';
// 		if (j == 0)
// 			test->param.width_with_x = i + count - 1;
// 		i = 1;
// 		while (j + --i > 0)
// 			printf("X ");
// 		printf("\n");
// 		count--;
// 		j++;
// 		free(line);
// 	}
// 	test->param.map[j] = NULL;
// 	close(fd);
// 	test->param.height_with_wall = test->param.height + 3;
// 	printf("\n");

// 	print_map(test);
//     return (0);
// }