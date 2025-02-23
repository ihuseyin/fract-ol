#include "fractol.h"
#include <mlx.h>

void	press_x(t_data *var)
{
	if (var->map.max_iter <= 4900)
	{
		var->map.max_iter += 100;
		mlx_clear_window(var->mlx, var->win);
		render_set(var);
	}
	return ;
}

void	press_z(t_data *var)
{
	if (var->map.max_iter > 110)
	{
		var->map.max_iter -= 100;
		mlx_clear_window(var->mlx, var->win);
		render_set(var);
	}
	return ;
}
