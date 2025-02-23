#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_W 800
# define WIN_H 600
# define MAX_ITER 100
# define SCALE_FACTOR 1.1

typedef unsigned int	t_uint;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size;
	int		endian;
}		t_img;

typedef struct s_comp
{
	double	r;
	double	i;
	t_uint	iter;
}		t_comp;

typedef struct s_scale
{
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
	t_comp	c;
	t_uint	shift;
	t_uint	max_iter;
}		t_scale;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_scale	map;
	t_uint	fractal;
}		t_data;

void	print(const char *str);
void	print_usage(void);

void	set_mandelbrot(int argc, char *argv[], t_data *var);
void	set_julia(int argc, char *argv[], t_data *var);
void	set_burning_ship(int argc, char *argv[], t_data *var);

void	render_set(t_data *var);

void	free_resources(t_data *var, char *msg);
void	init_and_open_win(t_data *var, char *win_name);

//events
void	press_x(t_data *var);
void	press_z(t_data *var);

void	press_c(t_data *var);
void	press_left(t_data *var);
void	press_up(t_data *var);
void	press_right(t_data *var);
void	press_down(t_data *var);
int		key_press(int keycode, t_data *var);

void	scroll_up(int x, int y, t_data *var);
void	scroll_down(int x, int y, t_data *var);
int		mouse_scroll(int button, int x, int y, t_data *var);

//mlx_utils
void	put_pixel(t_img *img, int x, int y, int color);
double	map(double min, double max, double pix_pos, double pixel);
t_uint	color_shift(t_uint iterations, t_uint max_iterations, t_uint shift);

//utils
char	*to_lower(char *str);
int		ft_strncmp(const char *s1, const char *s2, int len);
t_uint	ft_atoui(const char *str);
double	ft_atof(const char *str);

//fractol_sets
void	mandelbrot_set(t_data *var);
void	julia_set(t_data *var);
void	burning_ship_set(t_data *var);

#endif
