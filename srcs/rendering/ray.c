#include "cub3d-bis.h"

float degrees_to_radians(float angle)
{
    return angle * (M_PI / 180.0);
}

float radians_to_degrees(float angle)
{
    return angle * (180.0 / M_PI);
}

void draw_ray(t_image *image, int x_start, int y_start, int x_end, int y_end)
{
	for (int y = y_start; y < y_end; y++)
	{
		for (int x = x_start; x < x_end; x++)
		{
			my_mlx_pixel_put(image, x, y, 0xe19239);
		}
	}
}

void cast_ray(t_image *image, t_player *player) 
{
    int x_start;
	int x_end;
	int y_start;
	int y_end;
	
	x_start = (int)(player->x_pos);
    y_start = (int)(player->y_pos);

	double angle_rad = player->angle * (M_PI / 180.0);
	
	x_end = x_start + (int)(cos(angle_rad) * RAY_LENGTH);
    y_end = y_start + (int)(sin(angle_rad) * RAY_LENGTH);
	// x_end = x_start + 100;
    // y_end = y_start + 100;

	// // To do : fin du rayon en fonction de l'angle du joueur
	// x_end = x_start + (int)cos(degrees_to_radians(player->angle)) * RAY_LENGTH;
    // y_end = y_start + (int)sin(degrees_to_radians(player->angle)) * RAY_LENGTH;
	printf("-----------x_end: %d, y_end: %d\n", x_end, y_end);
    draw_ray(image, x_start, y_start, x_end, y_end);
}
