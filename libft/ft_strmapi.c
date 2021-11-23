/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 08:52:51 by esafar            #+#    #+#             */
/*   Updated: 2021/06/04 09:33:11 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*tableau;

	i = 0;
	if (!s)
		return (NULL);
	tableau = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!tableau)
		return (NULL);
	while (s[i] != '\0')
	{
		tableau[i] = (f)(i, s[i]);
		i++;
	}
	tableau[i] = '\0';
	return (tableau);
}
