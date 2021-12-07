/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:26:58 by esafar            #+#    #+#             */
/*   Updated: 2021/12/07 20:27:11 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_game_keypress(t_test *test, int keysym)
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

void	check_intro_keypress(t_test *test, int keysym)
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
int	handle_keypress(int keysym, t_test *test)
{
	if (test->intro_or_not == 0)
		check_game_keypress(test, keysym);
	else
		check_intro_keypress(test, keysym);
    return (0);
}