#include "cub3d-bis.h"

// From player to wall hit
void	get_wall_dist(t_data *data)
{
	data->ray->dx = data->ray->x2 - data->player->x_pos;
    data->ray->dy = data->ray->y2 - data->player->y_pos;
    data->ray->wall_dist = sqrt(data->ray->dx * data->ray->dx 
						+ data->ray->dy * data->ray->dy);
}

void	get_wall_height(t_data *data)
{
	if (data->ray->wall_dist == 0)
		data->ray->wall_dist = 1;
	data->ray->wall_height = (int)(WALL_HEIGHT / data->ray->wall_dist);
}

void draw_wall_column(t_data *data, int column)
{
	int top;
	int bottom;
	int y;

    top = (WINDOW_HEIGHT - data->ray->wall_height) / 2;
    bottom = top + data->ray->wall_height;

    if (top < 0)
		top = 0;
    if (bottom >= WINDOW_HEIGHT)
		bottom = WINDOW_HEIGHT - 1;

	y = top;
    while (y <= bottom)
    {
        my_mlx_pixel_put(data->world, column, y, 0x451800);
		y++;
    }
}

void draw_wall(t_data *data)
{
	int column;
	
	column = 0;
    while ( column < WINDOW_WIDTH)
    {
        // Calcul de l'angle du rayon pour chaque colonne
        float ray_angle = data->player->angle - (FOV / 2.0) + ((float)column / (float)WINDOW_WIDTH) * FOV;
        
        // Initialiser les coordonnées du rayon
        data->ray->x1 = data->player->x_pos;
        data->ray->y1 = data->player->y_pos;
        data->ray->angle = ray_angle;

        // Calculer la distance au mur
        get_wall_dist(data);
        
        // Calculer la hauteur du mur en fonction de la distance
        get_wall_height(data);
        
        // Dessiner la colonne du mur
        draw_wall_column(data, column);
		column++;
    }
}
