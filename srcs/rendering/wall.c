#include "cub3d-bis.h"

// From player to wall hit
void	get_wall_dist(t_player *player, t_ray *ray)
{
    float dx;
	float dy;

	dx = ray->x_end - player->x_pos;
    dy = ray->y_end - player->y_pos;
    ray->wall_dist = sqrt(dx * dx + dy * dy);
}

void	get_wall_height(t_ray *ray)
{
	if (ray->wall_dist == 0)
		ray->wall_dist = 1;
	ray->wall_height = (int)(WALL_HEIGHT / ray->wall_dist);
}

void draw_wall_column(t_image *world, int column, int wall_height)
{
    int top;
	int bottom;
	int y;
	
	top = (WINDOW_HEIGHT - wall_height) / 2;
    bottom = top + wall_height;
    y = top;
    while (y < bottom)
    {
        my_mlx_pixel_put(world, column, y, 0xBBA498);
        y++;
    }
}

// void yoooodraw_wall(t_image *image, int x, int y) {
//     for (int i = y; i < y + TILE_SIZE; i++) {
//         for (int j = x; j < x + TILE_SIZE; j++) {
//             my_mlx_pixel_put(image, j, i, 0x02471A); // White color for walls
//         }
//     }
// }

void draw_wall(t_data *data, int x, int y)
{
    // Convertir les coordonnées de la grille en coordonnées du monde
    float world_x = data->player->x_pos + x * TILE_SIZE;
    float world_y = data->player->y_pos + y * TILE_SIZE;

    // Convertir les coordonnées du monde en coordonnées de l'écran
    float screen_x = (world_x - data->player->x_pos) * cos(data->player->angle) - (world_y - data->player->y_pos) * sin(data->player->angle) + data->player->x_pos;
    float screen_y = (world_x - data->player->x_pos) * sin(data->player->angle) + (world_y - data->player->y_pos) * cos(data->player->angle) + data->player->y_pos;

    // Calculer la distance entre le mur et le joueur (à titre d'exemple, vous pouvez utiliser une autre méthode pour cela)
    float distance = sqrt((screen_x - data->player->x_pos) * (screen_x - data->player->x_pos) + (screen_y - data->player->y_pos) * (screen_y - data->player->y_pos));

    // Calculer la hauteur du mur sur l'écran en fonction de sa distance
    int wall_height = (int)(WALL_HEIGHT / distance);

    // Dessiner le mur sur l'écran
    draw_wall_column(data, x, wall_height);
}

