

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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

/* /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ STRUCTS _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ */

typedef struct s_color_info
{
	char	*string_color;
	int		final_color;
	int		int_r;
	int		int_g;
	int		int_b;
	int		found_color;
}	t_color_info;

typedef struct s_texture_info
{
	int		texture_found;
	char	*road;
}	t_texture_info;

typedef struct s_data
{
	char			**map;
	int				map_x;
	int				map_y;
	int				f_spawn;
	t_texture_info	no;
	t_texture_info	so;
	t_texture_info	we;
	t_texture_info	ea;
	t_color_info	fcolors;
	t_color_info	ccolors;
}				t_data;

/* /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ PROTOTYPE _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ */

/* -------------------- ERROR -------------------- */

// Located in *error.c*
void	ft_error(char *error);

/* -------------------- PARSING -------------------- */

// Located in *parsing.c*
int		parsing(char *argv[], t_data *data);

// Located in *len_map.c*
void	len_map(char *file_d, t_data *data);

// Located in *len_map_utils.c*
int		process_line(char *line, t_data *data);
char	*ignore_texture(int fd_cub);

// Located in *found_texture.c*
void	found_textures_data(char *fname, t_data *data);

// Located in *save_texture.c*
void	save_texture_data(t_texture_info *texture, char *line);

// Located in *color.c*
void	color_data(char *fname, t_data *data);

// Located in *color_utils.c*
int		encode_rgb(int r, int g, int b);

// Located in *map_main.c*
void	check_map(char *fname, t_data *data);
void	check_map_bounds(t_data *data);
void	analyze_map_data(t_data *data);

// Located in *map.c*
void	complet_string_with_space(char **strings, int len);
void	adjust_string_length(char *string, int new_len);
int		find_max_string_length(char **strings, int len);
void	check_start_end(char *string);
void	only_space_or_one(char *string);

// Located in *map_utils.c*
void	tab_to_space(char *string);
void	remove_newline(char **array);

// Located in *map_on.c*
int		on_map(char car);
void	check_upper(char *string_up, char *string_down);
void	check_down(char *string_up, char *string_down);

// Located in *map_data.c*
void	read_map_data(int fd_cub, t_data *data);

/* -------------------- LIBFT -------------------- */

// Located in *get_next_line.c*
char	*join_line(char *left_line, char *s1);
char	*read_the_line(int fd, char *left_line);
char	*go_line(char *left_line);
char	*go_next(char *left_line);
char	*get_next_line(int fd);

// Located in *libft_one.c*
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *src);
void	ft_bzero(void *s, size_t n);

// Located in *libft_two.c*
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t size);
int		ft_atoi(const char *str);
void	free_tokens(char **tokens);

// Located in *libft_three.c*
char	**ft_split(char const *s, char c);

// Located in *libft_four.c*
char	*ft_strcpy(char *s1, char *s2);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

// Located in *libft_five.c*
char	*ft_strtrim(char const *s1, char const *set);

#endif