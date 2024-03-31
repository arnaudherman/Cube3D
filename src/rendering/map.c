#include "../include/cub3d.h"

 int map2d[MAP_WIDTH][MAP_HEIGHT] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 1, 1, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

void draw_square(void *mlx_ptr, void *win_ptr, int x, int y, int color)
{
    int i;
    int j;

    i = 0;
    while (i < TILE_SIZE)
    {
        j = 0;
        while (j < TILE_SIZE)
        {
            mlx_pixel_put(mlx_ptr, win_ptr, x + i, y + j, color);
            j++;
        }
        i++;
    }
}

void draw_map(void *mlx_ptr, void *mlx_win_ptr/*, t_map map_data*/)
{
    int x;
    int y;
    
	// TO DO : use t_map struct ?
    // int h_map = map_data.h_map;
    // int w_map = map_data.w_map;
    // char **map2d = map_data.map2d;
	// int h_map = 10;
    // int w_map = 10;
    y = 0;
    while (y < MAP_HEIGHT)
    {
        x = 0;
        while (x < MAP_WIDTH)
        {
            if (map2d[y][x] == 1)
                draw_square(mlx_ptr, mlx_win_ptr, x * TILE_SIZE, y * TILE_SIZE, 0xFFFFFF); // white empty space
            else
                draw_square(mlx_ptr, mlx_win_ptr, x * TILE_SIZE, y * TILE_SIZE, 0xFF0000); // red wall
            x++;
        }
        y++;
    }
}

// void display_map()
// {
//     draw_map2D();
//     draw_player();
// }