/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:25:30 by esafar            #+#    #+#             */
/*   Updated: 2021/12/07 19:25:39 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	clean_dialog(t_test *test)
{
	test->dialog_box.keep = 0;
	test->player.lock_pos = 0;
}

void	open_trapdoor(t_test *test)
{
	test->all.exit.opened = 1;
	test->player.lock_pos = 0;
}

void	play_piano(t_test *test)
{
	if (test->player.pos_i != 1 && test->param.map[test->player.pos_i
			- 1][test->player.pos_j] == '1' && \
			test->param.map[test->player.pos_i - 1][test->player.pos_j
			+ 1] == '1' && test->param.map[test->player.pos_i - \
			1][test->player.pos_j + 2] == '0' && test->player.pos_j + 1
			< test->param.width - 1 && test->param.map[test->player.pos_i
			- 1][test->player.pos_j - 1] == '1' && \
			test->param.map[test->player.pos_i - 1][test->player.pos_j
			- 2] == '0')
	{
		test->dialog_box.event = 1;
		draw_dialog_box(test);
		test->dialog_box.keep = 1;
	}
}

void	pick_up_coll_event(t_test *test)
{
	test->dialog_box.event = 2;
	draw_dialog_box(test);
	test->dialog_box.keep = 1;
	test->collec.count++;
	ft_putnbr_fd(test->collec.count, 1);
	ft_putstr_fd(" object in your inventory\n", 1);
}

void	pick_up_coll(t_test *test)
{
	if (test->param.map[test->player.pos_i][test->player.pos_j + 1] == 'C')
	{
		pick_up_coll_event(test);
		test->param.map[test->player.pos_i][test->player.pos_j + 1] = '0';
	}
	else if (test->param.map[test->player.pos_i][test->player.pos_j - 1] == 'C')
	{
		pick_up_coll_event(test);
		test->param.map[test->player.pos_i][test->player.pos_j - 1] = '0';
	}
	else if (test->param.map[test->player.pos_i + 1][test->player.pos_j] == 'C')
	{
		pick_up_coll_event(test);
		test->param.map[test->player.pos_i + 1][test->player.pos_j] = '0';
	}
	else if (test->param.map[test->player.pos_i - 1][test->player.pos_j] == 'C')
	{
		pick_up_coll_event(test);
		test->param.map[test->player.pos_i - 1][test->player.pos_j] = '0';
	}
}
