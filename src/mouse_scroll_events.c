#include "fractol.h"
#include <mlx.h>

void	scroll_up(int x, int y, t_data *var)
{
	double	mouse_x;
	double	mouse_y;

	mouse_x = map(var->map.min_x, var->map.max_x, x, WIN_W);
	mouse_y = map(var->map.max_y, var->map.min_y, y, WIN_H);
	var->map.min_x = mouse_x + (var->map.min_x - mouse_x) / SCALE_FACTOR;
	var->map.max_x = mouse_x + (var->map.max_x - mouse_x) / SCALE_FACTOR;
	var->map.min_y = mouse_y + (var->map.min_y - mouse_y) / SCALE_FACTOR;
	var->map.max_y = mouse_y + (var->map.max_y - mouse_y) / SCALE_FACTOR;
}

void	scroll_down(int x, int y, t_data *var)
{
	double	mouse_x;
	double	mouse_y;

	mouse_x = map(var->map.min_x, var->map.max_x, x, WIN_W);
	mouse_y = map(var->map.max_y, var->map.min_y, y, WIN_H);
	var->map.min_x = mouse_x + (var->map.min_x - mouse_x) * SCALE_FACTOR;
	var->map.max_x = mouse_x + (var->map.max_x - mouse_x) * SCALE_FACTOR;
	var->map.min_y = mouse_y + (var->map.min_y - mouse_y) * SCALE_FACTOR;
	var->map.max_y = mouse_y + (var->map.max_y - mouse_y) * SCALE_FACTOR;
}
