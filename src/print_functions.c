#include "fractol.h"
#include <stdlib.h>
#include <unistd.h>

void	print(const char *str)
{
	t_uint	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		i++;
	write(STDERR_FILENO, str, i);
}

void	print_usage(void)
{
	char	*text;

	text = "Usage: ./fractol [FRACTAL SET]... [OPTIONS]...\n\n"
		"  'cr' is the real value of constant\n"
		"  'ci' is the imaginary value of constant\n"
		"  'i' is the numbe of iterations\n\n"
		"  Fractal sets with options:\n"
		"\tmandelbrot  <i>\n"
		"\tjulia <cr> <ci> <i>\n"
		"\tburningship <i>\n\n"
		"./fractol mandelbrot 1000\n"
		"./fractol julia -0.8 0.156 500\n"
		"./fractol burninigship 500\n";
	print(text);
	exit(EXIT_FAILURE);
}
