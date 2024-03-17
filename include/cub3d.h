/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:23:39 by aherman           #+#    #+#             */
/*   Updated: 2024/03/17 18:26:01 by bat              ###   ########.fr       */
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
# define CELLSIZE 64
#define MAPX 8
#define MAPYX 8
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
#  define BUFFER_SIZE 42

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

# endif

/* /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ STRUCTS _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ */

enum e_direction
{
	NORTH = 0,
	EAST = 1,
	SOUTH = 2,
	WEST = 3
};

typedef struct s_color
{
	char		*f_color;
	char		*c_color;
	int			floor;
	int			ceiling;
}	t_color;

typedef struct s_texture
{
	int			texture_found;
	char		*road;
}	t_texture;
typedef struct s_ray {
    int 		step_x;          // Direction x du pas de grille du rayon (1 ou -1)
    int 		step_y;          // Direction y du pas de grille du rayon (1 ou -1)
    int 		side;            // Indicateur de côté de la carte frappée par le rayon (0: horizontal, 1: vertical)
    int 		line_height;     // Hauteur de ligne à dessiner sur l'écran
    int 		draw_start;      // Début de la ligne à dessiner sur l'écran
    int 		draw_end;        // Fin de la ligne à dessiner sur l'écran
	double 		wall_dist;       // Distance de la caméra au mur frappé par le rayon
    double 		wall_x;          // Position exacte du mur frappé par le rayon
	double 		pov_x;        	 // Position horizontale de la caméra sur le plan de projection
    double 		dir_x;           // Composante x de la direction du rayon
    double 		dir_y;           // Composante y de la direction du rayon
    double 		map_x;           // Coordonnée x de la case de la carte frappée par le rayon
    double 		map_y;           // Coordonnée y de la case de la carte frappée par le rayon
    double 		deltadist_x;     // Distance entre deux intersections de rayon horizontales
    double 		deltadist_y;     // Distance entre deux intersections de rayon verticales
    double 		sidedist_x;      // Distance du rayon horizontal à la prochaine ligne de grille x
    double 		sidedist_y;      // Distance du rayon vertical à la prochaine ligne de grille y
} t_ray;

typedef struct s_map {
    char 		**map2d;
    int			w_map;
    int 		h_map;
    int 		x_pos_map;
    int 		y_pos_map;
} t_map;
typedef struct s_player
{
 	int  		x_pos_px; // player x position in pixels
 	int  		y_pos_px; // player y position in pixels
	double		x_dir;
	double		y_dir;
	float		player_angle; // player angle
	float 		fov; // field of view in radians
 	int  		left_right; // left right flag
 	int  		up_down; // up down flag
 	int  		rotate; // rotation flag
	char 		dir;
} t_player;
typedef struct	s_data {
	int			fd;
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			win_width;
	int			win_height;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	char 		**map;
	t_map		map;
	t_ray  		ray;
	t_player  	player;
	t_texture 	texture;
	t_color		color;
} t_data;

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
int			parse_textures(char *file_d, t_data *data);

/* -------------------- RAYCASTING -------------------- */
static void init_raycasting(t_data *data);
static void perform_dda(t_data *data, t_ray *ray);
static void calculate_line_height(t_ray *ray, t_data *data, t_player *player);
int 		raycasting(t_player *player, t_data *data);

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