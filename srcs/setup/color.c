#include "cub3d-bis.h"

t_color *allocate_color(void) 
{
    t_color *color;
	
	
	color = malloc(sizeof(t_color));
    if (color == NULL) {
        perror("Allocation for color failed\n");
        exit(EXIT_FAILURE);
    }
    color->string_color = NULL;
    color->fcolor = NULL;
    color->ccolor = NULL;
    color->final_color = 0;
    color->int_r = 0;
    color->int_g = 0;
    color->int_b = 0;
    color->found_color = 0;
    color->floor = 0;
    color->floor_hexa = 0;
    color->ceiling = 0;
    color->ceiling_hexa = 0;
    return color;
}
