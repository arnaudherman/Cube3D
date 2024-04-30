#include "cub3d-bis.h"

t_image	*malloc_t_image(void)
{
	t_image *image;

	if (!(image = (t_image *)malloc(sizeof(t_image))))
		return (NULL);
	image->img = NULL;
	image->addr = NULL;
	image->bits_per_pixel = 0;
	image->line_length = 0;
	image->endian = 0;
	image->relative_path = NULL;
	return (image);
}

int init_image(t_data *data)
{
    // Création d'une nouvelle image avec les dimensions de la fenêtre
    data->image->img = mlx_new_image(data->mlx.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
    if (data->image->img == NULL) {
        perror("Failed to create image\n");
        return 1;
    }
    
    // Récupération de l'adresse de la mémoire de l'image et des informations sur l'image
    data->image->addr = mlx_get_data_addr(data->image->img, &(data->image->bits_per_pixel),
                                         &(data->image->line_length), &(data->image->endian));
    if (data->image->addr == NULL) {
        perror("Failed to get image data address\n");
        mlx_destroy_image(data->mlx.mlx_ptr, data->image->img);
        return 1;
    }
    data->image->relative_path = NULL;
    return 0;
}

// // Allocation d'une structure t_image
// t_image *allocate_image() 
// {
//     t_image *image;
	
// 	image = malloc(sizeof(t_image));
//     if (image == NULL) {
//         perror("Allocation for image failed\n");
//         exit(EXIT_FAILURE);
//     }
// }
