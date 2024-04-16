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
INCLUDE = -I../include

# ALL FILES.C
MAIN := main.c
SRCS := src/main.c \
			src/error/error.c \
			src/movement/direction.c \
			src/movement/keys.c \
			src/movement/move.c \
			src/movement/player.c \
			src/movement/position.c \
			src/movement/rotation.c \
			src/parsing/color.c \
			src/parsing/initialize_map.c \
			src/parsing/map.c \
			src/parsing/len_map.c \
			src/parsing/parsing.c \
			src/parsing/texture_color.c \
			src/parsing/texture.c \
			src/rendering/draw.c \
			src/rendering/image.c \
			src/rendering/map.c \
			src/rendering/minimap_draw.c \
			src/rendering/minimap.c \
			src/rendering/raycasting.c \
			src/rendering/render.c \
			src/rendering/texture.c \
			src/libft/get_next_line.c \
			src/libft/utils.c \


# GLOBAL VARIABLES
CC = gcc
CFLAGS := -Wall -Wextra -O3 -g -I$(HEADER_DIRECTORY) -Imlx
OBJS = $(SRCS:.c=.o)
RM := rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
	@${MAKE} -C ${FT_PRINTF_FOLDER}
	@${MAKE} -C ${LIBFT_FOLDER}
	@${MAKE} -C ${MINILIBX_FOLDER}
	@${CC} $(INCLUDE) ${CFLAGS} ${OBJS} -L${LIBFT_FOLDER} -lft -L${FT_PRINTF_FOLDER} -lft_printf -L./minilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean: 
	@${MAKE} -C ${LIBFT_FOLDER} clean
	@${MAKE} -C ${FT_PRINTF_FOLDER} clean
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all
