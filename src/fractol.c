#include "fractol.h"
#include <mlx.h>

void	render_set(t_data *var)
{
	if (var->fractal == 1)
		mandelbrot_set(var);
	else if (var->fractal == 2)
		julia_set(var);
	else if (var->fractal == 3)
		burning_ship_set(var);
	return ;
}

static int	fractal_check(int argc, char *argv[], t_data *var)
{
	to_lower(argv[1]);
	if (!ft_strncmp(argv[1], "Mandelbrot", 11) && argc < 4)
	{
		var->fractal = 1;
		set_mandelbrot(argc, argv, var);
		return (1);
	}
	if (!ft_strncmp(argv[1], "Julia", 6) && argc != 3)
	{
		var->fractal = 2;
		set_julia(argc, argv, var);
		return (1);
	}
	if (!ft_strncmp(argv[1], "Burningship", 12) && argc < 4)
	{
		argv[1][7] -= 32;
		var->fractal = 3;
		set_burning_ship(argc, argv, var);
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	var;

	if (argc > 1 && argc < 6 && fractal_check(argc, argv, &var))
	{
		init_and_open_win(&var, argv[1]);
		render_set(&var);
		mlx_key_hook(var.win, key_press, &var);
		mlx_mouse_hook(var.win, mouse_scroll, &var);
		mlx_loop(var.mlx);
	}
	print_usage();
}
