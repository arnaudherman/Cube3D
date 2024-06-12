# --------------- source files --------------- #

SRCS += srcs/main.c

SRCS += srcs/clean/all.c \
		srcs/clean/error.c \
		srcs/clean/exit.c \
		srcs/clean/print_values.c

SRCS += srcs/setup/all.c \
		srcs/setup/engine.c \
		srcs/setup/image.c \
		srcs/setup/player.c \
		srcs/setup/ray.c \
		srcs/setup/texture.c 

SRCS += srcs/moving/keys.c \
		srcs/moving/listener.c \
        srcs/moving/move.c \
        srcs/moving/position.c \
        srcs/moving/rotation.c

SRCS += srcs/parsing/color_utils.c \
		srcs/parsing/color.c \
        srcs/parsing/len_map.c \
		srcs/parsing/len_map_utils.c \
        srcs/parsing/map.c \
        srcs/parsing/map_check.c \
        srcs/parsing/map_process.c \
        srcs/parsing/map_utils.c \
        srcs/parsing/parsing.c \
        srcs/parsing/texture.c \
        srcs/parsing/texture_utils.c

SRCS += srcs/rendering/dda.c \
		srcs/rendering/draw.c \
		srcs/rendering/frame.c \
        srcs/rendering/map.c \
        srcs/rendering/raycasting.c \
        srcs/rendering/draw.c \
		srcs/rendering/wall.c

SRCS += srcs/utils/get_next_line.c \
        srcs/utils/utils.c

# ---------------  --------------- #

NAME	=			cub3D

OBJS	=			$(SRCS:%.c=%.o)

CC		=			gcc

RM		=			rm -f

CFLAGS	=			-Wall -Wextra -Werror -g -w -O2 -fsanitize=address

# Platform detection
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	LIBS	=	-Llibft -lft -L./minilibx/linux -lmlx -lXext -lX11 -lm -lbsd
	MLX_DIR = minilibx/linux
else
	LIBS = -Llibft -lft -L./minilibx/mac -lmlx -framework OpenGL -framework AppKit
	MLX_DIR = minilibx/mac
endif


all: 				$(NAME)

%.o: 				%.c
					${CC} ${CFLAGS} -Iinclude -Ilibft -I${MLX_DIR} -c $? -o $@

${NAME}:			${OBJS}
					@make -C libft
					@make -C ${MLX_DIR}
					${CC} ${CFLAGS} $^ ${LIBS} -o ${NAME}

clean:
					${RM} $(OBJS)
					@make -C libft clean
					@make -C ${MLX_DIR} clean

name:
					@echo $(MLX_DIR)

fclean:				clean
					${RM} $(NAME)
					@make -C libft fclean

re: 				fclean all

.PHONY:				all  clean fclean re

# find error with : 	valgrind ./prog
# Debug with :  		gdb ./prog --tui