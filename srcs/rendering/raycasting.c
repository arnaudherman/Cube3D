#include "cub3d.h"

void    draw_line(t_image *img, int x_start, int y_start, int x_end, int y_end, int color)
{
    int dx = x_end - x_start;
    int dy = y_end - y_start;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float x_increment = dx / (float)steps;
    float y_increment = dy / (float)steps;

    float x = x_start;
    float y = y_start;

    for (int i = 0; i <= steps; i++)
    {
        my_mlx_pixel_put(img, x, y, color);
        // my_mlx_pixel_put(img, round(x), round(y), color);
        x += x_increment;
        y += y_increment;
    }
}

// BRO U USE CHAR INSTEAD OF INT IN MAP2D
// BRO U USE CHAR INSTEAD OF INT IN MAP2D
// BRO U USE CHAR INSTEAD OF INT IN MAP2D !!!
void    dda(t_data *data, t_map *map, t_ray *ray)
{
    int map_x;
    int map_y;

    map_x = ray->x_map / 32;
    map_y = ray->y_map / 32;
    while (ray->hit == 0)
    {
        if (ray->sx < ray->sy)
        {
            ray->sx += ray->dx;
            ray->x_map += ray->x_step;
            if (ray->x_step == -1)
                ray->side = 0; // West
            else
                ray->side = 1; // East        
        }
        else
        {
            ray->sy += ray->dy;
            ray->y_map += ray->y_step;
            if (ray->y_step == -1)
                ray->side = 2; // North
            else
                ray->side = 3; // South        
        }
        // Wall hit detection
        if (ray->x_map >= 0 && ray->x_map < map->w_map * 32 &&
            ray->y_map >= 0 && ray->y_map < map->h_map * 32)
            {
                
                int map_x = ray->x_map / 32;
                int map_y = ray->y_map / 32;
                
                if (map->map2d[map_y][map_x] == '1')
                {
                    ray->hit = 1;
                    printf("ray->y_map = %d\n", ray->y_map);
                    printf("ray->x_map = %d\n", ray->x_map);
                    printf("Hit wall: map->map2d[%d][%d] = %c\n", map_y, map_x, map->map2d[map_y][map_x]);
                }
                else 
                    my_mlx_pixel_put(data->map2d, map_x, map_y, 0xFF0000);
            }
        else
        {
            // Coordinate outside bounds
            printf("ray->y_map = %d, ray->x_map = %d\n", ray->y_map, ray->x_map); // DEBUG y 111 et x 110
            printf("map->map2d[ray->y_map][ray->x_map] = %d\n", map->map2d[ray->y_map / 32][ray->x_map / 32]);
            printf("Error: In DDA() map->map2d[ray->y_map][ray->x_map] is out of bounds\n");
            exit(1);
        }
    }
}

void    get_perp_and_height(t_ray *ray, t_player *player, t_mlx *mlx)
{
    if (ray->side == 0)
        ray->wall_dist = (ray->x_map - player->x_pos + (1 - ray->x_step) / 2) / ray->dir_x;
    else
        ray->wall_dist = (ray->y_map - player->y_pos + (1 - ray->y_step) / 2) / ray->dir_y;

    // Handle fish-eye
    ray->wall_dist *= cos(ray->camera_x * M_PI / 180);

    ray->line_height = (int)(mlx->win_height / ray->wall_dist) * 8; // Adjust wall height x8

    ray->draw_start = -ray->line_height / 2 + mlx->win_height / 2;
    if (ray->draw_start < 0)
        ray->draw_start = 0;
    ray->draw_end = ray->line_height / 2 + mlx->win_height / 2;
    if (ray->draw_end >= mlx->win_height)
        ray->draw_end = mlx->win_height - 1;
}

void    raycasting(t_data *data, t_player *player, t_mlx *mlx)
{
    t_ray ray;
    ray.x = 0;

    if (!(ray.z_index = (double *)malloc(sizeof(double) * mlx->win_width)))
        perror("Malloc z_index failed in raycasting();\n");

    ft_bzero(ray.z_index, sizeof(double) * mlx->win_width);

    while (ray.x < mlx->win_width)
    {
        init_ray(&ray, player);
        dda(data, &data->map, &ray);
        get_perp_and_height(&ray, player, mlx);
        draw_col(data, mlx, &ray);
        ray.x++;
    }
    
    free(ray.z_index);

    mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.mlx_win_ptr, data->world->img, 0, 0);
}


        
