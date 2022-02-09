/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 09:04:02 by esafar            #+#    #+#             */
/*   Updated: 2021/11/17 20:12:43 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	fml(char *str)
{
	free(str);
	return (-1);
}

char	*after_newline(char *save)
{
	size_t		i;
	size_t		j;
	char		*after_newline;

	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (save[i] == '\0')
	{
		free(save);
		return (NULL);
	}
	after_newline = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!after_newline)
		return (NULL);
	i++;
	j = 0;
	while (save[i] != '\0')
		after_newline[j++] = save[i++];
	after_newline[j] = '\0';
	free(save);
	save = NULL;
	return (after_newline);
}

char	*get_line(char *save)
{
	size_t	i;
	char	*line;

	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

int	end_gnl(char *save, int key, int ret)
{
	if (key == 1)
		free(save);
	if (ret == 0)
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line, int key)
{
	int			ret;
	char		*buff;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE < 0 || !line || read(fd, "", 0) == -1)
		return (-1);
	if (!save)
		save = ft_strdup("");
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	ret = 1;
	while (ft_isnewline(save) == 0 && ret != 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
			return (fml(buff));
		buff[ret] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	*line = get_line(save);
	save = after_newline(save);
	if (end_gnl(save, key, ret) == 0)
		return (0);
	return (1);
}

/*
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int	fd1;
	int	fd2;
	char *line;

	fd1 = open("test1", O_RDONLY);
	fd2 = open("test2", O_RDONLY);
	get_next_line(fd1, &line);
	printf("line : %s\n", line);
	free(line);
	get_next_line(fd2, &line);
	printf("line : %s\n", line);
	free(line);
	get_next_line(fd1, &line);
	printf("line : %s\n", line);
	free(line);
	get_next_line(fd2, &line);
	printf("line : %s\n", line);
	free(line);
	return (0);
}

*/
