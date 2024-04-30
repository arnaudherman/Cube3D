#include "cub3d-bis.h"

int init_image(t_data *data)
{
    // Création d'une nouvelle image avec les dimensions de la fenêtre
    data->image.img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
    if (data->image.img == NULL) {
        perror("Failed to create image\n");
        return 1;
    }
    
    // Récupération de l'adresse de la mémoire de l'image et des informations sur l'image
    data->image.addr = mlx_get_data_addr(data->image.img, &(data->image.bits_per_pixel),
                                         &(data->image.line_length), &(data->image.endian));
    if (data->image.addr == NULL) {
        perror("Failed to get image data address\n");
        mlx_destroy_image(data->mlx_ptr, data->image.img);
        return 1;
    }
    data->image.relative_path = NULL;
    return 0;
}


// Allocation d'une structure t_image
t_image *allocate_image() 
{
    t_image *image;
	
	image = malloc(sizeof(t_image));
    if (image == NULL) {
        perror("Allocation for image failed\n");
        exit(EXIT_FAILURE);
    }
}
