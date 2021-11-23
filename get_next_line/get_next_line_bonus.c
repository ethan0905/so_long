/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 10:11:01 by esafar            #+#    #+#             */
/*   Updated: 2021/06/25 10:26:40 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	fml(char *str)
{
	free(str);
	return (-1);
}

char	*fml_bis(char *str)
{
	free(str);
	return (NULL);
}

char	*after_newline(char *save)
{
	size_t	i;
	size_t	j;
	char	*after_newline;

	i = 0;
	if (!save)
		return (NULL);
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (save[i] == '\0')
		return (fml_bis(save));
	after_newline = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!after_newline)
		return (NULL);
	i++;
	j = 0;
	while (save[i] != '\0')
		after_newline[j++] = save[i++];
	after_newline[j] = '\0';
	free(save);
	return (after_newline);
}

char	*get_line(char *save)
{
	size_t	i;
	char	*line;

	if (!save)
		return (NULL);
	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

int	get_next_line(int fd, char **line)
{
	int			ret;
	char		*buff;
	static char	*save[1024];

	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, "", 0) == -1)
		return (-1);
	if (!save[fd])
		save[fd] = ft_strdup("");
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	ret = 1;
	while (ret != 0 && ft_isnewline(save[fd]) == 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
			return (fml(buff));
		buff[ret] = '\0';
		save[fd] = ft_strjoin(save[fd], buff);
	}
	free(buff);
	*line = get_line(save[fd]);
	save[fd] = after_newline(save[fd]);
	if (ret == 0)
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
	printf("%s\n", line);
	free(line);
	get_next_line(fd2, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd1, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd2, &line);
	printf("%s\n", line);
	free(line);
	return (0);
}*/
