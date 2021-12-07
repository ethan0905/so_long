/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:32:28 by esafar            #+#    #+#             */
/*   Updated: 2021/11/23 16:32:30 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_flames(t_test *test, int x, int y)
{
	draw_on_image(test, test->all.fire.frame, x, y);
}

void	draw_dresser(t_test *test, int x, int y)
{
	draw_on_image(test, &test->all.dresser_downleft, x, y - 24);
	draw_on_image(test, &test->all.dresser_downright, x + 64, y - 24);
	draw_on_image(test, &test->all.dresser_topleft, x, y - 64 - 24);
	draw_on_image(test, &test->all.dresser_topright, x + 64, y - 64 - 24);
}

int		draw_chimney(t_test *test, int random_obj, int x, int y)
{
	if (random_obj == 0)
	{
		draw_on_image(test, &test->all.chimney.bottom_left, x, y - 32 - 16 + 8);
		draw_on_image(test, &test->all.chimney.bottom_right, x + 64, y - 32 - 16 + 8);
		draw_on_image(test, &test->all.chimney.mid_left, x, y - 32 - 16 - 64 + 8);
		draw_on_image(test, &test->all.chimney.mid_right, x + 64, y - 32 - 16 - 64 + 8);
		draw_on_image(test, &test->all.chimney.top_left, x, y - 32 - 16 - 128 + 8);
		draw_on_image(test, &test->all.chimney.top_right, x + 64, y - 32 - 16 - 128 + 8);
		if (test->frame < 8)
			test->all.fire.frame = &test->all.fire.frame_one;
		else if (test->frame < 16 && test->frame >= 8)
			test->all.fire.frame = &test->all.fire.frame_three;
		else if (test->frame < 24 && test->frame >= 16)
			test->all.fire.frame = &test->all.fire.frame_five;
		else if (test->frame >= 24)
			test->all.fire.frame = &test->all.fire.frame_seven;
		draw_flames(test, x + 16, y - 51);
		random_obj = 1;
	}
	else if (random_obj == 1)
		draw_dresser(test, x, y);
	return (random_obj);
}

int	draw_piano(t_test *test, int piano, int x, int y)
{
	if (piano == 0)
	{
		draw_on_image(test, &test->all.piano.downleft, x, y - 26);
		draw_on_image(test, &test->all.piano.midleft, x, y - 64 - 26);
		draw_on_image(test, &test->all.piano.topleft, x + 9, y - 128 - 26);
		draw_on_image(test, &test->all.piano.downmid, x + 64, y - 26);
		draw_on_image(test, &test->all.piano.midmid, x + 64, y - 64 - 26);
		draw_on_image(test, &test->all.piano.topmid, x + 64, y - 128 - 26);
		draw_on_image(test, &test->all.piano.downright, x + 128, y - 26);
		draw_on_image(test, &test->all.piano.midright, x + 128, y - 64 - 26);
		draw_on_image(test, &test->all.piano.topright, x + 128, y - 128 - 26);
		piano++;
	}
	else
	{
		draw_on_image(test, &test->all.pot, x, y - 32);
		draw_on_image(test, &test->all.pot, x + 64, y - 32);
		draw_on_image(test, &test->all.pot, x + 128, y - 32);
	}
	return (piano);
}

void	draw_pot(t_test *test, int random_obj, int x, int y)
{
	if (random_obj == 0)
	{
		draw_on_image(test, &test->all.pot, x, y - 32);
		if (test->all.babo == 0)
		{
			draw_on_image(test, &test->all.babolex_painting, x + 32, y-128);
			test->all.babo = 1;
		}
	}
}

void draw_furnitures(t_test *test)
{
	int i;
	int j;
	int x;
	int y;
	int random_obj;
	int piano;

	i = 1;
	piano = 0;
	random_obj = 0;
	while (test->param.map[i + 1])
	{
		j = 1;
		while (test->param.map[i][j + 1])
		{
			x = (64 + (test->param.height - 2 - i)*64 + (j-1)*64);
			y = (192 + (i-1)*64);
			if (test->param.map[i][j] == '1' && i != 1)
				draw_on_image(test, &test->all.box, x, y);
			else if (test->param.map[i][j] == '1' && ((test->param.map[i][j - 1] == '0' || test->param.map[i][j - 1] == 'P') || (test->param.map[i][j - 1] == '1' && j - 1 == 0)) && ((test->param.map[i][j + 1] == '0' || test->param.map[i][j + 1] == 'P') || (test->param.map[i][j + 1] == '1' && j + 1 == test->param.width - 1)) && i == 1)
				draw_pot(test, random_obj, x, y);
			else if (test->param.map[i][j] == '1' && test->param.map[i][j + 1] == '1' && j + 1 != test->param.width - 1 && ((test->param.map[i][j - 1] == '0' || test->param.map[i][j - 1] == 'P') || (test->param.map[i][j - 1] == '1' && j - 1 == 0)) && ((test->param.map[i][j + 2] == '0' || test->param.map[i][j + 2] == 'P') || (test->param.map[i][j + 2] == '1' && j + 2 == test->param.width - 1)))
				random_obj = draw_chimney(test, random_obj, x, y);
			else if (test->param.map[i][j] == '1' && test->param.map[i][j + 1] == '1' && test->param.map[i][j + 2] == '1' && j + 1 != test->param.width - 1 && ((test->param.map[i][j - 1] == '0' || test->param.map[i][j - 1] == 'P') || (test->param.map[i][j - 1] == '1' && j - 1  == 0)) && ((test->param.map[i][j + 3] == '0' || test->param.map[i][j + 3] == 'P') || (test->param.map[i][j + 3] == '1' && j + 3 == test->param.width - 1)))
				piano = draw_piano(test, piano, x, y);
			else if (i == 1 && j != test->param.width - 4 && test->param.map[i][j] == '1' && test->param.map[i][j + 1] == '1' && test->param.map[i][j + 2] == '1' && test->param.map[i][j + 3] == '1')
			{
				draw_on_image(test, &test->all.pot, x, y - 32);
				draw_on_image(test, &test->all.pot, x + 64, y - 32);
				draw_on_image(test, &test->all.pot, x + 128, y - 32);
				draw_on_image(test, &test->all.pot, x + 192, y - 32);
			}
			j++;
		}
		i++;
	}
	test->all.babo = 0;
}

void	draw_exit(t_test *test)
{
	int i;
	int j;
	int x;
	int y;

	i = 1;
	while (test->param.map[i + 1])
	{
		j = 1;
		while (test->param.map[i][j + 1])
		{
			x = (64 + (test->param.height - 2 - i)*64 + (j-1)*64);
			y = (192 + (i-1)*64);
			if (test->param.map[i][j] == 'E')
			{
 				draw_on_image(test, &test->all.exit.exit_half_right, x + 23, y);
				draw_on_image(test, &test->all.exit.exit_half_left, x - 64 + 27, y);
				if (test->all.exit.opened == 0)
				{
 					draw_on_image(test, &test->all.exit.trapdoor_right, x + 23, y);
 					draw_on_image(test, &test->all.exit.trapdoor_left, x - 64 + 23, y);
				}
				else if (test->all.exit.opened == 1 && test->param.map[i-1][j] != '1')
				{
 					draw_on_image(test, &test->all.exit.open_to_right, x + 23 + 64 - 8 - 8, y-64 + 12);
 					draw_on_image(test, &test->all.exit.open_to_left, x - 64 + 23 + 64 - 8 - 8, y - 64 + 12);
				}
				else if (test->all.exit.opened == 1 && test->param.map[i-1][j] == '1')
				{
					if (test->param.map[i][j + 1] == '0' || test->param.map[i][j + 1] == 'P')
					{
 						draw_on_image(test, &test->all.exit.open_to_right, x + 23 + 64 - 8, y + 12);
 						draw_on_image(test, &test->all.exit.open_to_left, x - 64 + 23 + 64 - 8, y + 12);
					}				
				}
			}
			j++;
		}
		i++;
	}
}

void	get_pos_player(t_test *test)
{
	int i;
	int j;

	i = 0;
    while (test->param.map[i])
	{
		j = 0;
		while (test->param.map[i][j])
		{
			if (test->param.map[i][j] == 'P')
			{
				test->player.pos_i = i;
				test->player.pos_j = j;
				//(j-1)*64 + 12 -> set the position according to the j value in the tab. (+12 is only for more logical player positioning)
				//+(test.data.height - 3) * 64 -> allow you to adjust the player on the x axis depending on the height of the map (every + 1 will need to add 64px to pos_x)
				//-(i-1)*64 -> allow you to adjust the player depending of the y value the player spawn (every +1 will need to remove 64px to print the player closer to the left border) 
				test->player.pos_x = (j-1)*64 + 30 + (test->param.height - 3) * 64 - (i-1)*64; 
				test->player.pos_y = 3 * 64 + (i-1) * 64 - 64 - 25 + 10;
			}
			else if (test->param.map[i][j] == 'C' && test->param.rendered == 0)
				test->collec.amount++;
			j++;
		}	
		i++;
	}
}

void	choose_player_image(t_test *test)
{
	if (test->frame < 17)
	{
		if (test->param.map[test->player.pos_i + 1][test->player.pos_j] == 'T')
		   	test->player.side = &test->player.dmg_front;
		else if (test->param.map[test->player.pos_i - 1][test->player.pos_j] == 'T')
		   	test->player.side = &test->player.dmg_back;
		else if (test->param.map[test->player.pos_i][test->player.pos_j - 1] == 'T')
		   	test->player.side = &test->player.dmg_left;
		else if (test->param.map[test->player.pos_i][test->player.pos_j + 1] == 'T')
		   	test->player.side = &test->player.dmg_right;
	}
	else if (test->frame >= 17)
	{
		if (test->param.map[test->player.pos_i + 1][test->player.pos_j] == 'T')
		   	test->player.side = &test->player.frontside;
		else if (test->param.map[test->player.pos_i - 1][test->player.pos_j] == 'T')
		   	test->player.side = &test->player.backside;
		else if (test->param.map[test->player.pos_i][test->player.pos_j - 1] == 'T')
		   	test->player.side = &test->player.leftside;
		else if (test->param.map[test->player.pos_i][test->player.pos_j + 1] == 'T')
		   	test->player.side = &test->player.rightside;
	}
}

void draw_player(t_test *test)
{
	get_pos_player(test);
	if (test->player.hurt == 1)
	{
		test->player.lock_pos = 1;
		choose_player_image(test);
		if (test->frame == 31)
			test->loop++;
		if (test->loop == 4)
		{
			test->player.hurt = 0;
			test->loop = 0;
			test->player.lock_pos = 0;
			test->player.side = &test->player.frontside;
		}
		draw_on_image_bis(test, test->player.side, test->player.pos_x, test->player.pos_y);
	}
	else if (test->player.hurt == 0)
		draw_on_image_bis(test, test->player.side, test->player.pos_x, test->player.pos_y);
}

void	draw_trap(t_test *test)
{
	int i;
	int j;
	int x;
	int y;

	i = 1;
	while (test->param.map[i + 1])
	{
		j = 1;
		while (test->param.map[i][j + 1])
		{
			x = (64 + (test->param.height - 2 - i)*64 + (j-1)*64);
			y = (192 + (i-1)*64);
			if (test->param.map[i][j] == 'T')
			{
 				draw_on_image(test, &test->all.spike, x+16, y-32-8);
 				draw_on_image(test, &test->all.spike, x+8, y-32);
 				draw_on_image(test, &test->all.spike, x, y-16-8);
 				draw_on_image(test, &test->all.spike, x-8, y-16);
			}
			j++;
		}
		i++;
	}
}

void	draw_button(t_test *test)
{
	int i;

	i = 0;
    if ((test->param.map[test->player.pos_i][test->player.pos_j + 1] == 'C' || test->param.map[test->player.pos_i][test->player.pos_j - 1] == 'C' || test->param.map[test->player.pos_i - 1][test->player.pos_j] == 'C' || test->param.map[test->player.pos_i + 1][test->player.pos_j] == 'C'))
    {
		if (test->button.time % 2 == 0)
		{
        	draw_on_image(test, &test->button.e_key, test->player.pos_x + 32, test->player.pos_y - 42);
			while (i < 45000000)
				i++;
			test->button.time = 1;
		}
		else if (test->button.time % 2 == 1)
		{
			draw_walls(test);
			draw_floors(test);
			draw_furnitures(test);
			draw_collectibles(test);
			draw_trap(test);
			if (test->param.map[test->player.pos_i][test->player.pos_j + 1] == 'C')
				test->player.side = &test->player.rightside;
			else if (test->param.map[test->player.pos_i][test->player.pos_j - 1] == 'C')
				test->player.side = &test->player.leftside;
			else if (test->param.map[test->player.pos_i - 1][test->player.pos_j] == 'C')
				test->player.side = &test->player.backside;
			else if (test->param.map[test->player.pos_i + 1][test->player.pos_j] == 'C')
				test->player.side = &test->player.frontside;
			if (test->all.exit.opened == 1)
				draw_exit(test);
			draw_player(test);
			if (test->all.exit.opened == 0)
				draw_exit(test);
			draw_score(test);
			while (i < 240000000)
				i++;
			test->button.time = 0;
		}
    }
	else if (test->param.map[test->player.pos_i - 1][test->player.pos_j] == '1' && test->param.map[test->player.pos_i - 1][test->player.pos_j + 1] == '1' && test->param.map[test->player.pos_i - 1][test->player.pos_j + 2] == '0' && test->player.pos_j + 1 < test->param.width - 1 && test->param.map[test->player.pos_i - 1][test->player.pos_j - 1] == '1' && test->param.map[test->player.pos_i - 1][test->player.pos_j - 2] == '0')
	{
		if (test->button.time % 2 == 0 && test->player.lock_pos == 0)
		{
        	draw_on_image(test, &test->button.p_key, test->player.pos_x + 32, test->player.pos_y - 42);
			while (i < 45000000)
				i++;
			test->button.time = 1;
		}
		else if (test->button.time % 2 == 1)
		{
			draw_walls(test);
			draw_floors(test);
			draw_furnitures(test);
			draw_collectibles(test);
			draw_trap(test);
			test->player.side = &test->player.backside;
			if (test->all.exit.opened == 1)
				draw_exit(test);
			draw_player(test);
			if (test->all.exit.opened == 0)
				draw_exit(test);
			draw_score(test);
			while (i < 240000000)
				i++;
			test->button.time = 0;
		}
	}
	else if (test->collec.exit == 1 && test->all.exit.opened == 0)
	{
		if (test->button.time % 2 == 0)
		{
        	draw_on_image(test, &test->button.o_key, test->player.pos_x + 32, test->player.pos_y - 42);
			while (i < 45000000)
				i++;
			test->button.time = 1;
			test->player.lock_pos = 1;
		}
		else if (test->button.time % 2 == 1)
		{
			draw_walls(test);
			draw_floors(test);
			draw_furnitures(test);
			draw_collectibles(test);
			draw_trap(test);
			if (test->all.exit.opened == 1)
				draw_exit(test);
			draw_player(test);
			if (test->all.exit.opened == 0)
				draw_exit(test);
			draw_score(test);
			while (i < 240000000)
				i++;
			test->button.time = 0;
		}
	}
}

void	print_box(t_test *test)
{
	draw_on_image(test, &test->dialog_box.left, (test->param.width/2-2) * 64, (test->param.height) * 64);
	draw_on_image(test, &test->dialog_box.mid, (test->param.width/2-1) * 64, (test->param.height) * 64);
	draw_on_image(test, &test->dialog_box.mid, (test->param.width/2) * 64, (test->param.height) * 64);
	draw_on_image(test, &test->dialog_box.mid, (test->param.width/2+1) * 64, (test->param.height) * 64);
	draw_on_image(test, &test->dialog_box.right, (test->param.width/2+2) * 64, (test->param.height) * 64);
}

void 	draw_dialog_box(t_test *test)
{
	print_box(test);
	if (test->dialog_box.event == 1)
	{
		mlx_string_put(test->mlx, test->win, (test->param.width/2-2) * 64 + 4, (test->param.height) * 64 + 16, 0xf4fefe, "Hmm strange... This piano seems to be perfectly");
		mlx_string_put(test->mlx, test->win, (test->param.width/2-2) * 64 + 4, (test->param.height) * 64 + 32, 0xf4fefe, "working...");
		test->player.lock_pos = 1;
	}
	else if (test->dialog_box.event == 2)
	{
		mlx_string_put(test->mlx, test->win, (test->param.width/2-2) * 64 + 4, (test->param.height) * 64 + 16, 0xf4fefe, "You have 1 new item in your inventory!");
		test->player.lock_pos = 1;
	}
	else if (test->dialog_box.event == 3)
	{
		mlx_string_put(test->mlx, test->win, (test->param.width/2-2) * 64 + 4, (test->param.height) * 64 + 16, 0xf4fefe, "I should take all the newspaper reports with me");
		mlx_string_put(test->mlx, test->win, (test->param.width/2-2) * 64 + 4, (test->param.height) * 64 + 32, 0xf4fefe, "before I go further..");
		test->player.lock_pos = 1;
	}
	mlx_string_put(test->mlx, test->win, (test->param.width/2+1) * 64 + 8, (test->param.height) * 64 + 32 + 16 + 5, 0xf4fefe, "Press C to continue");
}

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

void 	draw_all_together(t_test *test)
{
	draw_background(test);
	draw_walls(test);
	draw_floors(test);
	draw_furnitures(test);
	draw_collectibles(test);
	draw_trap(test);
	if (test->param.rendered == 0)
		test->player.side = &test->player.frontside;
	if (test->all.exit.opened == 1)
		draw_exit(test);
	draw_player(test);
	if (test->all.exit.opened == 0)
		draw_exit(test);
	mlx_put_image_to_window(test->mlx, test->win, test->data.img, 0, 0);
	draw_score(test);
	draw_button(test);
	test->param.rendered = 1;
	if (test->dialog_box.keep == 1)
		draw_dialog_box(test);
	draw_life(test);
}

int    render(t_test *test)
{
	if ((test->intro_or_not == 1 || test->intro_or_not == 2 || test->intro_or_not == 3 || test->intro_or_not == 4 || test->intro_or_not == 5) && test->param.width_with_x*64-(2*64) == 960 && (test->param.height-2)*64+3*64 == 448)
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

void	play_piano(t_test *test)
{
	if (test->player.pos_i != 1 && test->param.map[test->player.pos_i - 1][test->player.pos_j] == '1' && test->param.map[test->player.pos_i - 1][test->player.pos_j + 1] == '1' && test->param.map[test->player.pos_i - 1][test->player.pos_j + 2] == '0' && test->player.pos_j + 1 < test->param.width - 1 && test->param.map[test->player.pos_i - 1][test->player.pos_j - 1] == '1' && test->param.map[test->player.pos_i - 1][test->player.pos_j - 2] == '0')
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

int     handle_keypress(int keysym, t_test *test)
{
	if (test->intro_or_not == 0)
	{
    	if (keysym == ESC)
	   		clean_exit(test);
    	else if (keysym == D)
	    	move_right(test);
    	else if (keysym == A)
	    	move_left(test);
    	else if (keysym == W)
	    	move_up(test);
   		else if (keysym == S)
	    	move_down(test);
		else if (keysym == E)
			pick_up_coll(test);
		else if (keysym == P)
			play_piano(test);
		else if (keysym == C)
			clean_dialog(test);
		else if (keysym == O && test->collec.count == test->collec.amount)
			open_trapdoor(test);
		else if (keysym != ESC)
        	write(1, &keysym, 1);
	}
	else
	{
		if (keysym == SPACE && test->intro_or_not == 1)
			test->intro_or_not++;
		else if (keysym == SPACE && test->intro_or_not == 2)
			test->intro_or_not++;
		else if (keysym == SPACE && test->intro_or_not == 3)
			test->intro_or_not++;
		else if (keysym == SPACE && test->intro_or_not == 4)
			test->intro_or_not++;
		else if (keysym == SPACE && test->intro_or_not == 5)
			test->intro_or_not = 0;
		else if (keysym == ESC)
	   		clean_exit(test);
		else
        	write(1, &keysym, 1);
	}
    return (0);
}

int	close_win_cross(t_test *test)
{
	mlx_loop_end (test->mlx);
	clean_exit(test);
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

int main(int ac, char **av)
{
    t_test test;

	get_map(&test, ac, av);
    test.mlx = mlx_init();
    test.win = mlx_new_window(test.mlx, test.param.width_with_x*64-(2*64), (test.param.height-2)*64+3*64, "so_short on time!");
    test.data.img = mlx_new_image(test.mlx, test.param.width_with_x*64-(2*64), (test.param.height-2)*64+3*64);
    test.data.addr = mlx_get_data_addr(test.data.img, &test.data.bits_per_pixel, &test.data.line_length, &test.data.endian);
	get_all_images_and_addresses(&test);
	mlx_hook(test.win, 2, 1L << 0, &handle_keypress, &test);
	mlx_loop_hook(test.mlx, render, &test);
	mlx_hook(test.win, 17, 1L << 0, &close_win_cross, &test);
    mlx_loop(test.mlx);
    return (0);
}
