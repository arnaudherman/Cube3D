/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:23:39 by aherman           #+#    #+#             */
/*   Updated: 2024/03/08 15:19:41 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ INCLUDE _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ */

# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include "../minilibx/mlx.h"
# include "../ft_printf/include/ft_printf.h"

/* /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ MACRO _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ */

# define WIN_WIDTH 1900 // window width
# define WIN_HEIGHT 1000 // window height
# define TILE_SIZE 30 // tile size
# define FOV 60 // field of view
# define ROTATION_SPEED 0.045 // rotation speed
# define PLAYER_SPEED 4 // player speed
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# define ERROR_NBR_ARG "Invalid number of arguments.\n \
	Example of use:: ./cub3D map/XX.cub\n"

# define ERROR_WRONG_MAP_NAME "Parameter given wrong!\n \
	Example of use:: ./cub3D map/XX.cub\n"

# define ERROR_EXEMPLE "Example of use:\n \
	./cub3D map/XX.cub\n"

# define ERROR_MAP_EXT "Invalid extension for map.\n \
	Example of use:: ./cub3D map/XX.cub\n"

# endif

/* /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ STRUCTS _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ */

typedef struct s_player //the player structure
{
	int	plyr_x; // player x position in pixels
	int	plyr_y; // player y position in pixels
	double	angle; // player angle
	float	fov_rd; // field of view in radians
	int	rot; // rotation flag
	int	l_r; // left right flag
	int	u_d; // up down flag
}	t_player;

typedef struct s_ray //the ray structure
{
	double ray_ngl; // ray angle
	double distance; // distance to the wall
	int  flag;  // flag for the wall
}	t_ray;

typedef struct s_data //the data structure
{
	char **map2d; // the map
	int  p_x;  // player x position in the map
	int  p_y;  // player y position in the map
	int  w_map;  // map width
	int  h_map;  // map height
}	t_data;

typedef struct mlx_instance
{
	int32_t	x;
	int32_t	y;
	int32_t	z;
	bool	enabled;
}	mlx_instance_t;

typedef struct mlx_image
{
	const uint32_t	width;
	const uint32_t	height;
	uint8_t*		pixels;
	mlx_instance_t*	instances;
	size_t			count;
	bool			enabled;
	void*			context;
}	mlx_image_t;

typedef struct mlx
{
	void*		window;
	void*		context;
	int32_t		width;
	int32_t		height;
	double		delta_time;
}	mlx_t;

typedef struct s_txtr
{
	char			*key;
	char			*value;
	struct s_txtr	*next;
}	t_txtr;

typedef struct mlx_texture
{
	uint32_t	width;
	uint32_t	height;
	uint8_t		bytes_per_pixel;
	uint8_t*	pixels;
}	mlx_texture_t;

typedef struct s_tex
{
	mlx_texture_t	*no;
	mlx_texture_t	*so;
	mlx_texture_t	*we;
	mlx_texture_t	*ea;
}	t_tex;

typedef struct s_data
{
	char	**map2d;
	int		rows;
	int		cols;
	int		p_x;
	int		p_y;
	int		w_map;
	int		h_map;
	char	**ff;
	char	**cc;
	int		fd;
	int		i;
	char	*line;
	char	*ture;
	char	*map;
	char	**ture2d;
	char	**sq_map;
	char	**rgb;
	t_txtr	*t;
}	t_data;

typedef enum mouse_mode
{
	MLX_MOUSE_NORMAL	= 0x00034001,
	MLX_MOUSE_HIDDEN	= 0x00034002,
	MLX_MOUSE_DISABLED	= 0x00034003,
}	mouse_mode_t;

typedef struct s_mlx //the mlx structure
{
	mlx_image_t	*img; // the image
	mlx_t	*mlx_p; // the mlx pointer
	t_ray	*ray; // the ray structure
	t_data	*dt; // the data structure
	t_player	*ply; // the player structure
	t_tex			*tex;
	t_txtr			*l_ture;
	mouse_mode_t	mouse_mode;
}	t_mlx;

/* /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ PROTOTYPE _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ */

/* -------------------- ERROR -------------------- */

// Located in *error.c*
void		ft_error(int flag);

/* -------------------- PARSING -------------------- */

// Located in *parsong.c*
int			parsing(int ac, char **av, t_data *m, t_txtr *l_ture);

/* -------------------- LIBFT -------------------- */

// Located in *libft_one.c*
char		*ft_strchr(const char *s, int c);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(char *src);

// Located in *get_next_line.c*
char		*join_line(char *left_line, char *s1);
char		*read_the_line(int fd, char *left_line);
char		*go_line(char *left_line);
char		*go_next(char *left_line);
char		*get_next_line(int fd);



#endif