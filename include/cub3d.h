#ifndef CUB3D_H
# define CUB3D_H

/* /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ INCLUDE _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ */

# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
// # include "../minilibx/linux/mlx.h"
# include "../minilibx/mac/mlx.h"
# include "../libft/libft.h"
# include "../ft_printf/include/ft_printf.h"
# include "../include/colors.h"

/* /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ MACRO _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ */

# define ERROR_NBR_ARG "Error\n \
	Invalid number of arguments.\n \
	Example of use: ./cub3D map/XX.cub\n"
# define ERROR_MALLOC "Error\n \
	Malloc error.\n \
	Example of use: ./cub3D map/XX.cub\n"
# define ERROR_MAP_SPAWN "Error\n \
	More than one spawn on map.\n \
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
	Format color string.\n \
	Example of use: ./cub3D map/XX.cub\n"
# define ERROR_RANGE_COLOR "Error\n \
	Range RGB color string.\n \
	Example of use: ./cub3D map/XX.cub\n"
# define ERROR_STRING_COLOR "Error\n \
	A color is not correct.\n \
	Example of use: ./cub3D map/XX.cub\n"
# define ERROR_MAP_ONLY_SPACE_ONE "Error\n \
	First or last map line is false.\n \
	Example of use: ./cub3D map/XX.cub\n"
# define ERROR_MAP_NOT_ONE_START "Error\n \
	A line on the map does not have a 1 at the beginning.\n \
	Example of use: ./cub3D map/XX.cub\n"
# define ERROR_MAP_NOT_ONE_END "Error\n \
	A line on the map does not have a 1 at the ending.\n \
	Example of use: ./cub3D map/XX.cub\n"
# define ERROR_MAP_CHECK_UPER "Error\n \
	The second line of the map does not only have 1 above its 0.\n \
	Example of use: ./cub3D map/XX.cub\n"
# define ERROR_MAP_CHECK_DOWN "Error\n \
	A line does not have a 1 or 0 below any of its 0.\n \
	Example of use: ./cub3D map/XX.cub\n"
# define ERROR_BACK_AFTER_MAP "Error\n \
	There are newlines after or on the map.\n \
	Example of use: ./cub3D map/XX.cub\n"

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define TILE_SIZE 32
// # define MAPX 8
// # define MAPY 8
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
# define MOUSE_BORDER_DISTANCE 20
# define FLOOR 0xE6E6E6
# define CEILING 0x404040
# define TEXTURE 42
# define WALL_HEIGHT (WINDOW_HEIGHT / 2)
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

/* /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ STRUCTS _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ */

typedef struct s_image
{
	int			width;
	int 		height;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*img; // Here's my pointer
	char		*addr;
	// char 		*data;
	char		*road;
    int		    texture_found;
} t_image;

typedef struct s_ray {
    int 		x;
    int 		y;
    int     	x_map;
    int      	y_map;
    int      	x_step;
    int      	y_step;
	int			hit;
    int 		side;
    int 		line_height;
    int 		draw_start;
	int 		draw_end;
	int 		x_text;
	int 		y_text;
	double 		wall_x;
	double 		*z_index;
	double 		camera_x;
	double 		wall_dist;
	double 		dir_x;
    double 		dir_y;
	double 		sx; // side distance
	double 		sy;
	double 		dx; // delta distance
    double 		dy;
} t_ray;

typedef struct s_map {
    int			f_spawn;
    int			w_map;
    int 		h_map;
	char 		**map2d;
    int 		x_map;
    int 		y_map;
	unsigned int color;
	t_ray  		*ray;
} t_map;

typedef struct s_player
{
 	double  	x_pos; // in pixels
 	double  	y_pos;
	double		x_dir;
	double		y_dir;
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

typedef struct s_color_info
	{
		char			*string_color;
		char			*fcolor;
		char 			*ccolor;
		int				final_color;
		int				int_r;
		int				int_g;
		int				int_b;
		int				found_color;
		int				floor;
		unsigned long	floor_hexa;
		int				ceiling;
		unsigned long	ceiling_hexa;
} t_color_info;
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
	// TO DO : HANDLE t_color_info struct
	int		 		c_color;
	int 			f_color;
	t_color_info    fcolors;
	t_color_info	ccolors;
	t_mlx		    mlx;
	t_map		    map;
	t_player	    *player;
	t_keys		    *keys;
	t_ray  		    *ray;
	t_image 	    *image;
	t_image  	    *map2d;
	t_image 	    *world;
	t_image 	    NO;
	t_image 	    SO;
	t_image 	    WE;
	t_image 	    EA;
	t_image 	    *floor;
	t_image 	    *ceiling;

} t_data;

/* /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ PROTOTYPE _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ */

/* -------------------- CLEAN -------------------- */
// Located in *all.c*
void 		free_tokens(char **tokens);
int 		clean_all(t_data *data);
void		free_if_malloc_failed(t_data *data);
void		free_all(t_data *data);

// Located in *error.c*
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_error(char *error);
int			err(char *str);

// Located in *exit.c*
int			exit_game(t_data *data);
void		clear_map(t_data *data);
void		clear_window(t_mlx *mlx);
void		clear_image(t_image *image, t_mlx *mlx);
void		destroy_data(t_data *data);

// Located in *map.c*
void 		free_map(t_map *map);

// Located in *print_struct_values.c*
void 		print_ray_info(t_ray *ray);
void 		print_ray_texture_info(t_data *data, t_ray *ray, t_image *texture);
void 		print_image_info(t_image *image);

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
int			init_all_images(t_data *data);
int			init_custom_all(t_data *data);

// Located in *engine.c*
int	init_mlx_engine(t_mlx *mlx);
// Located in *image.c*
t_image		*allocate_image();
int 		init_map2d(t_image *map2d, t_mlx *mlx);
int 		init_world(t_image *world, t_mlx *mlx);
int			init_image(t_data *data, t_image *image, void *mlx_ptr);
// Located in *keys.c*
t_keys		*allocate_keys(void);
// Located in *map.c*
int			malloc_map2d(t_map *map);
int			fill_map(t_map *map);
int 		init_map(t_map *map);
// Located in *minimap.c*
// t_minimap 	*allocate_minimap(void); 
// Located in *player.c*
t_player	*allocate_player(void);
static void	default_player(t_player *player);
int			init_player(t_player *player);
// Located in *ray.c*
void		calculate_deltas(t_ray *ray);
void		calculate_steps_sides(t_ray *ray, t_player *player);
void 		init_ray(t_ray *ray, t_player *player);
void 		init_default_ray(t_ray *ray);
// Located in *texture.c*
void 		init_texture_img(t_image *texture_img, void *mlx_ptr, char *path);
void 		init_textures(t_data *data, void *mlx_ptr);
void		set_texture_image_road(t_image *texture_img, t_ray *ray);

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
int			encode_rgb(int r, int g, int b);
void		save_color_data(t_color_info *color, char *line);
void		found_color_data(char *fname, t_data *data);
void		is_valid_color(t_color_info *color);
void		check_string_color(t_data data);
void		color_data(char *fname, t_data *data);

// Located in *len_map.c*
int			check_auth_char(char *line, t_data *data);
int			process_line(char *line, t_data *data);
char		*read_and_filter_line(int fd_cub, char **ptr);
char		*ignore_texture(int fd_cub);
void		len_map(char *file_d, t_data *data);

// Located in *map.c*
void 		print_string_array(char **array);
void 		show_with_spaces(const char *chaine);
void 		remove_newline(char **array);
void 		tab_to_space(char* string);
void 		only_space_or_one(char *string);
void		check_start_end(char *string);
void 		complet_string_with_space(char **string, int len);
int 		on_map(char car);
void		check_upper(char *string_up, char *string_down);
void		check_down(char *string_up, char *string_down);
void		check_zero(char *string_up, char *string_down);
void 		check_map(char *fname, t_data *data);

// Located in *parsing.c*
void		ft_check_file(char *fname, char *name);
int			parsing(char *argv[], t_data *data);

// Located in *texture.c*
void		save_texture_data(t_image *texture, char *line, t_mlx *mlx);
void	    found_textures_data(char *fname, t_data *data, t_mlx *mlx);

/* -------------------- RENDERING -------------------- */

// Located in *draw.c*
void		my_mlx_pixel_put(t_image *image, int x, int y, int color);
void		draw_vertical_lign(t_data *data);
void 		draw_square(t_data *data, int x, int y, int color);
void 		draw_rays_on_map(t_data *data, t_player *player, t_mlx *mlx);

// Located in *frame.c"
int			render_next_frame(t_data *data);

// Located in *map.c*
int 		draw_map(t_image *map2d, t_map *map);
void 		draw_tile(t_image *image, int x, int y);
void 		draw_vertical_lines(t_image *image);
void 		draw_horizontal_lines(t_image *image);
void 		draw_vertical_line(t_image *image, int x, int start_y, int color);
void 		draw_horizontal_line(t_image *image, int start_x, int y, int color);

// Located in *player.c*
int				draw_player(t_image *image, t_player *player);

// Located in *raycasting.c*
float 		get_ray_length(int map_width, int map_height, int window_width, int window_height);
void 		fov_rays(int hauteur_image, int largeur_image, float fov_horizontal_deg);
float 		correct_fisheye(float distance, float ray_angle, float player_angle);
void 		draw_ray(t_data *data);
void 		shoot_rays(t_data *data, t_player *player, t_ray *ray, t_mlx *mlx);
void 		raycasting(t_data *data, t_player *player, t_mlx *mlx);

// Located in *texture.c*
void		pixel_put(t_image *image, int x, int y, int color);
void		set_color_on_image(t_data *data, t_ray *ray);
void		texture_put(t_data *data, t_image *texture, t_ray *ray);
void		set_texture_on_image(t_data *data, t_image *texture, t_ray *ray);

// Located in *wall.c*
void		get_wall_dist(t_player *player, t_ray *ray);
void		get_wall_height(t_ray *ray);
void 		draw_wall_column(t_image *world, int column, int wall_height);
void 		draw_wall(t_data *data, t_ray *ray);
void		set_wall(t_data *data, t_ray *ray);
void		draw_col(t_data *data, t_mlx *mlx, t_ray *ray);

// Located in *world.c*
void 		draw_world_bg(t_image *world, int color);

/* -------------------- LIBFT -------------------- */

// Located in *get_next_line.c*
char		*join_line(char *left_line, char *s1);
char		*read_the_line(int fd, char *left_line);
char		*go_line(char *left_line);
char		*go_next(char *left_line);
char		*get_next_line(int fd);

// Located in *libft_one.c*
char		*ft_strchr(const char *s, int c);
void		*ft_calloc(size_t nmemb, size_t size);
// char		*ft_strjoin(char *s1, char *s2);
// char		*ft_strdup(char *src);
void		ft_bzero(void *s, size_t n);

// Located in *libft_two.c*
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
int			ft_strncmp(const char *s1, const char *s2, size_t size);
int			ft_atoi(const char *str);
void		free_tokens(char **tokens);

// Located in *libft_three.c*
char		**ft_split(char const *s, char c);

// Located in *libft_four.c*
// char	    *ft_strcpy(char *s1, char *s2);
char	    *ft_strrchr(const char *s, int c);
int 	    ft_strcmp(char *s1, char *s2);
char	    *ft_strtrim(char const *s1, char const *set);

/* -------------------- MAIN.C -------------------- */
int			main(int ac, char **av);
#endif