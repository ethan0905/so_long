/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 10:30:32 by esafar            #+#    #+#             */
/*   Updated: 2021/06/04 09:23:05 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d2;
	char	*s2;

	d2 = (char *)dest;
	s2 = (char *)src;
	if (src < dest)
	{
		while (n > 0)
		{
			n--;
			d2[n] = s2[n];
		}
	}
	else if (src > dest)
		ft_memcpy(d2, s2, n);
	return (dest);
}
