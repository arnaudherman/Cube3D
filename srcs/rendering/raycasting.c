#include "cub3d-bis.h"

// RESSOURCES : 
// Raycasting : https://lodev.org/cgtutor/raycasting.html
// DDA Algorithm https://lodev.org/cgtutor/raycasting.html
// Video https://www.youtube.com/watch?v=NbSee-XM7WA&t=1s&ab_channel=javidx9
// https://www.youtube.com/watch?v=W5P8GlaEOSI&ab_channel=AbdulBari

// OG VERSION do not touch
// TO DO : check x became x1 and y became y1 problem ?
// void perform_dda(t_ray *ray, t_map *map, int x, int y) 
// {
//     int hit = 0;
//     while (hit == 0) 
// 	{
//         if (ray->sidedist_x < ray->sidedist_y) 
// 		{
//             ray->sidedist_x += ray->dx;
//             ray->map_x += ray->x1;
// 			if (ray->x1 == -1)
// 				ray->side = 0;
// 			else
// 				ray->side = 1;
//         } else {
//             ray->sidedist_y += ray->dy;
//             ray->map_y += ray->y1;
// 			if (ray->y1 == -1)
// 			{
// 				ray->side = 2;
// 				printf("c debug this shit\n");
// 			}
				
// 			else
// 			{
// 				ray->side = 3;
// 				printf("d debug this shit\n");
// 			}
//         }
// 		printf("5 debug this shit\n");
// 		// TO DO : CORRECT FUCKING PROBLEM HERE
// 		if (map->map2d[(int)ray->map_y][(int)ray->map_x] != '0')
// 		printf(" 6 mamamia debug this shit\n");
// 			hit = 1;
//     }
// }

// TO DO : check x became x1 and y became y1 problem ?
// TO DO : use of ray->map_x or ray->map_y really ?
void perform_dda(t_ray *ray, t_map *map) 
{
    int hit = 0;
    while (hit == 0) 
	{
        if (ray->sidedist_x < ray->sidedist_y) 
		{
            ray->sidedist_x += ray->dx;
            ray->map_x += ray->x1;
			if (ray->x1 == -1)
				ray->side = 0;
			else
				ray->side = 1;
        } else {
            ray->sidedist_y += ray->dy;
            ray->map_y += ray->y1;
			if (ray->y1 == -1)
			{
				ray->side = 2;
				printf("c debug this shit\n");
			}
				
			else
			{
				ray->side = 3;
				printf("d debug this shit\n");
			}
        }
		printf("5 debug this shit\n");
		// TO DO : CORRECT FUCKING PROBLEM HERE
		// Previous function was : if (map->map2d[y / TILE_SIZE][x / TILE_SIZE] != '0')
		if (map->map2d[(int)ray->map_y][(int)ray->map_x] != '0')
		printf(" 6 mamamia debug this shit\n");
			hit = 1;
    }
}

void draw_ray(t_image *map2d, t_image *world, t_map *map, t_ray *ray, t_data *data) {
    int i;
    int x, y;
    float current_x;
    float current_y;

	get_steps(ray);
    if (ray->steps == 0)
        return;

    get_step_sizes(ray);

    current_x = ray->x1;
    current_y = ray->y1;

    i = 0;
    while (i <= ray->steps) 
	{
        x = (int)current_x;
        y = (int)current_y;

		// TO DO : CORRECT everything before draw 3D world walls
		// draw_wall(data, ray);
        my_mlx_pixel_put(map2d, x / TILE_SIZE, y / TILE_SIZE, 0xffd55c);

        current_x += ray->step_x;
        current_y += ray->step_y;
        i++;
    }
}

void shoot_rays(t_image *map2d, t_image *world, t_player *player, t_map *map, t_ray *ray, t_data *data) {
    double start_angle;
	double angle_increment;
	double angle_rad;
	int i;

	start_angle = player->angle - (player->fov / 2.0);
    angle_increment = player->fov / WINDOW_WIDTH;
	i = 0;
    while (i < WINDOW_WIDTH) {
        angle_rad = (start_angle + i * angle_increment) * (M_PI / 180.0);

        ray->x2 = (int)(player->x_pos + cos(angle_rad) * ray->ray_length);
        ray->y2 = (int)(player->y_pos + sin(angle_rad) * ray->ray_length);

        if (ray->x2 < 0) ray->x2 = 0;
        if (ray->x2 >= (MAP_WIDTH * TILE_SIZE)) ray->x2 = (MAP_WIDTH * TILE_SIZE) - 1;
        if (ray->y2 < 0) ray->y2 = 0;
        if (ray->y2 >= (MAP_HEIGHT * TILE_SIZE)) ray->y2 = (MAP_HEIGHT * TILE_SIZE) - 1;

        draw_ray(map2d, world, map, ray, data);
		i++;
    }
}

int raycasting(t_data *data) {
    shoot_rays(data->map2d, data->world, data->player, &data->map, data->ray, data);
    return 0;
}
