#include "cub3d-bis.h"

// Fonction simple pour calculer les pas nécessaires pour se déplacer 
// d'un point initial à un point final dans un espace 2D
void get_steps(t_data *data)
{
	float distance;

    // Calcul de la distance horizontale et verticale
    data->ray->dx = data->ray->x2 - data->ray->x1;
    data->ray->dy = data->ray->y2 - data->ray->y1;
    
    // Calcul de la distance totale parcourue par le rayon
    distance = sqrt(data->ray->dx * data->ray->dx + data->ray->dy * data->ray->dy);

    // Détermination du nombre d'étapes en fonction de la distance totale
    // data->ray->steps = distance / STEP_LENGTH; // STEP_LENGTH est la longueur d'étape fixe
	data->ray->steps = distance; 
}


// Fonction simple pour calculer les pas nécessaires pour se déplacer
void get_step_sizes(t_data *data) 
{
    data->ray->step_x = (float)data->ray->dx / data->ray->steps;
    data->ray->step_y = (float)data->ray->dy / data->ray->steps;
}

void	get_delta_dist(t_data *data)
{
	if (data->ray->dir_y == 0)
		data->ray->dx = 0;
	else if (data->ray->dir_x == 0)
		data->ray->dx = 1;
	else
		data->ray->dx = fabs(1 / data->ray->dir_x);

	if (data->ray->dir_x == 0)
		data->ray->dy = 0;
	else if (data->ray->dir_y == 0)
		data->ray->dy = 1;
	else
		data->ray->dy = fabs(1 / data->ray->dir_y);
}

// TO DO check if it is really x1, casuse x changed
void	get_side_dist(t_data *data)
{
	if (data->ray->dir_x < 0)
	{
		// TO DO ; HERE this is not x1
		data->ray->x1 = -1;
		data->ray->sidedist_x = (data->player->x_pos - data->ray->map_x) * data->ray->dx;
	}
	else
	{
		// TO DO ; HERE this is not x1
		data->ray->x1 = 1;
		data->ray->sidedist_x = (data->ray->map_x - data->player->x_pos + 1.0) * data->ray->dx;
	}
	if (data->ray->dir_y < 0)
	{
		data->ray->y1 = -1;
		data->ray->sidedist_y = (data->player->y_pos - data->ray->map_y) * data->ray->dy;
	}
	else
	{
		data->ray->y1 = 1;
		data->ray->sidedist_y = (data->ray->map_y - data->player->y_pos + 1.0) * data->ray->dy;
	}
}