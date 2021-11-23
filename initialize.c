#include "so_long.h"

void	initialize(t_test *test)
{
	test->mlx = NULL;
	test->win = NULL;
	test->param.map = NULL;
	test->param.height = 0;
	test->param.width = 0;
	test->param.width_with_x = 0;
}
