# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 12:15:54 by aherman           #+#    #+#              #
#    Updated: 2024/02/29 16:40:18 by aherman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS := src/main.c\

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
