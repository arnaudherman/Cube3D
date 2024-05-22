#include "cub3d-bis.h"

// OG version DO NOT TOUCH
// Fonction simple pour calculer les pas nécessaires pour se déplacer 
// d'un point initial à un point final dans un espace 2D
// void get_steps(int x1, int y1, int x2, int y2, int *dx, int *dy, int *steps) 
// {
//  // mon delta x et y
// 	*dx = x2 - x1;
//     *dy = y2 - y1;
// 	// valeur absolue de dx > celle de dy ?
//     if (abs(*dx) > abs(*dy)) 
//         *steps = abs(*dx);
// 	// Sinon distance verticale > distance horizontale
//     else 
//         *steps = abs(*dy);
// }

// Fonction simple pour calculer les pas nécessaires pour se déplacer 
// d'un point initial à un point final dans un espace 2D
void get_steps(t_ray *ray)
{
	// mon delta x et y
	ray->dx = ray->x2 - ray->x1;
    ray->dy = ray->y2 - ray->y1;
	// valeur absolue de dx > celle de dy ?
    if (abs(ray->dx) > abs(ray->dy)) 
        ray->steps = abs(ray->dx);
	// Sinon distance verticale > distance horizontale
    else 
        ray->steps = abs(ray->dy);
}

// OG version DO NOT TOUCH
// void get_step_sizes(int dx, int dy, float *step_x, float *step_y, int steps) 
// {
//     *step_x = (float)dx / steps;
//     *step_y = (float)dy / steps;
// }

void get_step_sizes(t_ray *ray) 
{
    ray->step_x = (float)ray->dx / ray->steps;
    ray->step_y = (float)ray->dy / ray->steps;
}

void	get_delta_dist(t_ray *ray)
{
	if (ray->dir_y == 0)
		ray->dx = 0;
	else if (ray->dir_x == 0)
		ray->dx = 1;
	else
		ray->dx = fabs(1 / ray->dir_x);

	if (ray->dir_x == 0)
		ray->dy = 0;
	else if (ray->dir_y == 0)
		ray->dy = 1;
	else
		ray->dy = fabs(1 / ray->dir_y);
}


// TO DO check if it is really x1, casuse x changed
void	get_side_dist(t_ray *ray, t_player *player)
{
	if (ray->dir_x < 0)
	{
		ray->x1 = -1;
		ray->sidedist_x = (player->x_pos - ray->map_x) * ray->dx;
	}
	else
	{
		ray->x1 = 1;
		ray->sidedist_x = (ray->map_x - player->x_pos + 1.0) * ray->dx;
	}
	if (ray->dir_y < 0)
	{
		ray->y1 = -1;
		ray->sidedist_y = (player->y_pos - ray->map_y) * ray->dy;
	}
	else
	{
		ray->y1 = 1;
		ray->sidedist_y = (ray->map_y - player->y_pos + 1.0) * ray->dy;
	}
}