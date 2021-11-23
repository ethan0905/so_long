/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 14:45:52 by esafar            #+#    #+#             */
/*   Updated: 2021/06/04 09:34:59 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*current;

	current = *lst;
	if (lst)
	{
		while (current)
		{
			temp = current->next;
			ft_lstdelone(current, (*del));
			current = temp;
		}
		*lst = NULL;
	}
}
