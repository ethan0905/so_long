/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:17:53 by esafar            #+#    #+#             */
/*   Updated: 2021/06/04 09:32:53 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size = 1;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		buffer_size;
	char	*dest;
	long	nbis;

	nbis = n;
	buffer_size = ft_intlen(n);
	dest = (char *)malloc(sizeof(char) * (buffer_size + 1));
	if (!dest)
		return (NULL);
	if (nbis < 0)
		nbis = -nbis;
	dest[buffer_size--] = '\0';
	while (buffer_size >= 0)
	{
		dest[buffer_size] = nbis % 10 + '0';
		nbis = nbis / 10;
		buffer_size--;
	}
	if (n < 0)
		dest[0] = '-';
	return (dest);
}
