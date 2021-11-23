/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 12:38:25 by esafar            #+#    #+#             */
/*   Updated: 2021/06/04 09:36:38 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*subsub(char const *s, unsigned int start, size_t len, size_t i)
{
	char	*str;

	if (ft_strlen(s) < start)
	{
		str = (char *)malloc(sizeof(char));
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
	}
	else
	{
		if (start + len > ft_strlen(s))
			len = ft_strlen(s) - start;
		str = (char *)malloc(sizeof(char) * (len + 1));
		if (!str)
			return (NULL);
		i = 0;
		while (++i - 1 < len)
			str[i - 1] = s[start + i - 1];
		str[i - 1] = '\0';
	}
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	return (subsub(s, start, len, i));
}
