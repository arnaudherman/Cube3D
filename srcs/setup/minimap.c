#include "cub3d-bis.h"

// Allocation d'une structure t_minimap
t_minimap *allocate_minimap() 
{
    t_minimap *minimap;
	
	minimap = malloc(sizeof(t_minimap));
    if (minimap == NULL) {
        perror("Allocation for minimap failed\n");
        exit(EXIT_FAILURE);
    }
    // Initialisation des membres de la structure ici si nécessaire
    minimap->map = NULL;
    minimap->img = NULL; // Attention, t_image doit être alloué séparément si nécessaire
    minimap->size = 0.0;
    minimap->offset_x = 0;
    minimap->offset_y = 0;
    minimap->view_dist = 0;
    minimap->tile_size = 0;
    return minimap;
}