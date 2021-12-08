/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:25:21 by esafar            #+#    #+#             */
/*   Updated: 2021/12/08 10:25:35 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	exec_right(t_test *test)
{
	test->param.map[test->player.pos_i][test->player.pos_j] = '0';
	test->param.map[test->player.pos_i][test->player.pos_j + 1] = 'P';
	test->player.lastpos_j = test->player.pos_j;
	test->player.pos_j++;
	test->player.side = &test->player.rightside;
	test->player.pos_x += 64;
	test->player.pos_y += 0;
}

void	exec_left(t_test *test)
{
	test->param.map[test->player.pos_i][test->player.pos_j] = '0';
	test->param.map[test->player.pos_i][test->player.pos_j - 1] = 'P';
	test->player.lastpos_j = test->player.pos_j;
	test->player.pos_j--;
	test->player.side = &test->player.leftside;
	test->player.pos_x -= 64;
	test->player.pos_y += 0;
}

void	exec_up(t_test *test)
{
	test->param.map[test->player.pos_i][test->player.pos_j] = '0';
	test->param.map[test->player.pos_i - 1][test->player.pos_j] = 'P';
	test->player.lastpos_i = test->player.pos_i;
	test->player.pos_i--;
	test->player.side = &test->player.backside;
	test->player.pos_x += 64;
	test->player.pos_y -= 64;
}

void	exec_down(t_test *test)
{
	test->param.map[test->player.pos_i][test->player.pos_j] = '0';
	test->param.map[test->player.pos_i + 1][test->player.pos_j] = 'P';
	test->player.lastpos_i = test->player.pos_i;
	test->player.pos_i++;
	test->player.side = &test->player.frontside;
	test->player.pos_x -= 64;
	test->player.pos_y += 64;
}
