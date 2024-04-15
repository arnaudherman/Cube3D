#include "cub3d.h"

void init_my_map()
{
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

	int rows = sizeof(map2d)/sizeof(map2d[0]);
	int columns = sizeof(map2d[0])/sizeof(map2d[0][0]);

	printf("rows: %d\n", rows);
	printf("columns: %d\n", columns);
}

void draw_square(void *mlx_ptr, void *win_ptr, t_player *player, t_data *data, t_map *map)
{
    int i;
    int j;

	init_my_map();

    i = 0;
    while (i < MAP_WIDTH)
    {
        j = 0;
        while (j < MAP_HEIGHT)
        {
            my_mlx_pixel_put(data, player->x_pos + i, player->y_pos + j, map->color);
            j++;
        }
        i++;
    }
}

void draw_map(void *mlx_ptr, void *win_ptr, t_player player) {
    int x = 0;
    int y = 0;
	t_map *map;

	map = (t_map *)malloc(sizeof(t_map));

    // Dessiner les lignes verticales
    while (x <= MAP_WIDTH * TILE_SIZE) {
        mlx_pixel_put(mlx_ptr, win_ptr, x, 0, 0xFFFFFF); // Ligne en haut
        mlx_pixel_put(mlx_ptr, win_ptr, x, MAP_HEIGHT * TILE_SIZE, 0xFFFFFF); // Ligne en bas
        x += TILE_SIZE;
    }

    // Dessiner les lignes horizontales
    while (y <= MAP_HEIGHT * TILE_SIZE) {
        mlx_pixel_put(mlx_ptr, win_ptr, 0, y, 0xFFFFFF); // Ligne à gauche
        mlx_pixel_put(mlx_ptr, win_ptr, MAP_WIDTH * TILE_SIZE, y, 0xFFFFFF); // Ligne à droite
        y += TILE_SIZE;
    }

    // Dessiner les tiles
    y = 0;
    while (y < MAP_HEIGHT) {
        x = 0;
        while (x < MAP_WIDTH) {
            if (map->map2d[y][x] == 1) {
                // Dessiner une tile de mur (si map2d[y][x] est 1, cela signifie que c'est un mur)
                draw_square(mlx_ptr, win_ptr, x * TILE_SIZE, y * TILE_SIZE, 0xFF0000);
            }
            // Ajoutez d'autres conditions pour d'autres types de tiles si nécessaire
            x++;
        }
        y++;
    }
    // Dessiner le joueur
    draw_player(mlx_ptr, win_ptr, &player);
}
