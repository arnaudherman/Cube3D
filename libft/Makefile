# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 17:04:37 by bbessard          #+#    #+#              #
#    Updated: 2023/08/18 13:24:19 by bbessard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INCLUDES    = -I includes -I $(LIBFT_DIR)/includes/

LIBFT_DIR   = libft/

CC = gcc

CFLAGS = -Wall -Wextra -Werror -O3

RM = rm -f

LDFLAGS = -L.

LDLIBS = -lft

HDDIRS = -I includes/

AR = ar rc

HEADER = libft.h

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
ft_isdigit.c ft_isprint.c ft_memcpy.c ft_memmove.c ft_memset.c \
ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_tolower.c ft_toupper.c \
ft_strchr.c ft_calloc.c ft_memchr.c ft_memcmp.c ft_strdup.c \
ft_strncmp.c ft_strnstr.c ft_strrchr.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
get_next_line.c get_next_line_utils.c \

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean git norminette re 
