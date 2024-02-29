# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 16:50:19 by aherman           #+#    #+#              #
#    Updated: 2023/03/07 14:10:29 by aherman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_printf.a

SRCS = src/ft_printf.c \
			src/print_c.c \
			src/print_d.c \
			src/print_maj_x.c \
			src/print_p.c \
			src/print_s.c \
			src/print_u.c \
			src/print_x.c \

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.
OBJS = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):$(OBJS)
			ar rc $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS) $(BONUS_OBJS)

fclean:	clean
			$(RM) $(NAME)

re:	fclean $(NAME)