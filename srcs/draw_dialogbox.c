/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_dialogbox.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:35:07 by esafar            #+#    #+#             */
/*   Updated: 2022/12/14 14:50:39 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_box(t_test *test)
{
	draw_on_image(test, &test->dialog_box.left, (test->param.width
			/ 2 - 2) * 64, (test->param.height) * 64);
	draw_on_image(test, &test->dialog_box.mid, (test->param.width
			/ 2 - 1) * 64, (test->param.height) * 64);
	draw_on_image(test, &test->dialog_box.mid, (test->param.width
			/ 2) * 64, (test->param.height) * 64);
	draw_on_image(test, &test->dialog_box.mid, (test->param.width
			/ 2 + 1) * 64, (test->param.height) * 64);
	draw_on_image(test, &test->dialog_box.right, (test->param.width
			/ 2 + 2) * 64, (test->param.height) * 64);
}

void	draw_dialog_box(t_test *test)
{
	print_box(test);
	if (test->dialog_box.event == 1)
	{
		write_piano_event(test);
		test->player.lock_pos = 1;
	}
	else if (test->dialog_box.event == 2)
	{
		write_new_item_event(test);
		test->player.lock_pos = 1;
	}
	else if (test->dialog_box.event == 3)
	{
		write_newspaper_event(test);
		test->player.lock_pos = 1;
	}
	write_press_c_event(test);
}
