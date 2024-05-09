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
# define FOV 66
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
// # define ROTATE_LEFT 123
// # define ROTATE_RIGHT 124
// # define KEY_DOWN 125
// # define KEY_UP 126
// # define FORWARD_W_Z 13
// # define BACK_S_S 1
// # define RIGHT_D_D 2
// # define LEFT_A_Q 0
# define RAY_LENGTH 300
# define MOUSE_BORDER_DISTANCE 20
# define FLOOR 0xE6E6E6
# define CEILING 0x404040
# define TEXTURE 42
/* KEYS CONSTANTS */
# define ESC_KEY 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53
# define LEFT_ARR 123
# define RIGHT_ARR 124
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define BUTTON_PRESS 4
# define BUTTON_RELEASE 5

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
	char		*relative_path;
} t_image;

typedef struct s_ray {
    int 		step_x;
    int 		step_y;
    int 		side;
    int 		line_height;
    int 		draw_start;
    int 		draw_end;
	double 		wall_dist;
    double 		wall_x;
	double 		pov_x;
    double 		dir_x;
    double 		dir_y;
    double 		map_x;
    double 		map_y;
    double 		dx;
    double 		dy;
    double 		sidedist_x;
    double 		sidedist_y;
} t_ray;

typedef struct s_map {
    int			w_map;
    int 		h_map;
	char 		**map2d;
    int 		x_map;
    int 		y_map;
	unsigned int color;
	t_ray  		*ray;
} t_map;

typedef struct s_minimap
{
	char	**map;
	t_image	*img;
	double	size;
	int		offset_x;
	int		offset_y;
	int		view_dist;
	int		tile_size;
} t_minimap;

typedef struct s_player
{
 	double  	x_pos; // in pixels
 	double  	y_pos;
	double		x_dir;
	double		y_dir;
	// double		x_move;
	// double 		y_move;
	double		x_plane;
	double		y_plane;
	double		speed;
	float		angle; // in radians
	float 		fov; // in radians
 	int  		rotate;
	char 		direction;
	double	 	size;
	unsigned int color;
} t_player;

typedef struct	s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	esc;
	int	left;
	int	right;
} t_keys;

typedef struct s_color
	{
		char			*string_color;
		char			*fcolor;
		char 			*ccolor;
		int				final_color;
		int				r;
		int				g;
		int				b;
		int				found;
		int				floor;
		unsigned long	floor_hexa;
		int				ceiling;
		unsigned long	ceiling_hexa;
} t_color;

typedef struct s_texture
{
	int			found;
	int			size;
	char		*road;
	char		**NO;
	char 		**SO;
	char 		**WE;
	char		**EA;
	char 		**xpm_data;
} t_texture;

typedef struct	s_mlx
{
	int			fd;
	int			win_width;
	int			win_height;
	void		*mlx_ptr;
	void		*mlx_win_ptr;
} t_mlx;

typedef struct s_data
{
	t_mlx		mlx;
	t_map		map;
	t_minimap	minimap;
	t_image  	*image;
	t_player	*player;
	t_keys		*keys;
	t_ray  		*ray;
	t_texture 	*texture;
	t_color		*color;
	// t_texture_info	no;
	// t_texture_info	so;
	// t_texture_info	we;
	// t_texture_info	ea;
	// t_color_info	fcolors;
	// t_color_info	ccolors;
} t_data;

/* /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ PROTOTYPE _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ */

/* -------------------- CLEAN -------------------- */
// Located in *all.c*
int 		clean_all(t_data *data);
void		free_if_malloc_failed(t_data *data);
void		free_all(t_data *data);
// Located in *error.c*
void		ft_error(char *error);
// Located in *exit.c*
int			exit_game(t_data *data);
void		clear_map(t_data *data);
void		clear_window(t_mlx *mlx);
void		clear_image(t_image *image, t_mlx *mlx);
void		destroy_data(t_data *data);
// Located in *map.c*
void 		free_map(t_map *map);

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

/* -------------------- SETUP -------------------- */
// Located in *all.c*
int			check_allocations(t_data *data);
int 		malloc_struct(void **ptr, size_t size);
int			malloc_all(t_data *data);
int			init_default_all(t_data *data);
int			init_custom_all(t_data *data);
// Located in *color.c*
t_color 	*allocate_color();
// Located in *engine.c*
int			init_data(t_data *data);
// Located in *image.c*
t_image		*allocate_image(void);
int			init_image(t_image *image, t_mlx *mlx);
t_image 	*allocate_image(void);
// Located in *keys.c*
t_keys		*allocate_keys(void);
// Located in *map.c*
int			malloc_map2d(t_map *map);
int			fill_map(t_map *map);
int 		init_map(t_map *map);
// Located in *minimap.c*
t_minimap 	*allocate_minimap(void); 
// Located in *player.c*
t_player	*allocate_player(void);
static void	default_player(t_player *player);
int			init_player(t_player *player);
// Located in *ray.c*
t_ray 		*allocate_ray(void);
// Located in *texture.c*
t_texture 	*allocate_texture(void);

/* -------------------- MOVING -------------------- */
// Located in *direction.c*
static void	set_east_west(t_player *player);
static void	set_north_south(t_player *player);
void		set_direction(t_player *player);
// Located in *keys.c*
int			key_release(int key, t_data *data);
int			key_press(int key, t_data *data);
void		key_move(t_data *data);
// static void	wrap_mouse_position(t_data *data, int x, int y);
// static int	mouse_motion(int x, int y, t_data *data);
// void		listen_input(t_data *data);
// Located in *listener.c*
void		loop(t_data *data);
// Located in *move.c*
int			go_up(t_data *data);
int			go_left(t_data *data);
int			go_down(t_data *data);
int			go_right(t_data *data);
int			go_move(t_data *data);
// Located in *player.c*
// Located in *position.c*
// bool is_wall(t_map *map, double x, double y);
bool 		player_wall_collision(t_map *map, double x, double y);
// bool	check_map_pos(t_data *data, double x, double y);
// bool	check_wall_pos(t_data *data, double x, double y);
// bool	check_pos(t_data *data, double x, double y);
// bool	check_move(t_data *data, double x_new, double y_new);
// Located in *rotation.c*
void 		rotate_left(t_data *data);
void 		rotate_right(t_data *data);

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
// int	get_texture_path(t_orientation dir, char *line, t_data *data);
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
void		my_mlx_pixel_put(t_image *image, int x, int y, int color);
void 		draw_floor(t_data *data);
void 		draw_ceiling(t_data *data);
void 		draw_square(t_data *data, int x, int y, int color);
// Located in *frame.c"
int			render_next_frame(t_data *data);
// Located in *map.c*
int 		draw_map(t_image *image, t_map *map);
void 		draw_tile(t_image *image, int x, int y);
void 		draw_vertical_lines(t_image *image);
void 		draw_horizontal_lines(t_image *image);
void 		draw_vertical_line(t_image *image, int x, int start_y, int color);
void 		draw_horizontal_line(t_image *image, int start_x, int y, int color);
// Located in *minimap.c*
// Located in *player.c*
// int			draw_player(t_player *player, t_mlx *mlx);
int			draw_player(t_image *image, t_player *player);
// Located in *raycasting.c*
static void perform_dda(t_data *data);
static void calculate_line_height(t_data *data);
int 		raycasting(t_data *data);

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

