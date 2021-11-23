/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:02:18 by esafar            #+#    #+#             */
/*   Updated: 2021/06/04 09:24:42 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tab;

	tab = (char *)malloc(nmemb * size);
	if (tab == NULL)
		return (NULL);
	ft_bzero((void *)tab, nmemb * size);
	return (tab);
}
