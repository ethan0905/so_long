/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:32:28 by esafar            #+#    #+#             */
/*   Updated: 2022/12/14 14:39:00 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	make_intro(t_test *test)
{
	if (test->intro_or_not == 1)
		draw_on_image_intro(test, &test->intro.one, 0, 0);
	else if (test->intro_or_not == 2)
		draw_on_image_intro(test, &test->intro.two, 0, 0);
	else if (test->intro_or_not == 3)
		draw_on_image_intro(test, &test->intro.three, 0, 0);
	else if (test->intro_or_not == 4)
		draw_on_image_intro(test, &test->intro.four, 0, 0);
	else if (test->intro_or_not == 5)
		draw_on_image_intro(test, &test->intro.five, 0, 0);
	mlx_put_image_to_window(test->mlx, test->win, test->data.img, 0, 0);
}

void	draw_all_together(t_test *test)
{
	draw_background(test);
	draw_walls(test);
	draw_floors(test);
	draw_trap(test);
	draw_exit(test);
	draw_furnitures(test);
	draw_collectibles(test);
	if (test->param.rendered == 0)
		test->player.side = &test->player.frontside;
	draw_player(test);
	mlx_put_image_to_window(test->mlx, test->win, test->data.img, 0, 0);
	draw_score(test);
	draw_button(test);
	test->param.rendered = 1;
	if (test->dialog_box.keep == 1)
		draw_dialog_box(test);
	draw_life(test);
}

int	render(t_test *test)
{
	if ((test->intro_or_not == 1 || test->intro_or_not == 2 || test->intro_or_not == 3 || test->intro_or_not == 4 || test->intro_or_not == 5) && test->param.width_with_x * 64 - (2 * 64) == 960 && (test->param.height - 2) * 64 +	3 * 64 == 448)
		make_intro(test);
	else if ((test->param.rendered == 0 || test->param.rendered == 1) && test->stats.lives != 0)
	{
		draw_all_together(test);
		test->intro_or_not = 0;
	}
	test->frame++;
	if (test->frame % 40 / 32 == 1)
		test->frame = 0;
	return (0);
}

void	get_all_images_and_addresses(t_test *test)
{
	get_event(test);
	get_piano(test);
	get_chimney_and_dresser(test);
	get_fire(test);
	get_collec(test);
	get_remain(test);
	get_player(test);
	get_stats(test);
	get_exit(test);
}

int	main(int ac, char **av)
{
	t_test	test;

	get_map(&test, ac, av);
	check_error(&test, av);
	print_map(&test);
	
	test.mlx = mlx_init();
	test.win = mlx_new_window(test.mlx, test.param.width_with_x * 64 - (2 * 64), (test.param.height - 2) * 64 + 3 * 64, "so_short on time!");
	test.data.img = mlx_new_image(test.mlx, test.param.width_with_x * 64 - (2 * 64), (test.param.height - 2) * 64 + 3 * 64);
	test.data.addr = mlx_get_data_addr(test.data.img, &test.data.bits_per_pixel, &test.data.line_length, &test.data.endian);
	get_all_images_and_addresses(&test);
	
	mlx_hook(test.win, 2, 1L << 0, &handle_keypress, &test);
	mlx_loop_hook(test.mlx, render, &test);
	mlx_hook(test.win, 17, 1L << 0, &close_win_cross, &test);
	mlx_loop(test.mlx);
	
	return (0);
}
