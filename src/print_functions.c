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
		"  Options:\n  <cr> - Real value of constant (for Julia set).\n"
		"  <ci> - Imaginary value of constant (for Julia set).\n"
		"  <i>  - Number of iterations\n\n"
		"  Available Fractal Sets:\n\n"
		"   Mandelbrot Set\n"
		"\tSyntax: ./fractol mandelbrot <i>\n"
		"\tExample: ./fractol mandelbrot 1000\n"
		"   Julia Set\n"
		"\tSyntax: ./fractol julia <cr> <ci> <i>\n"
		"\tExample: ./fractol julia -0.8 0.156 500\n"
		"   Burning Ship Set\n"
		"\tSyntax: ./fractol burningship <i>\n"
		"\tExample: ./fractol burningship 200\n";
	print(text);
	exit(EXIT_FAILURE);
}
