/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:23:39 by aherman           #+#    #+#             */
/*   Updated: 2024/02/29 16:38:49 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ INCLUDE _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ */

# include <math.h>
# include "../minilibx/mlx.h"
# include "../ft_printf/include/ft_printf.h"

/* /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ MACRO _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ */

# define WIDTH 600
# define HEIGHT 600
# define MAX_ITERATION 40

# define ESC 53
# define C 8
# define BOT 125
# define TOP 126
# define MOUSSBOT 5
# define MOUSSTOP 4

# define ERROR_NBR_ARG "Invalid number of arguments.\n \
	Fractal Mandelbrot: ./fractol mandelbrot\n \
	Fractal Julia: ./fractol julia “two decimal numbers“\n"

# define ERROR_WRONG_FRACTAL_NAME  "Parameter given wrong!\n \
	Fractal Mandelbrot: ./fractol mandelbrot\n \
	Fractal Julia: ./fractol julia “two decimal numbers“\n"

# define ERROR_ARG_JULIA "Only Julia take two decimal numbers.\n \
	Fractal Mandelbrot: ./fractol mandelbrot\n \
	Fractal Julia: ./fractol julia “two decimal numbers“\n"

# define ERROR_EXEMPLE "Example of use:\n \
	Fractal Mandelbrot: ./fractol mandelbrot\n \
	Fractal Julia: ./fractol julia “two decimal numbers“\n"

# define ERROR_ARG_JULIA_NEED "Julia take two decimal numbers.\n \
	Fractal Mandelbrot: ./fractol mandelbrot\n \
	Fractal Julia: ./fractol julia “two decimal numbers“\n"

/* /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ STRUCTS _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ */

typedef struct s_data
{
	void	*win_ptr;
	void	*mlx_ptr;
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		name;
	double	iter;
	int		color;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	double	cx;
	double	cy;
	double	zx;
	double	zy;
	double	c_real;
	double	c_imag;
	double	scale;
	double	scale1;
}				t_data;

/* /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ PROTOTYPE _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ */

void	ft_putendl_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t size);
double	ft_atod(const char *str);
void	ft_error(int flag);
void	my_pixel_put(t_data *data, int x, int y, int color);
void	julia(t_data *data);
void	julia_move(t_data *data, int keycode);
int		close_win(int keycode, t_data *data);
int		kill_win(t_data *data);
int		mouse_event(int keycode, int x, int y, t_data *data);
void	mandelbrot(t_data *data);
int		ft_julia_argv(char *str);

#endif