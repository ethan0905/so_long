/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 08:44:26 by esafar            #+#    #+#             */
/*   Updated: 2021/06/04 09:21:51 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*d2;

	i = 0;
	d2 = (char *)dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i++ < n)
		*d2++ = *(char *)src++;
	return (dest);
}
