/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 09:31:51 by esafar            #+#    #+#             */
/*   Updated: 2021/06/04 09:22:49 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	*d2;
	char	*s2;

	i = 0;
	d2 = (char *)dest;
	s2 = (char *)src;
	while (i < n)
	{
		*d2 = *s2;
		if (*s2 == (char)c)
		{
			*d2 = *s2;
			return ((void *)dest + i + 1);
		}
		i++;
		d2++;
		s2++;
	}
	return (NULL);
}
