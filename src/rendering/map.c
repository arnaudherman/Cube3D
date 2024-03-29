#include "../include/cub3d.h"

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

void draw_map(void *mlx_ptr, void *win_ptr/*, t_map map_data*/)
{
    int x;
    int y;
    
	// TO DO : use t_map struct ?
    // int h_map = map_data.h_map;
    // int w_map = map_data.w_map;
    // char **map2d = map_data.map2d;

	int h_map = 10;
    int w_map = 10;

    int map2d[10][10] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
		};

    y = 0;
    while (y < h_map)
    {
        x = 0;
        while (x < w_map)
        {
            if (map2d[y][x] == '1')
                draw_square(mlx_ptr, win_ptr, x * TILE_SIZE, y * TILE_SIZE, 0x000000); // black color for wall
            else
                draw_square(mlx_ptr, win_ptr, x * TILE_SIZE, y * TILE_SIZE, 0xFFFFFF); // white color for empty space
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