#include "fractol.h"
#include <mlx.h>

void	press_c(t_data *var)
{
	var->map.shift += 10.0;
	mlx_clear_window(var->mlx, var->win);
	render_set(var);
}

void	press_left(t_data *var)
{
	double	range;

	range = var->map.max_x - var->map.min_x;
	var->map.max_x -= (range * SCALE_FACTOR) - range;
	var->map.min_x -= (range * SCALE_FACTOR) - range;
	mlx_clear_window(var->mlx, var->win);
	render_set(var);
}

void	press_up(t_data *var)
{
	double	range;

	range = var->map.max_y - var->map.min_y;
	var->map.max_y += (range * SCALE_FACTOR) - range;
	var->map.min_y += (range * SCALE_FACTOR) - range;
	mlx_clear_window(var->mlx, var->win);
	render_set(var);
}

void	press_right(t_data *var)
{
	double	range;

	range = var->map.max_x - var->map.min_x;
	var->map.max_x += (range * SCALE_FACTOR) - range;
	var->map.min_x += (range * SCALE_FACTOR) - range;
	mlx_clear_window(var->mlx, var->win);
	render_set(var);
}

void	press_down(t_data *var)
{
	double	range;

	range = var->map.max_y - var->map.min_y;
	var->map.max_y -= (range * SCALE_FACTOR) - range;
	var->map.min_y -= (range * SCALE_FACTOR) - range;
	mlx_clear_window(var->mlx, var->win);
	render_set(var);
}
