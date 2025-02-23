#include "fractol.h"

static void	set_map(t_data *var)
{
	if (var->fractal == 1)
	{
		var->map.min_x = -2.0;
		var->map.max_x = 1.0;
		var->map.min_y = -1.15;
		var->map.max_y = 1.15;
	}
	else if (var->fractal == 2)
	{
		var->map.min_x = -2.0;
		var->map.max_x = 2.0;
		var->map.min_y = -2.0;
		var->map.max_y = 2.0;
	}
	else if (var->fractal == 3)
	{
		var->map.min_x = -1.5;
		var->map.max_x = 2.0;
		var->map.min_y = -1.0;
		var->map.max_y = 2.0;
	}
	var->map.shift = 1;
}

void	set_mandelbrot(int argc, char *argv[], t_data *var)
{
	var->map.max_iter = MAX_ITER;
	if (argc == 3 && argv[2])
		var->map.max_iter = ft_atoui(argv[2]);
	set_map(var);
}

void	set_julia(int argc, char *argv[], t_data *var)
{
	var->map.c.r = -0.8;
	var->map.c.i = 0.156;
	if ((argc == 4 || argc == 5) && argv[2] && argv[3])
	{
		var->map.c.r = ft_atof(argv[2]);
		var->map.c.i = ft_atof(argv[3]);
	}
	var->map.max_iter = MAX_ITER;
	if (argc == 5 && argv[4])
		var->map.max_iter = ft_atoui(argv[4]);
	set_map(var);
}

void	set_burning_ship(int argc, char *argv[], t_data *var)
{
	var->map.max_iter = MAX_ITER;
	if (argc == 3 && argv[2])
		var->map.max_iter = ft_atoui(argv[2]);
	set_map(var);
}
