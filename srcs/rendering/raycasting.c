#include "cub3d-bis.h"

void draw_line(int x1, int y1, int x2, int y2, t_data *data) 
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx, sy, err, e2;
    
    if (x1 < x2) sx = 1; else sx = -1;
    if (y1 < y2) sy = 1; else sy = -1;
    
    err = dx - dy;
    
    while (1) 
    {
        // Dessiner le pixel
        my_mlx_pixel_put(data->map2d, x1, y1, 0xffd55c);
        
        if (x1 == x2 && y1 == y2) break;
        
        e2 = 2 * err;
        if (e2 > -dy) 
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) 
        {
            err += dx;
            y1 += sy;
        }
    }
}

// Fonction pour dessiner une ligne à partir du joueur dans la direction actuelle de son regard
void draw_line_from_player(t_data *data) 
{
    // Coordonnées de départ du joueur
    int x1 = data->player->x_pos;
    int y1 = data->player->y_pos;

    // Longueur de la ligne (vous pouvez ajuster cette valeur selon vos besoins)
    int line_length = get_ray_length(data->player);

    // Calcul des coordonnées de fin de la ligne en utilisant la direction actuelle du joueur
    int x2 = x1 + line_length * cos(data->player->angle * M_PI / 180.0);
    int y2 = y1 + line_length * sin(data->player->angle * M_PI / 180.0);

    // Dessiner la ligne
    draw_line(x1, y1, x2, y2, data);
}

// RESSOURCES : 
// Raycasting : https://lodev.org/cgtutor/raycasting.html
// DDA Algorithm https://lodev.org/cgtutor/raycasting.html
// Video https://www.youtube.com/watch?v=NbSee-XM7WA&t=1s&ab_channel=javidx9
// https://www.youtube.com/watch?v=W5P8GlaEOSI&ab_channel=AbdulBari

void perform_dda(t_data *data) 
{
    int hit = 0;
    while (hit == 0) 
	{
        if (data->ray->sidedist_x < data->ray->sidedist_y) 
		{
            data->ray->sidedist_x += data->ray->dx;
            data->ray->map_x += data->ray->step_x;
            if (data->ray->step_x == -1)
				data->ray->side = 0;
			else
				data->ray->side = 1;
        } 
		else 
		{
            data->ray->sidedist_y += data->ray->dy;
            data->ray->map_y += data->ray->step_y;
			if(data->ray->step_y == -1)
				data->ray->side = 2;
			else
				data->ray->side = 3;
        }

		// Vérification des coordonnées du rayon pour la collision avec le mur
		if (data->map.map2d[(int)data->ray->map_y / TILE_SIZE][(int)data->ray->map_x / TILE_SIZE] != '0')
		{
			hit = 1;
			break;
		}
	}
}

void draw_ray(t_data *data) 
{
    int i;
    int x, y;
    float current_x;
    float current_y;

    get_steps(data);
    if (data->ray->steps == 0)
        return;

    get_step_sizes(data);

    // Utiliser les coordonnées du joueur pour initialiser les rayons
    current_x = data->player->x_pos / TILE_SIZE;
    current_y = data->player->y_pos / TILE_SIZE;

    // Utiliser les coordonnées de début du rayon
    x = data->ray->x1;
    y = data->ray->y1;

    i = 0;
    while (i <= data->ray->steps) 
    {
        data->ray->wall_hit = 0; // Variable pour vérifier si un mur est touché
        while (!data->ray->wall_hit) // Continuer tant qu'aucun mur n'est touché
        {
			printf("tes1t\n");
            // perform_dda(data);
            my_mlx_pixel_put(data->map2d, data->ray->map_x, data->ray->map_y, 0xffd55c);
			draw_line_from_player(data);
            if (data->map.map2d[(int)data->ray->map_y / TILE_SIZE][(int)data->ray->map_x / TILE_SIZE] != '0')
			{
                data->ray->wall_hit = 1;
				// printf("wall cordinates x = %d, y = %d\n", (int)data->ray->map_x / TILE_SIZE, (int)data->ray->map_y / TILE_SIZE);
			}
        }

        // Avancer le rayon d'un pas
        current_x += data->ray->step_x;
        current_y += data->ray->step_y;

        // Mise à jour des coordonnées pour le prochain pas du rayon
        x = (int)current_x;
        y = (int)current_y;
        i++;
    }
}


// Trace des rayons depuis la position du joueur pour déterminer ce qu'il voit. 
// Chaque rayon est tracé selon un certain angle, couvrant ainsi la player fov.
// Le résultat de ce traçage est utilisé pour dessiner la scène 3D.
void shoot_rays(t_data *data) 
{
    double start_angle;
    double angle_increment;
    double angle_rad;
    int i;

    start_angle = data->player->angle - (data->player->fov / 2.0);
    angle_increment = data->player->fov / WINDOW_WIDTH;
    
	i = 0;
    while (i < WINDOW_WIDTH) 
    {
        angle_rad = (start_angle + i * angle_increment) * (M_PI / 180.0);

		// Initialiser les données du rayon
        init_rays(data, i);

        // Calcul des coordonnées de fin du rayon (x2, y2)
        data->ray->x2 = data->player->x_pos + cos(angle_rad) * data->ray->ray_length;
        data->ray->y2 = data->player->y_pos + sin(angle_rad) * data->ray->ray_length;

		// Diviser par TILE_SIZE pour rester dans les limites de la carte
    	data->ray->x2 /= TILE_SIZE;
    	data->ray->y2 /= TILE_SIZE;

        // Contrainte des coordonnées aux dimensions de la carte
        if (data->ray->x2 < 0) 
            data->ray->x2 = 0;
        if (data->ray->x2 >= (MAP_WIDTH * TILE_SIZE)) 
            data->ray->x2 = (MAP_WIDTH * TILE_SIZE) - 1;
        if (data->ray->y2 < 0) 
            data->ray->y2 = 0;
        if (data->ray->y2 >= (MAP_HEIGHT * TILE_SIZE)) 
            data->ray->y2 = (MAP_HEIGHT * TILE_SIZE) - 1;

        // Initialiser les deltas pour le rayon
        data->ray->dx = data->ray->x2 - data->player->x_pos;
        data->ray->dy = data->ray->y2 - data->player->y_pos;

        // Calcul des directions pour le rayon
        data->ray->dir_x = cos(angle_rad);
        data->ray->dir_y = sin(angle_rad);
        draw_ray(data);
        i++;
    }
}

int raycasting(t_data *data) {
    shoot_rays(data);
    return 0;
}

