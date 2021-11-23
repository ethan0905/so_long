/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:26:03 by esafar            #+#    #+#             */
/*   Updated: 2021/11/23 18:26:17 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_pixel(t_data *img, int x, int y)
{
    return (*(int *)(img->addr + (y * img->line_length + (x * (img->bits_per_pixel / 8)))));
}

void	my_mlx_pixel_put(t_test *test, int x, int y, int color)
{
	char	*dest;

	dest = test->data.addr + (y * test->data.line_length + x * (test->data.bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}