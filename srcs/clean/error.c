#include "cub3d.h"

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

void print_ray_info(t_ray *ray) 
{
    printf("Ray Info:\n");
    printf("x: %d\n", ray->x);
    printf("y: %d\n", ray->y);
    printf("x_map: %d\n", ray->x_map);
    printf("y_map: %d\n", ray->y_map);
    printf("x_step: %d\n", ray->x_step);
    printf("y_step: %d\n", ray->y_step);
    printf("hit: %d\n", ray->hit);
    printf("side: %d\n", ray->side);
    printf("line_height: %d\n", ray->line_height);
    printf("draw_start: %d\n", ray->draw_start);
    printf("draw_end: %d\n", ray->draw_end);
    printf("x_text: %d\n", ray->x_text);
    printf("y_text: %d\n", ray->y_text);
    printf("wall_x: %f\n", ray->wall_x);
    printf("z_index: %p\n", (void*)ray->z_index);
    printf("camera_x: %f\n", ray->camera_x);
    printf("wall_dist: %f\n", ray->wall_dist);
    printf("dir_x: %f\n", ray->dir_x);
    printf("dir_y: %f\n", ray->dir_y);
    printf("sx: %f\n", ray->sx);
    printf("sy: %f\n", ray->sy);
    printf("dx: %f\n", ray->dx);
    printf("dy: %f\n", ray->dy);
}

