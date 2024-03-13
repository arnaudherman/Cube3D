/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:23:39 by aherman           #+#    #+#             */
/*   Updated: 2024/03/13 21:40:37 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ INCLUDE _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ */

# include "colors.h"
# include "libft.h"
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include "../minilibx/mlx.h"
# include "../ft_printf/include/ft_printf.h"

/* /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ MACRO _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ */

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1000
# define SQUARE 64
# define FOV 60
# define SPEED 4.2
# define ROTATION 0.042
/* MINIMAP MACROS */
# define MMAP_PIXEL_SIZE 128
# define MMAP_VIEW_DIST 4
# define MMAP_COLOR_PLAYER 0x00FF00
# define MMAP_COLOR_WALL 0x808080
# define MMAP_COLOR_FLOOR 0xE6E6E6
# define MMAP_COLOR_SPACE 0x404040

# define ERROR_NBR_ARG "Error\n \
	Invalid number of arguments.\n \
	Example of use: ./cub3D map/XX.cub\n"

# define ERROR_WRONG_MAP_NAME "Error\n \
	Parameter given wrong!\n \
	Example of use: ./cub3D map/XX.cub\n"

# define ERROR_EXEMPLE "Error\n \
	Example of use:\n \
	./cub3D map/XX.cub\n"

# define ERROR_MAP_EXT "Error\n \
	Invalid extension for map.\n \
	Example of use: ./cub3D map/XX.cub\n"

# define ERROR_MAP_OPEN "Error\n \
	Error map open.\n \
	Example of use: ./cub3D map/XX.cub\n"

# define ERROR_MAP_LTEX "Error\n \
	Error .cub ligne texture.\n \
	Example of use: ./cub3D map/XX.cub\n"

# define ERROR_MAP "Error\n \
	Forbidden character in the map.\n \
	Example of use: ./cub3D map/XX.cub\n"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

/* /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ STRUCTS _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ */

typedef struct s_color_info
{
	char	*f_color;
	char	*c_color;
	int		floor;
	int		ceiling;
}	t_color_info;

typedef struct s_texture_info
{
	int		texture_found;
	char	*road;
}	t_texture_info;

typedef struct s_data
{
	int				fd;
	int				map_x;
	int				map_y;
	t_texture_info	no;
	t_texture_info	so;
	t_texture_info	we;
	t_texture_info	ea;
	t_color_info	colors;
}				t_data;

// // Mlx library struct
// typedef struct s_mlx //the mlx structure
// {
//  	mlx_image_t	*img; // the image
//  	mlx_t		*mlx_p; // mlx pointer
//  	t_ray   	*ray; // ray structure
//  	t_data   	*data; // data structure
//  	t_player  	*plyr; // player structure
// } t_mlx;

// Raycasting struct
typedef struct s_ray
{
	double ray_ang; // ray angle
 	double wall_dist; // distance to the wall
 	int  wall_flag;  // flag for the wall
} t_ray;

// Map data struct
typedef struct s_map {
    char **map2d;
    int w_map;
    int h_map;
    int x_pos_map;
    int y_pos_map;
} t_map;

// Player struct
typedef struct s_player
{
 	int  x_pos_px; // player x position in pixels
 	int  y_pos_px; // player y position in pixels
	double player_angle; // player angle
	float fov; // field of view in radians
 	int  left_right; // left right flag
 	int  up_down; // up down flag
 	int  rot; // rotation flag
} t_player;

// Mlx library struct
typedef struct	s_data_mlx {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_ray   	*ray; // ray structure
	t_data   	*data; // data structure
	t_player  	*plyr; // player structure
} t_data_mlx;

enum e_texture_dir
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};

/* /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ PROTOTYPE _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ */

/* -------------------- ERROR -------------------- */

// Located in *error.c*
void		ft_error(char *error);

/* -------------------- PARSING -------------------- */

// Located in *parsing.c*
int			parsing(char *argv[], t_data *data);

// Located in *len_map.c*
int			process_line(char *line, t_data *data);
char		*ignore_texture(int fd_cub);
int			len_map(char *file_d, t_data *data);
// Located in *len_map.c*
// Located in *texture_color.c*
int	parse_textures(char *file_d, t_data *data);

/* -------------------- LIBFT -------------------- */

// Located in *libft_one.c*
char		*ft_strchr(const char *s, int c);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(char *src);
int			ft_strcmp(char *s1, char *s2);


// Located in *get_next_line.c*
char		*join_line(char *left_line, char *s1);
char		*read_the_line(int fd, char *left_line);
char		*go_line(char *left_line);
char		*go_next(char *left_line);
char		*get_next_line(int fd);

#endif