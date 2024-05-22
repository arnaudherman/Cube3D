

NAME = cub3D

SRCS := src/main.c\
			src/parsing/parsing.c\
			src/parsing/len_map.c\
			src/parsing/len_map_utils.c\
			src/parsing/color.c\
			src/parsing/color_utils.c\
			src/parsing/save_texture.c\
			src/parsing/found_texture.c\
			src/parsing/map.c\
			src/parsing/map_utils.c\
			src/parsing/map_on.c\
			src/parsing/map_data.c\
			src/error/error.c\
			src/libft/get_next_line.c\
			src/libft/libft_one.c\
			src/libft/libft_two.c\
			src/libft/libft_three.c\
			src/libft/libft_four.c\
			src/libft/libft_five\


CC = gcc
CFLAGS = -Wall -Wextra -Werror -I -g
OBJS = $(SRCS:.c=.o)


all: ${NAME} ${CHECK} ${OBJS}
${NAME}: ${OBJS}
	@${MAKE} -C ./ft_printf
	@${MAKE} -C ./minilibx
	@${CC} ${CFLAGS} ${OBJS} -L ./ft_printf -l ft_printf -L ./minilibx -l mlx -framework OpenGL -framework AppKit -o $(NAME)

${CHECK}: ${CHECK_OBJS} 
	@${CC} ${CFLAGS} ${CHECK_OBJS} -I ./ft_printf/ -I ./minilibx/-o ${CHECK}
clean: 
	@${MAKE} -C ./ft_printf fclean
	@${MAKE} -C ./minilibx fclean
	@${RM} ${OBJS}
	@${RM} ${CHECK_OBJS}

fclean: clean
	@${RM} ${NAME}
	@${RM} ${CHECK}

re: fclean all
