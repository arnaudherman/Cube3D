# Do mind that you need the libmlx.dylib in the same 
# directory as your build target as it is a dynamic library!

# FINAL EXECUTABLE NAME
NAME = Cub3D

# DIRECTORIES
HEADER_DIRECTORY := ./include
SRCS_DIRECTORY := ./src
LIBFT_FOLDER := $(SRCS_DIRECTORY)/libft/libftbat

# ALL FILES.C
MAIN := main.c
SRCS := src/main.c\
			src/parsing/parsing.c\
			src/parsing/len_map.c\
			src/parsing/color.c\
			src/parsing/texture.c\
			src/error/error.c\
			src/libft/get_next_line.c\
			src/libft_one.c\
			src/libft_two.c\
			src/libft_three.c\

# GLOBAL VARIABLES
CC = gcc
#CC := gcc -O3 -ffast-math -framework Cocoa -framework OpenGL -framework IOKit -lglfw (path to libmlx42.a) -L(path to glfw library) cub3d.c -o cub
CFLAGS := -Wall -Wextra -Werror -O3 -g -I$(HEADER_DIRECTORY)
OBJS = $(SRCS:.c=.o)
RM := rm -f

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all: ${NAME} ${CHECK} ${OBJS}

${NAME}: ${OBJS}
	@${MAKE} -C ./ft_printf
	@${MAKE} -C ./src/libft/libftbat
	@${MAKE} -C ./minilibx
	@${CC} ${CFLAGS} ${OBJS} -L ./ft_printf -l ft_printf -L ./minilibx -l mlx -framework OpenGL -framework AppKit -o $(NAME)

${CHECK}: ${CHECK_OBJS} 
	@${CC} ${CFLAGS} ${CHECK_OBJS} -I ./ft_printf/ -I ./minilibx/-o ${CHECK}

clean: 
	@${MAKE} -C ./ft_printf fclean
	@${MAKE} -C ./minilibx fclean
	@${RM} ${OBJS}
	@${RM} ${CHECK_OBJS}
	@make -C $(LIBFT_FOLDER) clean

fclean: clean
	@${RM} ${NAME}
	@${RM} ${CHECK}
	@make -C $(LIBFT_FOLDER) fclean

re: fclean all
