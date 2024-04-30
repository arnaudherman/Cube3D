#include "cub3d-bis.h"

// Allocation d'une structure t_color
t_color *allocate_color() 
{
    t_color *color;
	
	
	color = malloc(sizeof(t_color));
    if (color == NULL) {
        perror("Allocation for color failed\n");
        exit(EXIT_FAILURE);
    }
    // Initialisation des membres de la structure ici si nécessaire
    color->string_color = NULL;
    color->fcolor = NULL;
    color->ccolor = NULL;
    color->final_color = 0;
    color->r = 0;
    color->g = 0;
    color->b = 0;
    color->found = 0;
    color->floor = 0;
    color->floor_hexa = 0;
    color->ceiling = 0;
    color->ceiling_hexa = 0;
    return color;
}