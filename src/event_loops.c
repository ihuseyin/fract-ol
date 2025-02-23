#include "fractol.h"
#include <mlx.h>
#include <stddef.h>

int	mouse_scroll(int button, int x, int y, t_data *var)
{
	if (button == 4 || button == 5)
	{
		if (button == 4)
			scroll_up(x, y, var);
		else
			scroll_down(x, y, var);
		mlx_clear_window(var->mlx, var->win);
		render_set(var);
	}
	return (0);
}

int	key_press(int keycode, t_data *var)
{
	if (keycode == 65307)
		free_resources(var, NULL);
	else if (keycode == 99)
		press_c(var);
	else if (keycode == 120)
		press_x(var);
	else if (keycode == 122)
		press_z(var);
	else if (keycode == 65361)
		press_left(var);
	else if (keycode == 65362)
		press_up(var);
	else if (keycode == 65363)
		press_right(var);
	else if (keycode == 65364)
		press_down(var);
	return (0);
}
