#include "cub3d-bis.h"

float degrees_to_radians(float angle)
{
    return angle * (M_PI / 180.0);
}

float radians_to_degrees(float angle)
{
    return angle * (180.0 / M_PI);
}

// void draw_ray(t_image *image, int x_start, int y_start, int x_end, int y_end)
// {
// 	for (int y = y_start; y < y_end; y++)
// 	{
// 		for (int x = x_start; x < x_end; x++)
// 		{
// 			my_mlx_pixel_put(image, x, y, 0xe19239);
// 		}
// 	}
// }

// void cast_ray(t_image *image, t_player *player) 
// {
//     int x_start;
// 	int x_end;
// 	int y_start;
// 	int y_end;
	
// 	x_start = (int)(player->x_pos);
//     y_start = (int)(player->y_pos);

// 	double angle_rad = player->angle * (M_PI / 180.0);
	
// 	x_end = x_start + (int)(cos(angle_rad) * RAY_LENGTH);
//     y_end = y_start + (int)(sin(angle_rad) * RAY_LENGTH);
// 	// x_end = x_start + 100;
//     // y_end = y_start + 100;

// 	// // To do : fin du rayon en fonction de l'angle du joueur
// 	// x_end = x_start + (int)cos(degrees_to_radians(player->angle)) * RAY_LENGTH;
//     // y_end = y_start + (int)sin(degrees_to_radians(player->angle)) * RAY_LENGTH;
// 	printf("before draw ray : x_end = %d, y_end = %d\n, angle = %f", x_end, y_end, player->angle);
//     draw_ray(image, x_start, y_start, x_end, y_end);
// }

// TEST
void draw_ray(t_image *image, int x_start, int y_start, int x_end, int y_end)
{
    int x, y;
    int dx = x_end - x_start;
    int dy = y_end - y_start;
    
    // Determine the sign of the step (i.e., +1 or -1) for each dimension
    int sign_x = (dx > 0) ? 1 : -1;
    int sign_y = (dy > 0) ? 1 : -1;
    
    // Determine the number of steps required along each dimension
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    
    // Calculate the increment for each dimension per step
    float step_x = (float)dx / steps;
    float step_y = (float)dy / steps;
    
    // Initialize the starting position
    float current_x = x_start;
    float current_y = y_start;
    
    // Draw the ray by iterating through each step
    for (int i = 0; i <= steps; i++)
    {
        x = (int)current_x;
        y = (int)current_y;
        my_mlx_pixel_put(image, x, y, 0xe19239);
        
        // Move to the next position along each dimension
        current_x += step_x;
        current_y += step_y;
    }
}

void cast_ray(t_image *image, t_player *player) 
{
    int x_start, x_end, y_start, y_end;
    
    x_start = (int)(player->x_pos);
    y_start = (int)(player->y_pos);

    double angle_rad = player->angle * (M_PI / 180.0);
    
    x_end = x_start + (int)(cos(angle_rad) * RAY_LENGTH);
    y_end = y_start + (int)(sin(angle_rad) * RAY_LENGTH);

	if (x_end < 0) x_end = 0;
    if (x_end >= (MAP_WIDTH * 64)) x_end = (MAP_WIDTH * 64) - 1;
    if (y_end < 0) y_end = 0;
    if (y_end >= (MAP_HEIGHT * 64)) y_end = (MAP_HEIGHT * 64) - 1;
    
    draw_ray(image, x_start, y_start, x_end, y_end);
}
