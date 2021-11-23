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

void draw_furnitures(t_test *test)
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
			// printf("%d | %d \n", x, y);
			if (test->param.map[y][x] == '1')
			{
				// printf("Un 1 est ici !\n");
				draw_on_image(test, &test->all.box, 3*64 + (x-1)*64 - (count*64), 3*64 + (y-1)*64);
			}
			x++;
		}
		count++;
		y++;
	}
}

int    render(t_test *test)
{  
	draw_background(test);
	draw_walls(test);
	draw_floors(test);
	draw_furnitures(test);
    mlx_put_image_to_window(test->mlx, test->win, test->data.img, 0, 0);
	return (0);
}

int     handle_keypress(int keysym, t_test *test)
{	
    if (keysym == 65307)
    {
	    clean_exit(test);
    }
    else if (keysym != 65307)
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

    test.all.floor.img = mlx_xpm_file_to_image(test.mlx, "textures/book.xpm", &test.all.floor.x, &test.all.floor.y);
    test.all.floor.addr = mlx_get_data_addr(test.all.floor.img, &test.all.floor.bits_per_pixel, &test.all.floor.line_length, &test.all.floor.endian);

    test.all.floor_half_right.img = mlx_xpm_file_to_image(test.mlx, "textures/floor_half_right.xpm", &test.all.floor_half_right.x, &test.all.floor_half_right.y);
    test.all.floor_half_right.addr = mlx_get_data_addr(test.all.floor_half_right.img, &test.all.floor_half_right.bits_per_pixel, &test.all.floor_half_right.line_length, &test.all.floor_half_right.endian);
    test.all.floor_half_left.img = mlx_xpm_file_to_image(test.mlx, "textures/floor_half_left.xpm", &test.all.floor_half_left.x, &test.all.floor_half_left.y);
    test.all.floor_half_left.addr = mlx_get_data_addr(test.all.floor_half_left.img, &test.all.floor_half_left.bits_per_pixel, &test.all.floor_half_left.line_length, &test.all.floor_half_left.endian);

    test.all.box.img = mlx_xpm_file_to_image(test.mlx, "textures/box.xpm", &test.all.box.x, &test.all.box.y);
    test.all.box.addr = mlx_get_data_addr(test.all.box.img, &test.all.box.bits_per_pixel, &test.all.box.line_length, &test.all.box.endian);

	if (!test.all.box.img)
		printf("pas ok\n");
	if (!test.all.box.addr)
		printf("pas ok\n");

	mlx_hook(test.win, 2, 1L << 0, &handle_keypress, &test);
    // render(&test);
	mlx_loop_hook(test.mlx, render, &test);
    mlx_loop(test.mlx);
    return (0);
}
