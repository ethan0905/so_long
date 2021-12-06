/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:11:34 by esafar            #+#    #+#             */
/*   Updated: 2021/11/17 09:53:04 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <limits.h>
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>

# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include "./mlx/mlx.h"

# define ESC 65307
# define SPACE 32
# define W 119
# define A 97
# define S 115
# define D 100
# define E 101
# define P 112
# define C 99
# define O 111

# define BUFFER_SIZE 1
# define FRAME 250

# define ERROR -1
# define SUCCESS 1

typedef struct s_data
{
    void *img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
    int x;
    int y;
}               t_data;

typedef struct s_intro
{
    // t_data one;
    t_data two;
}              t_intro;

typedef struct s_param
{
	char **map;
	int width;
	int width_with_x;
	int height;
    int height_with_wall;
    int rendered;
}				t_param;

typedef struct s_player
{
    int pos_i;
    int lastpos_i;
    int pos_j;
    int lastpos_j;
    int pos_x;
    int pos_y;
    int steps;
    int lock_pos;
    int hurt;
    t_data frontside;
    t_data backside;
    t_data rightside;
    t_data leftside;
    t_data dmg_front;
    t_data dmg_back;
    t_data dmg_right;
    t_data dmg_left;
    t_data *side;
}              t_player;

typedef struct s_piano
{
    t_data topright;
    t_data topmid;
    t_data topleft;
    t_data midright;
    t_data midmid;
    t_data midleft;    
    t_data downright;
    t_data downmid;
    t_data downleft;
}              t_piano;

typedef struct s_exit
{
    int opened;
    t_data exit_half_right;
    t_data exit_half_left;
    t_data trapdoor_right;
    t_data trapdoor_left;
    t_data open_t_right;
    t_data open_t_left;
}              t_exit;

typedef struct s_chimney
{
    t_data bottom_right;
    t_data bottom_left;
    t_data mid_right;
    t_data mid_left;
    t_data top_right;
    t_data top_left;
}              t_chimney;

typedef struct s_fire
{
    t_data frame_one;
    t_data frame_two;
    t_data frame_three;
    t_data frame_four;
    t_data frame_five;
    t_data frame_six;
    t_data frame_seven;
    t_data frame_eight;
    t_data *frame;
}              t_fire;

typedef struct s_all
{
    int babo;
    t_data wall;
    t_data floor;
    t_data floor_half_right;
    t_data floor_half_left;
    t_data box;
    t_data pot;
    t_data cardboard;
    t_data dresser_topright;
    t_data dresser_topleft;
    t_data dresser_downright;
    t_data dresser_downleft;
    t_data babolex_painting;
    t_chimney chimney;
    t_fire fire;
    t_piano piano;
    t_exit exit;
    t_data spike;
}               t_all;

typedef struct s_collec
{
	int amount;
	int count;
	int exit;
    int random;
    t_data newspaper;
    t_data wanted;
    t_data murder_article;
}		t_collec;

typedef struct s_button
{
    int time;
    t_data e_key;
    t_data p_key;
    t_data o_key;
}		t_button;

typedef struct s_dialog
{
    int keep;
    int event;
    t_data right;
    t_data mid;
    t_data left;
}		t_dialog;

typedef struct s_stats
{
    int lives;
    int damages;
    t_data typeface_life;
    t_data full_heart;
    t_data empty_heart;
    t_data glass;
    t_data step;
}		t_stats;

typedef struct s_test
{
	void *mlx;
	void *win;
    int frame;
    int loop;
    int intro_or_not;
	t_param param;
	t_data data;
	t_all all;
	t_player player;
	t_collec collec;
    t_button button;
    t_dialog dialog_box;
    t_stats stats;
    t_intro intro;
}               t_test;

char	*get_line(char *save);
int    get_map(t_test *test, int ac, char **av);

//Init
void	initialize(t_test *test);

//MOVE
void	move_right(t_test *test);
void	move_left(t_test *test);
void	move_up(t_test *test);
void	move_down(t_test *test);

//Utils
int	get_pixel(t_data *img, int x, int y);
void	my_mlx_pixel_put(t_test *test, int x, int y, int color);
void	draw_on_image(t_test *test, t_data *img, int startx, int starty);
void	draw_on_image_bis(t_test *test, t_data *img, int startx, int starty);
void	draw_on_image_intro(t_test *test, t_data *img, int startx, int starty);
void    draw_score(t_test *test);
void 	draw_dialog_box(t_test *test);

//Exit
void	clean_exit(t_test *test);

#endif
