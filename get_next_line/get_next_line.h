/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 09:05:29 by esafar            #+#    #+#             */
/*   Updated: 2021/12/13 16:38:48 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

int		get_next_line(int fd, char **line, int key);

int		ft_isnewline(char *s);

#endif
