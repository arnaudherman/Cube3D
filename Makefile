# --------------- source files --------------- #

SRCS += srcs/main.c
SRCS += srcs/movement/direction.c \
        srcs/movement/keys.c \
        srcs/movement/move.c \
        srcs/movement/player.c \
        srcs/movement/position.c \
        srcs/movement/rotation.c

SRCS += srcs/parsing/color.c \
        srcs/parsing/initialize_map.c \
        srcs/parsing/len_map.c \
        srcs/parsing/map.c \
        srcs/parsing/parsing.c \
        srcs/parsing/texture_color.c \
        srcs/parsing/texture.c

SRCS += srcs/rendering/close.c \
        srcs/rendering/draw.c \
        srcs/rendering/image.c \
        srcs/rendering/init.c \
        srcs/rendering/map.c \
        srcs/rendering/minimap.c \
        srcs/rendering/raycasting.c \
        srcs/rendering/render.c \
        srcs/rendering/texture.c

SRCS += srcs/utils/get_next_line.c \
        srcs/utils/utils.c

# ---------------  --------------- #

NAME	=			cub3D

OBJS	=			$(SRCS:%.c=%.o)

CC		=			gcc

RM		=			rm -f

CFLAGS	=			-Wall -Wextra -Werror -g -w -O2 #-fsanitize=address

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
					${CC} ${CFLAGS} -Iincls -Ilibft -I${MLX_DIR} -c $? -o $@

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