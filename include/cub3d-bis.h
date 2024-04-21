#ifndef CUB3D_BIS_H
# define CUB3D_BIS_H

/* /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ INCLUDE _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ */

# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include "../minilibx/linux/mlx.h"
# include "../minilibx/mac/mlx.h"
# include "../libft/libft.h"
# include "../ft_printf/include/ft_printf.h"
# include "../include/colors.h"

/* /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ MACRO _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ */

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1000
# define TILE_SIZE 64
# define MAPX 8
# define MAPYX 8
# define MAP_HEIGHT 10
# define MAP_WIDTH 10
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
# define BUFFER_SIZE 42
# define ROTATE_LEFT 123
# define ROTATE_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define FORWARD_W_Z 13
# define BACK_S_S 1
# define RIGHT_D_D 2
# define LEFT_A_Q 0
# define MOUSE_BORDER_DISTANCE 20
# define FLOOR 0xE6E6E6
# define CEILING 0x404040

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
# define ERROR_DOUBLE_TEXT "Error\n \
	Twice the same texture has been setup.\n \
	Example of use: ./cub3D map/XX.cub\n"
# define ERROR_MISSING_TEXT "Error\n \
	A texture has been not setup.\n \
	Example of use: ./cub3D map/XX.cub\n"
# define ERROR_PATH_TEXT "Error\n \
	Textures path does not show a usable file.\n \
	Example of use: ./cub3D map/XX.cub\n"
# define ERROR_MISSING_COLOR "Error\n \
	A color has been not setup.\n \
	Example of use: ./cub3D map/XX.cub\n"
# define ERROR_DOUBLE_COLOR "Error\n \
	Twice the same color has been setup.\n \
	Example of use: ./cub3D map/XX.cub\n"
# define ERROR_SPLIT_COLOR "Error\n \
	Failed to split color string.\n \
	Example of use: ./cub3D map/XX.cub\n"
# define ERROR_FORMAT_COLOR "Error\n \
	Failed to split color string.\n \
	Example of use: ./cub3D map/XX.cub\n"
# define ERROR_RANGE_COLOR "Error\n \
	Failed to split color string.\n \
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

typedef struct s_image
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	// char	*relative_path = "./test.xpm";
}	t_image;

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
    int 		x_map;
    int 		y_map;
	int			color;
	t_ray  		ray;
} t_map;

typedef struct s_minimap
{
	char	**map;
	t_image	*img;
	int		size;
	int		offset_x;
	int		offset_y;
	int		view_dist;
	int		tile_size;
}	t_minimap;

typedef struct s_player
{
 	double  	x_pos; // player x position in pixels
 	double  	y_pos; // player y position in pixels
	int			x_move;
	int			y_move;	
	double		x_dir;
	double		y_dir;
	double		x_plane;
	double		y_plane;
	double		speed;
	float		angle; // player angle
	float 		fov; // field of view in radians
 	int  		rotate; // rotation flag
	char 		direction;
	int	 		size;
	int 		color;
	int		has_moved;
} t_player;

typedef struct s_color
{
	char		*string_color;
	int			final_color;
	int			int_r;
	int			int_g;
	int			int_b;
	int			found_color;
	char		*fcolor;
	char		*ccolor;
	int			floor;
	int			ceiling;
} t_color;

typedef struct s_texture
{
	int			texture_found;
	char		*road;
	char		*NO;
	char 		*SO;
	char 		*WE;
	char		*EA;
} t_texture;

typedef struct	s_data {
	int			fd;
	void		*mlx_ptr;
	void		*win_ptr;
	int			win_width;
	int			win_height;
	t_image  	image;
	t_map		map;
	t_minimap	minimap;
	t_ray  		ray;
	t_player  	player;
	t_texture 	texture;
	t_color		color;
} t_data;

/* /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ PROTOTYPE _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ */

/* -------------------- ERROR -------------------- */

// Located in *error.c*
void		ft_error(char *error);

/* -------------------- DIY LIBFT -------------------- */
// Located in *get_next_line.c*
char		*read_the_line(int fd, char *left_line);
char		*join_line(char *left_line, char *s1);
char		*go_line(char *left_line);
char		*go_next(char *left_line);
char		*get_next_line(int fd);
// Located in *utils.c*
int			ft_strcmp(char *s1, char *s2);
char 		*ft_strcpy(char *dst, const char *src);
void		free_tokens(char **tokens);
static char	*in_tab(const char *s1, int c1, int c2);
static int	number_word(const char *s1, char c);
/* -------------------- MOVEMENT -------------------- */
// Located in *direction.c*
static void	set_player_east_west(t_player *player);
static void	set_player_north_south(t_player *player);
void		set_player_direction(t_data *data);
// Located in *keys.c*
static int	key_press(int key, t_data *data);
static int	key_release(int key, t_data *data);
static void	wrap_mouse_position(t_data *data, int x, int y);
static int	mouse_motion(int x, int y, t_data *data);
void		listen_input(t_data *data);
// Located in *move.c*
static int	up(t_data *data);
static int	down(t_data *data);
static int	left(t_data *data);
static int	right(t_data *data);
int			move(t_data *data);
// Located in *player.c*
t_player 	init_player();
void 		update_player_position(t_player *player, int key);
void 		draw_player(void *mlx_ptr, void *win_ptr, t_player *player);
int 		key_hook(int key, t_player *player, t_data *data);
// Located in *position.c*
static bool	is_valid_wall_collision_position(t_data *data, double x, double y);
static bool	is_valid_map_position(t_data *data, double x, double y);
static bool	is_valid_pos(t_data *data, double x, double y);
bool		is_valid_move(t_data *data, double new_x, double new_y);
// Located in *rotation.c*
int			player_rotation(t_data *data, double rotation_direction);
static int	rotate(t_data *data, double rotspeed);

/* -------------------- PARSING -------------------- */
// Located in *color.c*
// int			encode_rgb(int r, int g, int b);
// void		save_color_data(t_color *color, char *line);
// void		found_color_data(t_data *data);
// void		is_valid_color(t_color *color);
// void		color_data(t_data *data);
// // Located in *initialize_map.c*
// void		initialize_map(t_data *data);
// void		fill_validate_and_close_map(char *file_d, t_data *data, int fd);
// int			fill_map(char *in_file, t_data *data);
// int			init_and_open(char *in_file, t_data *data);
// void		process_lines(int fd, t_data *data, int *y);
// char		*fill_with_space(char *line, t_data *data);
// void		validate_and_close(int fd, t_data *data, int y);
// int			check_walls(t_data *data);
// void		check_player_positions(t_data *data);
// int			player_pos(int x, int y, t_data *data);
// int			cross_check(t_data *data);
// // Located in *len_map.c*
// int			check_auth_char(char *line, t_data *data);
// int			process_line(char *line, t_data *data);
// char		*read_and_filter_line(int fd_cub, char **ptr);
// char		*ignore_texture(int fd_cub);
// void		len_map(char *file_d, t_data *data);
// // Located in *map.c*
// // Located in *parsing.c*
// int			ft_check_file(char *fname, char *name);
// void		process_textures_and_colors(char *file_d, t_data *data);
// int			parsing(char *argv[], t_data *data);
// // Located in *texture_color.c*
// int			open_file_and_init(const char *file_d, int *fd, int *line_counter);
// int			check_value(char *rgb_str, unsigned int i);
// int			check_format(char *rgb_str);
// int			convert_colors(t_data *data);
// void		check_and_close(int fd, int line_counter);
// int			get_rgb(int dir, char *line, t_data *data);
// // int	get_texture_path(t_orientation dir, char *line, t_data *data);
// int			get_path_texture(char *path, char **texture_path, char *error_message);
// void		extract_info(char *trimmed_line, t_data *data, int *line_counter);
// void		check_line_type(char *trimmed_line, t_data *data, int *line_counter);
// void		trimmed_line(char *line, t_data *data, int *line_counter);
// int			parse_textures(char *file_d, t_data *data);
// // Located in *texture.c*
// void		save_texture_data(t_texture *texture, char *line);
// void		found_textures_data(t_data *data);

/* -------------------- RENDERING -------------------- */
// Located in *draw.c*
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
// Located in *image.c*
int	my_mlx_init(t_data *data);
// Located in *map.c*
void 		init_my_map();
void 		draw_square(void *mlx_ptr, void *win_ptr, t_player *player, t_data *data, t_map *map);
void 		draw_map(void *mlx_ptr, void *win_ptr, t_player player);
// Located in *raycasting.c*
static void init_raycasting(t_data *data);
static void perform_dda(t_data *data, t_ray *ray);
static void calculate_line_height(t_ray *ray, t_data *data, t_player *player);
int 		raycasting(t_player *player, t_data *data);

// Located in *texture.c*
void		found_textures_data(t_data *data);

// Located in *color.c*
void		color_data(t_data *data);

/* -------------------- LIBFT -------------------- */

// Located in *get_next_line.c*
char		*join_line(char *left_line, char *s1);
char		*read_the_line(int fd, char *left_line);
char		*go_line(char *left_line);
char		*go_next(char *left_line);
char		*get_next_line(int fd);

// Located in *libft_one.c*
// char		*ft_strchr(const char *s, int c);
// void		*ft_calloc(size_t nmemb, size_t size);
// char		*ft_strjoin(char *s1, char *s2);
// char		*ft_strdup(char *src);
// void		ft_bzero(void *s, size_t n);
int			ft_strcmp(char *s1, char *s2);

// // Located in *libft_two.c*
// size_t		ft_strlen(const char *s);
// size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
// int			ft_strncmp(const char *s1, const char *s2, size_t size);
// int			ft_atoi(const char *str);
void		free_tokens(char **tokens);

// Located in *libft_three.c*
char		**ft_split(char const *s, char c);

/* -------------------- MAIN.C -------------------- */
int			main(int ac, char **av);