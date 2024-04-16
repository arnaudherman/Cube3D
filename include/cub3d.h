// #ifndef CUB3D_H
// # define CUB3D_H

// /* /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ INCLUDE _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ */

// # include <stdlib.h>
// # include <math.h>
// # include <string.h>
// # include <stdio.h>
// # include <stdbool.h>
// # include <fcntl.h>
// # include "../minilibx/mlx.h"
// # include "../ft_printf/include/ft_printf.h"

// /* /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ MACRO _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ */

// # define ERROR_NBR_ARG "Error\n \
// 	Invalid number of arguments.\n \
// 	Example of use: ./cub3D map/XX.cub\n"
// # define ERROR_WRONG_MAP_NAME "Error\n \
// 	Parameter given wrong!\n \
// 	Example of use: ./cub3D map/XX.cub\n"
// # define ERROR_EXEMPLE "Error\n \
// 	Example of use:\n \
// 	./cub3D map/XX.cub\n"
// # define ERROR_MAP_EXT "Error\n \
// 	Invalid extension for map.\n \
// 	Example of use: ./cub3D map/XX.cub\n"
// # define ERROR_MAP_OPEN "Error\n \
// 	Error map open.\n \
// 	Example of use: ./cub3D map/XX.cub\n"
// # define ERROR_MAP_LTEX "Error\n \
// 	Error .cub ligne texture.\n \
// 	Example of use: ./cub3D map/XX.cub\n"
// # define ERROR_MAP "Error\n \
// 	Forbidden character in the map.\n \
// 	Example of use: ./cub3D map/XX.cub\n"
// # define ERROR_DOUBLE_TEXT "Error\n \
// 	Twice the same texture has been setup.\n \
// 	Example of use: ./cub3D map/XX.cub\n"
// # define ERROR_MISSING_TEXT "Error\n \
// 	A texture has been not setup.\n \
// 	Example of use: ./cub3D map/XX.cub\n"
// # define ERROR_PATH_TEXT "Error\n \
// 	Textures path does not show a usable file.\n \
// 	Example of use: ./cub3D map/XX.cub\n"
// # define ERROR_MISSING_COLOR "Error\n \
// 	A color has been not setup.\n \
// 	Example of use: ./cub3D map/XX.cub\n"
// # define ERROR_DOUBLE_COLOR "Error\n \
// 	Twice the same color has been setup.\n \
// 	Example of use: ./cub3D map/XX.cub\n"
// # define ERROR_SPLIT_COLOR "Error\n \
// 	Failed to split color string.\n \
// 	Example of use: ./cub3D map/XX.cub\n"
// # define ERROR_FORMAT_COLOR "Error\n \
// 	Failed to split color string.\n \
// 	Example of use: ./cub3D map/XX.cub\n"
// # define ERROR_RANGE_COLOR "Error\n \
// 	Failed to split color string.\n \
// 	Example of use: ./cub3D map/XX.cub\n"

// # ifndef BUFFER_SIZE
// #  define BUFFER_SIZE 42

// # endif

// /* /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ STRUCTS _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ */

// typedef struct s_color_info
// {
// 	char	*string_color;
// 	int		final_color;
// 	int		int_r;
// 	int		int_g;
// 	int		int_b;
// 	int		found_color;
// }	t_color_info;

// typedef struct s_texture_info
// {
// 	int		texture_found;
// 	char	*road;
// }	t_texture_info;

// typedef struct s_data
// {
// 	int				fd;
// 	int				map_x;
// 	int				map_y;
// 	t_texture_info	no;
// 	t_texture_info	so;
// 	t_texture_info	we;
// 	t_texture_info	ea;
// 	t_color_info	fcolors;
// 	t_color_info	ccolors;
// }				t_data;

// /* /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ PROTOTYPE _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ */

// /* -------------------- ERROR -------------------- */

// // Located in *error.c*
// void		ft_error(char *error);

// /* -------------------- PARSING -------------------- */

// // Located in *parsing.c*
// int			parsing(char *argv[], t_data *data);

// // Located in *len_map.c*
// int			process_line(char *line, t_data *data);
// char		*ignore_texture(int fd_cub);
// int			len_map(char *file_d, t_data *data);

// // Located in *texture.c*
// void		found_textures_data(t_data *data);

// // Located in *color.c*
// void	color_data(t_data *data);

// /* -------------------- LIBFT -------------------- */

// // Located in *get_next_line.c*
// char		*join_line(char *left_line, char *s1);
// char		*read_the_line(int fd, char *left_line);
// char		*go_line(char *left_line);
// char		*go_next(char *left_line);
// char		*get_next_line(int fd);

// // Located in *libft_one.c*
// char		*ft_strchr(const char *s, int c);
// void		*ft_calloc(size_t nmemb, size_t size);
// char		*ft_strjoin(char *s1, char *s2);
// char		*ft_strdup(char *src);
// void		ft_bzero(void *s, size_t n);

// // Located in *libft_two.c*
// size_t		ft_strlen(const char *s);
// size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
// int			ft_strncmp(const char *s1, const char *s2, size_t size);
// int			ft_atoi(const char *str);
// void		free_tokens(char **tokens);

// // Located in *libft_three.c*
// char		**ft_split(char const *s, char c);


// #endif