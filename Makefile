# Do mind that you need the libmlx.dylib in the same 
# directory as your build target as it is a dynamic library!

# FINAL EXECUTABLE NAME
NAME = Cub3D

# DIRECTORIES
HEADER_DIRECTORY := ./include
SRCS_DIRECTORY := ./src
FT_PRINTF_FOLDER := ./ft_printf
LIBFT_FOLDER := ./libft
MAP_FOLDER := ./map
MINILIBX_FOLDER := ./minilibx
INCLUDE = -I$(HEADER_DIRECTORY)

# ALL FILES.C
MAIN := main.c
SRCS := $(addprefix $(SRCS_DIRECTORY)/, \
			main.c \
			error/error.c \
			movement/direction.c \
			movement/keys.c \
			movement/move.c \
			movement/player.c \
			movement/position.c \
			movement/rotation.c \
			parsing/color.c \
			parsing/initialize_map.c \
			parsing/map.c \
			parsing/len_map.c \
			parsing/parsing.c \
			parsing/texture_color.c \
			parsing/texture.c \
			rendering/draw.c \
			rendering/image.c \
			rendering/map.c \
			rendering/minimap_draw.c \
			rendering/minimap.c \
			rendering/raycasting.c \
			rendering/render.c \
			rendering/texture.c \
			libft/get_next_line.c \
			libft/utils.c \
		)

# GLOBAL VARIABLES

# Pour spécifier explicitement l'architecture lors de la compilation 
# avec GCC sur macOS, vous pouvez utiliser l'option -arch suivie de 
# l'architecture cible.
CC = gcc -arch x86_64
CFLAGS := -Wall -Wextra -O3 -g $(INCLUDE)
LDFLAGS := -L$(LIBFT_FOLDER) -lft -L$(FT_PRINTF_FOLDER) -lft_printf -L$(MINILIBX_FOLDER) -lmlx -framework OpenGL -framework AppKit
OBJS = $(SRCS:.c=.o)
RM := rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(FT_PRINTF_FOLDER)
	@$(MAKE) -C $(LIBFT_FOLDER)
	@$(MAKE) -C $(MINILIBX_FOLDER)
	@$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(NAME)

$(SRCS_DIRECTORY)/%.o: $(SRCS_DIRECTORY)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean: 
	@$(MAKE) -C $(LIBFT_FOLDER) clean
	@$(MAKE) -C $(FT_PRINTF_FOLDER) clean
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
