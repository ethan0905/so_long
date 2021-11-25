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

void	draw_on_image(t_test *test, t_data *img, int startx, int starty)
{
	int tex_x = 0;
	int tex_y = 0;
	int	x, y = 0;
	double ratio_x;
	double ratio_y;

	ratio_x = 1.0f;
	ratio_y = 1.0f;
	while (y < 64)
	{
		tex_y = (int)((double)y * ratio_y);
		x = 0;
		while (x < 64)
		{
			tex_x = (int)((double)x * ratio_x);
			if (get_pixel(img, tex_x, tex_y) != (int)0xFF000000)
				my_mlx_pixel_put(test, x + startx, y + starty, get_pixel(img, tex_x, tex_y));
			// printf("seg ici \n");
			// fflush(stdout);
			x++;
		}
		y++;
	}
}

void	draw_on_image_bis(t_test *test, t_data *img, int startx, int starty)
{
	int tex_x = 0;
	int tex_y = 0;
	int	x, y = 0;
	double ratio_x;
	double ratio_y;

	ratio_x = 1.0f;
	ratio_y = 1.0f;
	while (y < 128)
	{
		tex_y = (int)((double)y * ratio_y);
		x = 0;
		while (x < 128)
		{
			tex_x = (int)((double)x * ratio_x);
			if (get_pixel(img, tex_x, tex_y) != (int)0xFF000000)
				my_mlx_pixel_put(test, x + startx, y + starty, get_pixel(img, tex_x, tex_y));
			// printf("seg ici \n");
			// fflush(stdout);
			x++;
		}
		y++;
	}
}

void draw_background(t_test *test)
{
    int y;
    int x;

    y = 0;
    x = 0;
    while (y < (test->param.height-2)*64+3*64)
    {
        x = 0;
        while (x < test->param.width_with_x*64-(2*64))
        {
            my_mlx_pixel_put(test, x, y, 0xFF000000);
            x++;
        }
        y++;
    }
}

void draw_walls(t_test *test)
{
    int y;
    int x;

    y = 0;
    while (y < 3)
    {
    	x = test->param.width_with_x - test->param.width-1;
        while (x < test->param.width_with_x - 2)
        {
    		draw_on_image(test, &test->all.wall, x * 64, y *64);
            x++;
        }
        y++;
    }
}

void draw_floors(t_test *test)
{
    int y;
    int x;
	int count;

    y = 0;
	count = 0;
    while (y < test->param.height - 2)
    {
    	x = test->param.width_with_x - test->param.width - count - 1 - 1;
        while (x < test->param.width_with_x - 2 - count)
        {
			if (x == test->param.width_with_x - test->param.width - count - 1 - 1)
    			draw_on_image(test, &test->all.floor_half_right, x * 64, 3*64 + y *64);
			else if (x == test->param.width_with_x - 2 - count - 1)
    			draw_on_image(test, &test->all.floor_half_left, x * 64, 3*64 + y *64);
			else
    			draw_on_image(test, &test->all.floor, x * 64, 3*64 + y *64);
            x++;
        }
		count++;
        y++;
    }
}

// void draw_furnitures(t_test *test)
// {
// 	int y;
// 	int x;
// 	int count;
// 	int random_obj;
// 	int piano;
// 	int i;
// 	int j;

// 	y = 1;	
// 	count = 0;
// 	random_obj = 0;
// 	piano = 0;
// 	while (y + 3 < test->param.height_with_wall - 1)
// 	{
//     	x = 1;
// 		while (x + (test->param.width_with_x - test->param.width - count - 1) < test->param.width_with_x - 2 - count)
// 		{
// 			if (test->param.map[y][x] == '1' && y != 1)
// 				draw_on_image(test, &test->all.box, 3*64 + (x-1)*64 - (count*64), 3*64 + (y-1)*64);
// 			else if (test->param.map[y][x] == '1' && (test->param.map[y][x - 1] == '0' || (test->param.map[y][x - 1] == '1' && x - 1 == 0)) && (test->param.map[y][x + 1] == '0' || (test->param.map[y][x + 1] == '1' && x + 1 == test->param.width - 1)) && y == 1)
// 			{
// 				if (random_obj == 0)
// 					draw_on_image(test, &test->all.pot, 3*64 + (x-1)*64 - (count*64), 3*64 + (y-1)*64 - 32);
// 				else if (random_obj == 1)
// 					draw_on_image(test, &test->all.cardboard, 3*64 + (x-1)*64 - (count*64), 3*64 + (y-1)*64 - 32 + 10);
// 				random_obj++;
// 			}
// 			else if (test->param.map[y][x] == '1' && test->param.map[y][x + 1] == '1' && x + 1 != test->param.width - 1 && (test->param.map[y][x-1] == '0' || (test->param.map[y][x-1] == '1' && x - 1 == 0)) && (test->param.map[y][x + 2] == '0' || (test->param.map[y][x + 2] == '1' && x + 2 == test->param.width - 1)))
// 			{
// 					draw_on_image(test, &test->all.dresser_downleft, 3*64 + (x-1)*64 - (count*64) + 8, 3*64 + (y-1)*64 - 22);
// 					draw_on_image(test, &test->all.dresser_downright, 3*64 + (x-1)*64 - (count*64) + 64 + 8, 3*64 + (y-1)*64 - 22);
// 					draw_on_image(test, &test->all.dresser_topleft, 3*64 + (x-1)*64 - (count*64) + 8, 3*64 + (y-1)*64 - 64 - 22);
// 					draw_on_image(test, &test->all.dresser_topright, 3*64 + (x-1)*64 - (count*64) + 64 + 8, 3*64 + (y-1)*64 - 64 - 22);
// 			}
// 			else if (test->param.map[y][x] == '1' && test->param.map[y][x + 1] == '1' && test->param.map[y][x + 2] == '1' && x + 1 != test->param.width - 1 && (test->param.map[y][x-1] == '0' || (test->param.map[y][x-1] == '1' && x - 1  == 0)) && (test->param.map[y][x + 3] == '0' || (test->param.map[y][x + 3] == '1' && x + 3 == test->param.width - 1)))
// 			{
// 					if (piano == 0)
// 					{
// 							draw_on_image(test, &test->all.piano.downleft, 3*64 + (x-1)*64 - (count*64) + 8, 3*64 + (y-1)*64 - 22);
// 							draw_on_image(test, &test->all.piano.midleft, 3*64 + (x-1)*64 - (count*64) + 8, 3*64 + (y-1)*64 - 22 - 64);
// 							draw_on_image(test, &test->all.piano.topleft, 3*64 + (x-1)*64 - (count*64) + 8 + 9, 3*64 + (y-1)*64 - 22 - 128);
// 							draw_on_image(test, &test->all.piano.downmid, 3*64 + (x-1)*64 - (count*64) + 8 + 64, 3*64 + (y-1)*64 - 22);
// 							draw_on_image(test, &test->all.piano.midmid, 3*64 + (x-1)*64 - (count*64) + 8 + 64, 3*64 + (y-1)*64 - 22 - 64);
// 							draw_on_image(test, &test->all.piano.topmid, 3*64 + (x-1)*64 - (count*64) + 8 + 64, 3*64 + (y-1)*64 - 22 - 128);
// 							draw_on_image(test, &test->all.piano.downright, 3*64 + (x-1)*64 - (count*64) + 8 + 128, 3*64 + (y-1)*64 - 22);
// 							draw_on_image(test, &test->all.piano.midright, 3*64 + (x-1)*64 - (count*64) + 8 + 128, 3*64 + (y-1)*64 - 22 - 64);
// 							draw_on_image(test, &test->all.piano.topright, 3*64 + (x-1)*64 - (count*64) + 8 + 128, 3*64 + (y-1)*64 - 22 - 128);
// 							piano++;
// 					}
// 					else
// 					{
// 							draw_on_image(test, &test->all.pot, 3*64 + (x-1)*64 - (count*64), 3*64 + (y-1)*64 - 32);
// 							draw_on_image(test, &test->all.pot, 3*64 + (x-1)*64 - (count*64) + 64, 3*64 + (y-1)*64 - 32);
// 							draw_on_image(test, &test->all.pot, 3*64 + (x-1)*64 - (count*64) + 128, 3*64 + (y-1)*64 - 32);
// 					}
// 			}
// 			else if (test->param.map[y][x] == '1' && test->param.map[y][x + 1] == '1' && test->param.map[y][x + 2] == '1' && test->param.map[y][x + 3] == '1')
// 			{
// 				i = x;
// 				while (test->param.map[y][i] == '1')
// 					i++;
// 				j = i;
// 				i = 0;
// 				while (i + 1 < j - x)
// 				{
// 					draw_on_image(test, &test->all.pot, 3*64 + (x-1)*64 - (count*64) + (i * 64), 3*64 + (y-1)*64 - 32);
// 					i++;
// 				}
// 				// printf("i vaut : %d\n", i);
// 				// printf("j vaut : %d\n", j);
// 				// printf("XXXXXXXXXXX vaut : %d\n", x);
// 				if (j != test->param.width)
// 					draw_on_image(test, &test->all.pot, 3*64 + (x-1)*64 - (count*64) + (i * 64), 3*64 + (y-1)*64 - 32);
// 			}
// 			x++;
// 		}
// 		count++;
// 		y++;
// 	}
// }

void draw_furnitures(t_test *test)
{
	int y;
	int x;
	int count;
	int random_obj;
	int piano;
	int i;
	int j;

	y = 1;	
	count = 0;
	random_obj = 0;
	piano = 0;
	while (y + 3 < test->param.height_with_wall - 1)
	{
    	x = 1;
		while (x + (test->param.width_with_x - test->param.width - count - 1) < test->param.width_with_x - 2 - count)
		{
			if (test->param.map[y][x] == '1' && y != 1)
				draw_on_image(test, &test->all.box, 3*64 + (x-1)*64 - (count*64), 3*64 + (y-1)*64);
			else if (test->param.map[y][x] == '1' && ((test->param.map[y][x - 1] == '0' || test->param.map[y][x - 1] == 'P') || (test->param.map[y][x - 1] == '1' && x - 1 == 0)) && ((test->param.map[y][x + 1] == '0' || test->param.map[y][x + 1] == 'P') || (test->param.map[y][x + 1] == '1' && x + 1 == test->param.width - 1)) && y == 1)
			{
				if (random_obj == 0)
					draw_on_image(test, &test->all.pot, 3*64 + (x-1)*64 - (count*64), 3*64 + (y-1)*64 - 32);
				else if (random_obj == 1)
					draw_on_image(test, &test->all.cardboard, 3*64 + (x-1)*64 - (count*64), 3*64 + (y-1)*64 - 32 + 10);
				random_obj++;
			}
			else if (test->param.map[y][x] == '1' && test->param.map[y][x + 1] == '1' && x + 1 != test->param.width - 1 && ((test->param.map[y][x-1] == '0' || test->param.map[y][x-1] == 'P') || (test->param.map[y][x-1] == '1' && x - 1 == 0)) && ((test->param.map[y][x + 2] == '0' || test->param.map[y][x + 2] == 'P') || (test->param.map[y][x + 2] == '1' && x + 2 == test->param.width - 1)))
			{
					draw_on_image(test, &test->all.dresser_downleft, 3*64 + (x-1)*64 - (count*64) + 8, 3*64 + (y-1)*64 - 22);
					draw_on_image(test, &test->all.dresser_downright, 3*64 + (x-1)*64 - (count*64) + 64 + 8, 3*64 + (y-1)*64 - 22);
					draw_on_image(test, &test->all.dresser_topleft, 3*64 + (x-1)*64 - (count*64) + 8, 3*64 + (y-1)*64 - 64 - 22);
					draw_on_image(test, &test->all.dresser_topright, 3*64 + (x-1)*64 - (count*64) + 64 + 8, 3*64 + (y-1)*64 - 64 - 22);
			}
			else if (test->param.map[y][x] == '1' && test->param.map[y][x + 1] == '1' && test->param.map[y][x + 2] == '1' && x + 1 != test->param.width - 1 && ((test->param.map[y][x-1] == '0' || test->param.map[y][x-1] == 'P') || (test->param.map[y][x-1] == '1' && x - 1  == 0)) && ((test->param.map[y][x + 3] == '0' || test->param.map[y][x + 3] == 'P') || (test->param.map[y][x + 3] == '1' && x + 3 == test->param.width - 1)))
			{
					if (piano == 0)
					{
							draw_on_image(test, &test->all.piano.downleft, 3*64 + (x-1)*64 - (count*64) + 8, 3*64 + (y-1)*64 - 22);
							draw_on_image(test, &test->all.piano.midleft, 3*64 + (x-1)*64 - (count*64) + 8, 3*64 + (y-1)*64 - 22 - 64);
							draw_on_image(test, &test->all.piano.topleft, 3*64 + (x-1)*64 - (count*64) + 8 + 9, 3*64 + (y-1)*64 - 22 - 128);
							draw_on_image(test, &test->all.piano.downmid, 3*64 + (x-1)*64 - (count*64) + 8 + 64, 3*64 + (y-1)*64 - 22);
							draw_on_image(test, &test->all.piano.midmid, 3*64 + (x-1)*64 - (count*64) + 8 + 64, 3*64 + (y-1)*64 - 22 - 64);
							draw_on_image(test, &test->all.piano.topmid, 3*64 + (x-1)*64 - (count*64) + 8 + 64, 3*64 + (y-1)*64 - 22 - 128);
							draw_on_image(test, &test->all.piano.downright, 3*64 + (x-1)*64 - (count*64) + 8 + 128, 3*64 + (y-1)*64 - 22);
							draw_on_image(test, &test->all.piano.midright, 3*64 + (x-1)*64 - (count*64) + 8 + 128, 3*64 + (y-1)*64 - 22 - 64);
							draw_on_image(test, &test->all.piano.topright, 3*64 + (x-1)*64 - (count*64) + 8 + 128, 3*64 + (y-1)*64 - 22 - 128);
							piano++;
					}
					else
					{
							draw_on_image(test, &test->all.pot, 3*64 + (x-1)*64 - (count*64), 3*64 + (y-1)*64 - 32);
							draw_on_image(test, &test->all.pot, 3*64 + (x-1)*64 - (count*64) + 64, 3*64 + (y-1)*64 - 32);
							draw_on_image(test, &test->all.pot, 3*64 + (x-1)*64 - (count*64) + 128, 3*64 + (y-1)*64 - 32);
					}
			}
			else if (test->param.map[y][x] == '1' && test->param.map[y][x + 1] == '1' && test->param.map[y][x + 2] == '1' && test->param.map[y][x + 3] == '1')
			{
				i = x;
				while (test->param.map[y][i] == '1')
					i++;
				j = i;
				i = 0;
				while (i + 1 < j - x)
				{
					draw_on_image(test, &test->all.pot, 3*64 + (x-1)*64 - (count*64) + (i * 64), 3*64 + (y-1)*64 - 32);
					i++;
				}
				// printf("i vaut : %d\n", i);
				// printf("j vaut : %d\n", j);
				// printf("XXXXXXXXXXX vaut : %d\n", x);
				if (j != test->param.width)
					draw_on_image(test, &test->all.pot, 3*64 + (x-1)*64 - (count*64) + (i * 64), 3*64 + (y-1)*64 - 32);
			}
			x++;
		}
		count++;
		y++;
	}
}

void draw_collectibles(t_test *test)
{
	int y;
	int x;
	int count;

	y = 1;	
	count = 0;
	while (y + 3 < test->param.height_with_wall - 1)
	{
    	x = 1;
		while (x + (test->param.width_with_x - test->param.width - count - 1) < test->param.width_with_x - 2 - count)
		{
			if (test->param.map[y][x] == 'C')
				draw_on_image(test, &test->all.newspaper, 3*64 + (x-1)*64 - (count*64), 3*64 + (y-1)*64);
			x++;
		}
		count++;
		y++;
	}
}

void draw_exit(t_test *test)
{
	int y;
	int x;
	int count;

	y = 1;	
	count = 0;
	while (y + 3 < test->param.height_with_wall - 1)
	{
    	x = 1;
		while (x + (test->param.width_with_x - test->param.width - count - 1) < test->param.width_with_x - 2 - count)
		{
			if (test->param.map[y][x] == 'E')
			{
				draw_on_image(test, &test->all.exit_half_right, 3*64 + (x-1)*64 - (count*64) + 32, 3*64 + (y-1)*64 + 2);
				draw_on_image(test, &test->all.exit_half_left, 3*64 + (x-1)*64 - (count*64) + 32-64 + 4, 3*64 + (y-1)*64 + 2);
			}
			x++;
		}
		count++;
		y++;
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
				// ORIGINAL SET UP PLAYER

				test->player.pos_x = (j-1)*64 + 30 + (test->param.height - 3) * 64 - (i-1)*64; 
				test->player.pos_y = 3 * 64 + (i-1) * 64 - 64 - 25 + 10;

				//
			}
			j++;
		}
		i++;
	}
	// printf("pos i : %d\n", test->player.pos_i);
	// printf("pos j : %d\n", test->player.pos_j);
	// printf("pos x : %d\n", test->player.pos_x);
	// printf("pos y : %d\n", test->player.pos_y);
}

void draw_player(t_test *test)
{
	get_pos_player(test);
	draw_on_image_bis(test, test->player.side, test->player.pos_x, test->player.pos_y);
}

int    render(t_test *test)
{
	if (test->param.rendered == 0)
	{
		draw_background(test);
		draw_walls(test);
		draw_floors(test);
		draw_furnitures(test);
		draw_collectibles(test);
		draw_exit(test);
		test->player.side = &test->player.frontside;
		draw_player(test);
		test->param.rendered++;
	}
	else if (test->param.rendered == 1)
	{
		draw_background(test);
		draw_walls(test);
		draw_floors(test);
		draw_furnitures(test);
		draw_collectibles(test);
		draw_exit(test);
		draw_player(test);
	}
	mlx_put_image_to_window(test->mlx, test->win, test->data.img, 0, 0);
	return (0);
}

int     handle_keypress(int keysym, t_test *test)
{	
    if (keysym == ESC)
    {
	    clean_exit(test);
    }
    else if (keysym == D)
	    move_right(test);
    else if (keysym == A)
	    move_left(test);
    else if (keysym == W)
	    move_up(test);
    else if (keysym == S)
	    move_down(test);
    else if (keysym != ESC)
        write(1, &keysym, 1);
    return (0);
}

int main(int ac, char **av)
{
    t_test test;
///////////////////////////// RECUP MA MAP DANS TAB
	
	get_map(&test, ac, av);

///////////////

    test.mlx = mlx_init();
    test.win = mlx_new_window(test.mlx, test.param.width_with_x*64-(2*64), (test.param.height-2)*64+3*64, "so_short for now");
    test.data.img = mlx_new_image(test.mlx, test.param.width_with_x*64-(2*64), (test.param.height-2)*64+3*64);
    test.data.addr = mlx_get_data_addr(test.data.img, &test.data.bits_per_pixel, &test.data.line_length, &test.data.endian);

    test.all.wall.img = mlx_xpm_file_to_image(test.mlx, "textures/wall.xpm", &test.all.wall.x, &test.all.wall.y);
    test.all.wall.addr = mlx_get_data_addr(test.all.wall.img, &test.all.wall.bits_per_pixel, &test.all.wall.line_length, &test.all.wall.endian);

    test.all.floor.img = mlx_xpm_file_to_image(test.mlx, "textures/floor.xpm", &test.all.floor.x, &test.all.floor.y);
    test.all.floor.addr = mlx_get_data_addr(test.all.floor.img, &test.all.floor.bits_per_pixel, &test.all.floor.line_length, &test.all.floor.endian);

    test.all.floor_half_right.img = mlx_xpm_file_to_image(test.mlx, "textures/floor_half_right.xpm", &test.all.floor_half_right.x, &test.all.floor_half_right.y);
    test.all.floor_half_right.addr = mlx_get_data_addr(test.all.floor_half_right.img, &test.all.floor_half_right.bits_per_pixel, &test.all.floor_half_right.line_length, &test.all.floor_half_right.endian);
    test.all.floor_half_left.img = mlx_xpm_file_to_image(test.mlx, "textures/floor_half_left.xpm", &test.all.floor_half_left.x, &test.all.floor_half_left.y);
    test.all.floor_half_left.addr = mlx_get_data_addr(test.all.floor_half_left.img, &test.all.floor_half_left.bits_per_pixel, &test.all.floor_half_left.line_length, &test.all.floor_half_left.endian);

    test.all.box.img = mlx_xpm_file_to_image(test.mlx, "textures/box.xpm", &test.all.box.x, &test.all.box.y);
    test.all.box.addr = mlx_get_data_addr(test.all.box.img, &test.all.box.bits_per_pixel, &test.all.box.line_length, &test.all.box.endian);
    test.all.pot.img = mlx_xpm_file_to_image(test.mlx, "textures/pot.xpm", &test.all.pot.x, &test.all.pot.y);
    test.all.pot.addr = mlx_get_data_addr(test.all.pot.img, &test.all.pot.bits_per_pixel, &test.all.pot.line_length, &test.all.pot.endian);
    test.all.cardboard.img = mlx_xpm_file_to_image(test.mlx, "textures/cardboard.xpm", &test.all.cardboard.x, &test.all.cardboard.y);
    test.all.cardboard.addr = mlx_get_data_addr(test.all.cardboard.img, &test.all.cardboard.bits_per_pixel, &test.all.cardboard.line_length, &test.all.cardboard.endian);
    test.all.dresser_topright.img = mlx_xpm_file_to_image(test.mlx, "textures/dresser3_topright.xpm", &test.all.dresser_topright.x, &test.all.dresser_topright.y);
    test.all.dresser_topright.addr = mlx_get_data_addr(test.all.dresser_topright.img, &test.all.dresser_topright.bits_per_pixel, &test.all.dresser_topright.line_length, &test.all.dresser_topright.endian);
    test.all.dresser_topleft.img = mlx_xpm_file_to_image(test.mlx, "textures/dresser3_topleft.xpm", &test.all.dresser_topleft.x, &test.all.dresser_topleft.y);
    test.all.dresser_topleft.addr = mlx_get_data_addr(test.all.dresser_topleft.img, &test.all.dresser_topleft.bits_per_pixel, &test.all.dresser_topleft.line_length, &test.all.dresser_topleft.endian);
    test.all.dresser_downright.img = mlx_xpm_file_to_image(test.mlx, "textures/dresser3_downright.xpm", &test.all.dresser_downright.x, &test.all.dresser_downright.y);
    test.all.dresser_downright.addr = mlx_get_data_addr(test.all.dresser_downright.img, &test.all.dresser_downright.bits_per_pixel, &test.all.dresser_downright.line_length, &test.all.dresser_downright.endian);
    test.all.dresser_downleft.img = mlx_xpm_file_to_image(test.mlx, "textures/dresser3_downleft.xpm", &test.all.dresser_downleft.x, &test.all.dresser_downleft.y);
    test.all.dresser_downleft.addr = mlx_get_data_addr(test.all.dresser_downleft.img, &test.all.dresser_downleft.bits_per_pixel, &test.all.dresser_downleft.line_length, &test.all.dresser_downleft.endian);
    
// PIANO /////
	test.all.piano.topright.img = mlx_xpm_file_to_image(test.mlx, "textures/piano_topright.xpm", &test.all.piano.topright.x, &test.all.piano.topright.y);
    test.all.piano.topright.addr = mlx_get_data_addr(test.all.piano.topright.img, &test.all.piano.topright.bits_per_pixel, &test.all.piano.topright.line_length, &test.all.piano.topright.endian);
    test.all.piano.topmid.img = mlx_xpm_file_to_image(test.mlx, "textures/piano_topmid.xpm", &test.all.piano.topmid.x, &test.all.piano.topmid.y);
    test.all.piano.topmid.addr = mlx_get_data_addr(test.all.piano.topmid.img, &test.all.piano.topmid.bits_per_pixel, &test.all.piano.topmid.line_length, &test.all.piano.topmid.endian);
    test.all.piano.topleft.img = mlx_xpm_file_to_image(test.mlx, "textures/piano_topleft.xpm", &test.all.piano.topleft.x, &test.all.piano.topleft.y);
    test.all.piano.topleft.addr = mlx_get_data_addr(test.all.piano.topleft.img, &test.all.piano.topleft.bits_per_pixel, &test.all.piano.topleft.line_length, &test.all.piano.topleft.endian);

	test.all.piano.midright.img = mlx_xpm_file_to_image(test.mlx, "textures/piano_midright.xpm", &test.all.piano.midright.x, &test.all.piano.midright.y);
    test.all.piano.midright.addr = mlx_get_data_addr(test.all.piano.midright.img, &test.all.piano.midright.bits_per_pixel, &test.all.piano.midright.line_length, &test.all.piano.midright.endian);
    test.all.piano.midmid.img = mlx_xpm_file_to_image(test.mlx, "textures/piano_midmid.xpm", &test.all.piano.midmid.x, &test.all.piano.midmid.y);
    test.all.piano.midmid.addr = mlx_get_data_addr(test.all.piano.midmid.img, &test.all.piano.midmid.bits_per_pixel, &test.all.piano.midmid.line_length, &test.all.piano.midmid.endian);
    test.all.piano.midleft.img = mlx_xpm_file_to_image(test.mlx, "textures/piano_midleft.xpm", &test.all.piano.midleft.x, &test.all.piano.midleft.y);
    test.all.piano.midleft.addr = mlx_get_data_addr(test.all.piano.midleft.img, &test.all.piano.midleft.bits_per_pixel, &test.all.piano.midleft.line_length, &test.all.piano.midleft.endian);

	test.all.piano.downright.img = mlx_xpm_file_to_image(test.mlx, "textures/piano_downright.xpm", &test.all.piano.downright.x, &test.all.piano.downright.y);
    test.all.piano.downright.addr = mlx_get_data_addr(test.all.piano.downright.img, &test.all.piano.downright.bits_per_pixel, &test.all.piano.downright.line_length, &test.all.piano.downright.endian);
    test.all.piano.downmid.img = mlx_xpm_file_to_image(test.mlx, "textures/piano_downmid.xpm", &test.all.piano.downmid.x, &test.all.piano.downmid.y);
    test.all.piano.downmid.addr = mlx_get_data_addr(test.all.piano.downmid.img, &test.all.piano.downmid.bits_per_pixel, &test.all.piano.downmid.line_length, &test.all.piano.downmid.endian);
    test.all.piano.downleft.img = mlx_xpm_file_to_image(test.mlx, "textures/piano_downleft.xpm", &test.all.piano.downleft.x, &test.all.piano.downleft.y);
    test.all.piano.downleft.addr = mlx_get_data_addr(test.all.piano.downleft.img, &test.all.piano.downleft.bits_per_pixel, &test.all.piano.downleft.line_length, &test.all.piano.downleft.endian);
/////////////

    test.all.newspaper.img = mlx_xpm_file_to_image(test.mlx, "textures/newspaper.xpm", &test.all.newspaper.x, &test.all.newspaper.y);
    test.all.newspaper.addr = mlx_get_data_addr(test.all.newspaper.img, &test.all.newspaper.bits_per_pixel, &test.all.newspaper.line_length, &test.all.newspaper.endian);

    test.all.exit_half_left.img = mlx_xpm_file_to_image(test.mlx, "textures/ladder_half_left.xpm", &test.all.exit_half_left.x, &test.all.exit_half_left.y);
    test.all.exit_half_left.addr = mlx_get_data_addr(test.all.exit_half_left.img, &test.all.exit_half_left.bits_per_pixel, &test.all.exit_half_left.line_length, &test.all.exit_half_left.endian);
	test.all.exit_half_right.img = mlx_xpm_file_to_image(test.mlx, "textures/ladder_half_right.xpm", &test.all.exit_half_right.x, &test.all.exit_half_right.y);
    test.all.exit_half_right.addr = mlx_get_data_addr(test.all.exit_half_right.img, &test.all.exit_half_right.bits_per_pixel, &test.all.exit_half_right.line_length, &test.all.exit_half_right.endian);
	
	test.player.frontside.img = mlx_xpm_file_to_image(test.mlx, "textures/detective_frontside.xpm", &test.player.frontside.x, &test.player.frontside.y);
	test.player.frontside.addr = mlx_get_data_addr(test.player.frontside.img, &test.player.frontside.bits_per_pixel, &test.player.frontside.line_length, &test.player.frontside.endian);
	test.player.backside.img = mlx_xpm_file_to_image(test.mlx, "textures/detective_backside.xpm", &test.player.backside.x, &test.player.backside.y);
	test.player.backside.addr = mlx_get_data_addr(test.player.backside.img, &test.player.backside.bits_per_pixel, &test.player.backside.line_length, &test.player.backside.endian);
	test.player.rightside.img = mlx_xpm_file_to_image(test.mlx, "textures/detective_sideright.xpm", &test.player.rightside.x, &test.player.rightside.y);
	test.player.rightside.addr = mlx_get_data_addr(test.player.rightside.img, &test.player.rightside.bits_per_pixel, &test.player.rightside.line_length, &test.player.rightside.endian);
	test.player.leftside.img = mlx_xpm_file_to_image(test.mlx, "textures/detective_sideleft.xpm", &test.player.leftside.x, &test.player.leftside.y);
	test.player.leftside.addr = mlx_get_data_addr(test.player.leftside.img, &test.player.leftside.bits_per_pixel, &test.player.leftside.line_length, &test.player.leftside.endian);
	
	// test.player.side = &test.player.frontside;
	printf("iciiiii\n");
	mlx_hook(test.win, 2, 1L << 0, &handle_keypress, &test);
    // render(&test);
	mlx_loop_hook(test.mlx, render, &test);
    mlx_loop(test.mlx);
    return (0);
}
