

NAME = cub3D

SRCS := src/main.c\
			src/parsing/parsing.c\
			src/parsing/len_map.c\
			src/parsing/color.c\
			src/parsing/texture.c\
			src/parsing/map.c\
			src/error/error.c\
			src/libft/get_next_line.c\
			src/libft/libft_one.c\
			src/libft/libft_two.c\
			src/libft/libft_three.c\
			src/libft/libft_four.c\


CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.
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
