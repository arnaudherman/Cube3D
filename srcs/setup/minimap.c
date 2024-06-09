#include "cub3d.h"

// char minimap_data[MAP_HEIGHT][MAP_WIDTH] = {
//     {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
//     {'1', '0', '0', '0', '0', '0', '1', '0', '0', '1'},
//     {'1', '0', '1', '0', '1', '1', '1', '1', '0', '1'},
//     {'1', '0', '1', '0', '0', '0', '0', '1', '0', '1'},
//     {'1', '0', '1', '1', '1', '1', '0', '1', '0', '1'},
//     {'1', '0', '1', '0', '1', '1', '0', '1', '0', '1'},
//     {'1', '0', '0', '0', '0', '0', '0', '1', '0', '1'},
//     {'1', '0', '1', '1', '1', '1', '1', '1', '0', '1'},
//     {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
//     {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
// };

// int malloc_minimap2d(t_minimap *minimap)
// {
//     minimap->minimap2d = (char **)malloc(minimap->h_minimap * sizeof(char *));
//     if (minimap->minimap2d == NULL) {
//         perror("fail in malloc_minimap2d\n");
//         return -1;
//     }
//     return 0;
// }

// int fill_minimap(t_minimap *minimap)
// {
//     int i;

//     for (i = 0; i < minimap->h_minimap; i++) {
//         minimap->minimap2d[i] = (char *)malloc((minimap->w_minimap + 1) * sizeof(char));
//         if (minimap->minimap2d[i] == NULL) 
// 		{
//             perror("fail in fill_minimap\n");
//             while (i > 0) {
//                 free(minimap->minimap2d[--i]);
//             }
//             free(minimap->minimap2d);
//             return -1;
//         }
//     }
//     for (i = 0; i < minimap->h_minimap; i++) {
//         for (int j = 0; j < minimap->w_minimap; j++) {
//             minimap->minimap2d[i][j] = minimap_data[i][j];
//         }
//         minimap->minimap2d[i][minimap->w_minimap] = '\0';
//     }

//     return 0;
// }


// int init_minimap(t_minimap *minimap) 
// {
// 	int i;
// 	minimap->w_minimap = MAP_WIDTH;
// 	minimap->h_minimap = MAP_HEIGHT;

// 	 if (malloc_minimap2d(minimap) == -1) {
//         perror("Failed to allocate memory for map2d\n");
//         return -1;
//     }
//     if (fill_minimap(minimap) != 0) {
// 		i = -1;
// 		while (++i < minimap->h_minimap)
//             free(minimap->minimap2d[i]);
//         free(minimap->minimap2d);
//         return -1;
//     }

//     minimap->tile_size = 8;
// 	minimap->x_minimap = 0;
// 	minimap->y_minimap = 0;
// 	minimap->color = 0xBBA498;
// 	minimap->img = allocate_image();
// 	minimap->ray = allocate_ray();
//     return 0;
// }

// void complete_minimap(t_minimap *minimap, t_mlx *mlx, t_ray *ray, t_player *player)
// {
// 	init_minimap(minimap);
// 	init_image(minimap->img, mlx);
// 	init_rays(minimap->ray, player);
// }