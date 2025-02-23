#include "fractol.h"
#include <mlx.h>
#include <math.h>

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->size + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

double	map(double min, double max, double pix_pos, double pixel)
{
	return (min + (pix_pos / (pixel - 1)) * (max - min));
}

t_uint	color_shift(t_uint iterations, t_uint max_iterations, t_uint shift)
{
	double	hue;
	int		r;
	int		g;
	int		b;

	hue = (((double)(iterations) / (double)(max_iterations)) * 360.0) + shift;
	hue = fmod(hue, 360.0);
	if (hue < 0)
		hue += 360.0;
	r = (int)(255 * fabs(sin(hue * 3.141592653598793 / 180.0)));
	g = (int)(255 * fabs(sin((hue + 120) * 3.141592653598793 / 180.0)));
	b = (int)(255 * fabs(sin((hue + 240) * 3.141592653598793 / 180.0)));
	return ((r << 16) | (g << 8) | b);
}
