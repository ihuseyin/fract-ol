#include "fractol.h"
#include <mlx.h>
#include <stdlib.h>

void	free_resources(t_data *var, char *msg)
{
	if (var->img.img)
		mlx_destroy_image(var->mlx, var->img.img);
	if (var->win)
		mlx_destroy_window(var->mlx, var->win);
	if (var->mlx)
	{
		mlx_destroy_display(var->mlx);
		free(var->mlx);
	}
	print(msg);
	exit(EXIT_FAILURE);
}

static int	close_button(t_data *var)
{
	free_resources(var, NULL);
	return (0);
}

void	init_and_open_win(t_data *var, char *win_name)
{
	var->mlx = NULL;
	var->win = NULL;
	var->img.img = NULL;
	var->mlx = mlx_init();
	if (!var->mlx)
		free_resources(var, "mlx initialize error!\n");
	var->win = mlx_new_window(var->mlx, WIN_W, WIN_H, win_name);
	if (!var->win)
		free_resources(var, "new window error!\n");
	var->img.img = mlx_new_image(var->mlx, WIN_W, WIN_H);
	if (!var->img.img)
		free_resources(var, "image creation error!\n");
	var->img.addr = mlx_get_data_addr(var->img.img, &var->img.bpp,
			&var->img.size, &var->img.endian);
	mlx_hook(var->win, 17, 0, close_button, var);
}
