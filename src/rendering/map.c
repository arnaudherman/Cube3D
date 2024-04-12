#include "cub3d.h"

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

void draw_map(void *mlx_ptr, void *win_ptr) {
    int x = 0, y = 0;

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
            if (map2d[y][x] == 1) {
                // Dessiner une tile de mur (si map2d[y][x] est 1, cela signifie que c'est un mur)
                // Utilisez draw_square pour dessiner un carré à la place de mlx_rectangle_put
                draw_square(mlx_ptr, win_ptr, x * TILE_SIZE, y * TILE_SIZE, 0xFF0000);
            }
            // Ajoutez d'autres conditions pour d'autres types de tiles si nécessaire
            x++;
        }
        y++;
    }
}
