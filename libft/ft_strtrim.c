/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 12:18:11 by esafar            #+#    #+#             */
/*   Updated: 2021/06/04 09:32:31 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_is_char_from_set(const char *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*lajoconde;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && ft_is_char_from_set(set, s1[start]))
		start++;
	end = ft_strlen((char *)s1);
	while (start < end && ft_is_char_from_set(set, s1[end - 1]))
		end--;
	lajoconde = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!lajoconde)
		return (NULL);
	i = 0;
	while (start < end)
		lajoconde[i++] = s1[start++];
	lajoconde[i] = '\0';
	return (lajoconde);
}
