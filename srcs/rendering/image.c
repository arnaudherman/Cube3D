#include "cub3d-bis.h"

void my_mlx_pixel_put(t_image *image, int x, int y, int color) {
	// printf("xaq mlx_loop_hook line_length = %d, bits_per_pixel = %d\n", image->line_length, image->bits_per_pixel);
	// HERE : line_length = 0, bits_per_pixel = 0
    char *dst;
    dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
	// Debug: x = 0, y = 0, line_length = 24672, bits_per_pixel = 5600
	// Debug: Calculated address: 0x3e8
	// printf("Debug: x = %d, y = %d, line_length = %d, bits_per_pixel = %d\n", x, y, image->line_length, image->bits_per_pixel);
    // printf("Debug: Calculated address: %p\n", (void*)dst); 
	// Debug: x = 58, y = 57, line_length = 0, bits_per_pixel = 0 (et y boucle avec + 1 par iteration)
	// Debug: Calculated address: 0x60700001feb0
    *(unsigned int*)dst = color;
}

// update pixel color
void pixel_put(t_image *image, int x, int y, int color) 
{
    unsigned char *src;
	
	src = (unsigned char *)&color;
    image->addr[y * image->line_length + x * image->bits_per_pixel / 8] = src[0];
    image->addr[y * image->line_length + x * image->bits_per_pixel / 8 + 1] = src[1];
    image->addr[y * image->line_length + x * image->bits_per_pixel / 8 + 2] = src[2];
}

// To do : check not sure = Colorie les portions supérieures et inférieures de la colonne 
// avec les couleurs de plafond et de sol.
void set_color_on_image(t_data *data, t_ray *ray) 
{
    int y;
	
	y = 0;
    while (y < ray->draw_start) {
        pixel_put(data->world, ray->x1, y++, data->color->ceiling);
    }
    y = ray->draw_end + 1;
    while (y < data->mlx.win_height) {
        pixel_put(data->world, ray->x1, y++, data->color->floor);
    }
}

// Update image pixels with texture data
void texture_put(t_data *data, t_image *texture, t_ray *ray) 
{
    int d;
	
	d = ray->y1 * texture->line_length - data->mlx.win_height
            * texture->line_length / 2 + ray->line_height * texture->line_length / 2;
    ray->text_y = ((d * texture->height) / ray->line_height) / texture->line_length;
    data->world->addr[ray->y1 * data->world->line_length
                      + ray->x1 * data->world->bits_per_pixel / 8] =
        texture->addr[ray->text_y * texture->line_length
                      + ray->text_x * (texture->bits_per_pixel / 8)];
    data->world->addr[ray->y1 * data->world->line_length
                      + ray->x1 * data->world->bits_per_pixel / 8 + 1] =
        texture->addr[ray->text_y * texture->line_length
                      + ray->text_x * (texture->bits_per_pixel / 8) + 1];
    data->world->addr[ray->y1 * data->world->line_length
                      + ray->x1 * data->world->bits_per_pixel / 8 + 2] =
        texture->addr[ray->text_y * texture->line_length
                      + ray->text_x * (texture->bits_per_pixel / 8) + 2];
    ray->y1++;
}

// Apply texture along column
void set_texture_on_image(t_data *data, t_image *texture, t_ray *ray) 
{
    ray->y1 = ray->draw_start;
    while (ray->y1 <= ray->draw_end) {
        texture_put(data, texture, ray);
    }
}