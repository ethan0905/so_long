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

int    get_map(t_test *test, int ac, char **av)
{
	int     i;
	int     fd;
	int     diff;
	int     count;
	int     put_x;
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
	count = 0;
	while (get_next_line(fd, &line) != 0)
	{
		count++;
		test->param.width = ft_strlen(line);
		free(line);
	}
	free(line);
	close(fd);

	//boucler sur mon nb de lignes pour recup ma map
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}

	test->param.map = (char **)malloc(sizeof(char *) * (count + 1));
	put_x = 0;
	test->param.height = count;
	while (count > 0)
	{
		i = -1;
		get_next_line(fd, &line);
		diff = count;
		while (--diff > 0)
			printf("X ");
		while (line[++i] != '\0')
		{
			printf("%c ", line[i]);
		}
		test->param.map[put_x] = get_line(line);
		test->param.map[put_x][i] = '\0';
		if (put_x == 0)
			test->param.width_with_x = i + count - 1;
		i = 1;
		while (put_x + --i > 0)
			printf("X ");
		printf("\n");
		count--;
		put_x++;
		free(line);
	}
	test->param.map[put_x] = NULL;
	close(fd);
	test->param.height_with_wall = test->param.height + 3;
	printf("\nlargeur avec x = %d\n", test->param.width_with_x);
	printf("largeur = %d\n", test->param.width);
	printf("hauteur = %d\n", test->param.height);
	printf("hauteur avec murs = %d\n", test->param.height_with_wall);
	printf("window size : %d * %d\n\n", test->param.width_with_x*64-(2*64), (test->param.height-2)*64+3*64);

	i = 0;
	int j = 0;
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
    return (0);
}