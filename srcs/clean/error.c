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

void debug_ray(t_ray *ray) {
    if (!ray) {
        printf("ray is NULL\n");
        return;
    }
    // printf("ray->side = %d\n", ray->side); // TO DO CORRECT VALUE HERE
    printf("ray->x = %d\n", ray->x);
    printf("ray->y = %d\n", ray->y);
    printf("ray->dir_x = %f\n", ray->dir_x);
    printf("ray->dir_y = %f\n", ray->dir_y);
    printf("ray->map_x = %f\n", ray->map_x);
    printf("ray->map_y = %f\n", ray->map_y);
    printf("ray->dx = %f\n", ray->dx);
    printf("ray->dy = %f\n", ray->dy);
    printf("ray->sidedist_x = %f\n", ray->sidedist_x);
    printf("ray->sidedist_y = %f\n", ray->sidedist_y);
}