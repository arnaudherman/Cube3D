#include "cub3d-bis.h"

// void	ft_error(char *error)
// {
// 	ft_putendl_fd(error, 2);
// 	exit(-1);
// }

int err(char *str)
{	
	while (*str)
		write(2, str++, 1);
	return 1;
}

// DO NOT FORGET ray->map_x et ray->map_y must be divided by TILE_SIZE
// to obtain map coordinates so divide by 32 or TILE_SIZE in the code
void debug_ray(t_ray *ray) {
    if (!ray) {
        perror("ray is NULL\n");
        return;
    }
    // printf("ray->side = %d\n", ray->side); // TO DO CORRECT VALUE HERE
    printf("ray->x1 = %d\n", ray->x1);
    printf("ray->y1 = %d\n", ray->y1);
	printf("ray->x2 = %d\n", ray->x2);
    printf("ray->y2 = %d\n", ray->y2);
	printf("ray->step = %d\n", ray->steps);
	printf("ray->step_x = %d\n", ray->step_x);
	printf("ray->step_y = %d\n", ray->step_y);
    printf("ray->dir_x = %f\n", ray->dir_x);
    printf("ray->dir_y = %f\n", ray->dir_y);
    printf("ray->map_x = %f\n", ray->map_x);
    printf("ray->map_y = %f\n", ray->map_y);
    printf("ray->dx = %f\n", ray->dx);
    printf("ray->dy = %f\n", ray->dy);
    printf("ray->sidedist_x = %f\n", ray->sidedist_x);
    printf("ray->sidedist_y = %f\n", ray->sidedist_y);
}
