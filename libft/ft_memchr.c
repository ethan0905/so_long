/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:02:01 by esafar            #+#    #+#             */
/*   Updated: 2021/06/04 09:25:53 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*tab;

	i = 0;
	tab = (char *)s;
	while (i < n)
	{
		if (*tab == (char)c)
			return (tab);
		i++;
		tab++;
	}
	return (NULL);
}
