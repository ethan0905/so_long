#include "../so_long.h"

void init_stats(t_test *test)
{
	test->stats.lives = 3;
	test->stats.damages = 0;
	test->stats.typeface_life.img = NULL;
	test->stats.typeface_life.addr = NULL;
	test->stats.full_heart.img = NULL;
	test->stats.full_heart.addr = NULL;
	test->stats.empty_heart.img = NULL;
	test->stats.empty_heart.addr = NULL;
	test->stats.glass.img = NULL;
	test->stats.glass.addr = NULL;
	test->stats.step.img = NULL;
	test->stats.step.addr = NULL;
}

void	init_event(t_test *test)
{
	test->button.time = 0;
	test->button.e_key.img = NULL;
	test->button.e_key.addr = NULL;
	test->button.p_key.img = NULL;
	test->button.p_key.addr = NULL;
	test->button.o_key.img = NULL;
	test->button.o_key.addr = NULL;
	test->dialog_box.keep = 0;
	test->dialog_box.right.img = NULL;
	test->dialog_box.right.addr = NULL;
	test->dialog_box.mid.img = NULL;
	test->dialog_box.mid.addr = NULL;
	test->dialog_box.left.img = NULL;
	test->dialog_box.left.addr = NULL;
}

void	init_param(t_test *test)
{
	test->param.map = NULL;
	test->param.height = 0;
	test->param.height_with_wall = 0;
 	test->param.width = 0;
	test->param.width_with_x = 0;
	test->param.rendered = 0;
}
void	init_intro(t_test *test)
{
	test->intro.one.img = NULL;
	test->intro.one.addr = NULL;
	test->intro.two.img = NULL;
	test->intro.two.addr = NULL;
	test->intro.three.img = NULL;
	test->intro.three.addr = NULL;
	test->intro.four.img = NULL;
	test->intro.four.addr = NULL;
	test->intro.five.img = NULL;
	test->intro.five.addr = NULL;
}

void	init_player_pos(t_test *test)
{
	test->player.pos_i = 0;
	test->player.lastpos_i = 0;
	test->player.hurt = 0;
	test->player.pos_j = 0;
	test->player.lastpos_j = 0;
	test->player.pos_x = 0;
	test->player.pos_y = 0;
	test->player.steps = 0;
	test->player.lock_pos = 0;
}

void	init_player(t_test *test)
{
	init_player_pos(test);
	test->player.frontside.img = NULL;
	test->player.frontside.addr = NULL;
	test->player.backside.img = NULL;
	test->player.backside.addr = NULL;
	test->player.rightside.img = NULL;
	test->player.rightside.addr = NULL;
	test->player.leftside.img = NULL;
	test->player.leftside.addr = NULL;
	test->player.dmg_front.img = NULL;
	test->player.dmg_front.addr = NULL;
	test->player.dmg_back.img = NULL;
	test->player.dmg_back.addr = NULL;
	test->player.dmg_right.img = NULL;
	test->player.dmg_right.addr = NULL;
	test->player.dmg_left.img = NULL;
	test->player.dmg_left.addr = NULL;
}

void	init_chimney_dresser(t_test *test)
{
	test->all.dresser_downleft.img = NULL;
	test->all.dresser_downleft.addr = NULL;  
	test->all.dresser_downright.img = NULL;
	test->all.dresser_downright.addr = NULL; 
	test->all.dresser_topleft.img = NULL;
	test->all.dresser_topleft.addr = NULL;   
	test->all.dresser_topright.img = NULL;
	test->all.dresser_topright.addr = NULL;
	test->all.chimney.bottom_right.img = NULL;
	test->all.chimney.bottom_right.addr = NULL;
	test->all.chimney.bottom_left.img = NULL;
	test->all.chimney.bottom_left.addr = NULL;
	test->all.chimney.mid_right.img = NULL;
	test->all.chimney.mid_right.addr = NULL;
	test->all.chimney.mid_left.img = NULL;
	test->all.chimney.mid_left.addr = NULL;
	test->all.chimney.top_right.img = NULL;
	test->all.chimney.top_right.addr = NULL;
	test->all.chimney.top_left.img = NULL;
	test->all.chimney.top_left.addr = NULL;
}

void	init_fire(t_test *test)
{
	test->all.fire.frame_one.img = NULL;
	test->all.fire.frame_one.addr = NULL;
	test->all.fire.frame_two.img = NULL;
	test->all.fire.frame_two.addr = NULL;
	test->all.fire.frame_three.img = NULL;
	test->all.fire.frame_three.addr = NULL;
	test->all.fire.frame_four.img = NULL;
	test->all.fire.frame_four.addr = NULL;
	test->all.fire.frame_five.img = NULL;
	test->all.fire.frame_five.addr = NULL;
	test->all.fire.frame_six.img = NULL;
	test->all.fire.frame_six.addr = NULL;
	test->all.fire.frame_seven.img = NULL;
	test->all.fire.frame_seven.addr = NULL;
	test->all.fire.frame_eight.img = NULL;
	test->all.fire.frame_eight.addr = NULL;
}

void	init_collec_exit(t_test *test)
{
	test->collec.amount = 0;
	test->collec.count = 0;
	test->collec.exit = 0;
	test->collec.random = 0;
	test->collec.newspaper.img = NULL;
	test->collec.newspaper.addr = NULL;
	test->collec.wanted.img = NULL;
	test->collec.wanted.addr = NULL;
	test->all.exit.exit_half_left.img = NULL;
	test->all.exit.exit_half_left.addr = NULL;
	test->all.exit.exit_half_right.img = NULL;
	test->all.exit.exit_half_right.addr = NULL;
	test->all.exit.trapdoor_left.img = NULL;
	test->all.exit.trapdoor_left.addr = NULL;
	test->all.exit.trapdoor_right.img = NULL;
	test->all.exit.trapdoor_right.addr = NULL;
	test->all.exit.open_to_left.img = NULL;
	test->all.exit.open_to_left.addr = NULL; 
	test->all.exit.open_to_right.img = NULL;
	test->all.exit.open_to_right.addr = NULL;
	test->all.exit.opened = 0;
}

void	init_all_remain(t_test *test)
{
	test->all.wall.img = NULL;
	test->all.wall.addr = NULL;
	test->all.floor.img = NULL;
	test->all.floor.addr = NULL; 
	test->all.floor_half_left.img = NULL;
	test->all.floor_half_left.addr = NULL;   
	test->all.floor_half_right.img = NULL;
	test->all.floor_half_right.addr = NULL;  
	test->all.box.img = NULL;
	test->all.box.addr = NULL;   
	test->all.pot.img = NULL;
	test->all.pot.addr = NULL;   
	test->all.cardboard.img = NULL;
	test->all.cardboard.addr = NULL; 
	test->all.babo = 0;
	test->all.ispiano = 0;
	test->all.random_obj = 0;
	test->all.babolex_painting.img = NULL;
	test->all.babolex_painting.addr = NULL;
	test->all.spike.img = NULL;
	test->all.spike.addr = NULL;
}
void	initialize(t_test *test)
{
	test->mlx = NULL;
	test->win = NULL;
	test->frame = 0;
	test->loop = 1;
	test->intro_or_not = 1;
	test->data.img = NULL;
	test->data.addr = NULL;
	init_stats(test);
	init_event(test);
	init_param(test);
	init_intro(test);
	init_player(test);
	init_fire(test);
	init_chimney_dresser(test);
	init_collec_exit(test);
	init_all_remain(test);
}
