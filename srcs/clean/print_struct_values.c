#include "cub3d.h"

void print_ray_info(t_ray *ray) 
{
    printf("Ray Info:\n");
    printf("x: %d\n", ray->x);
    printf("y: %d\n", ray->y);
    printf("x_map: %d\n", ray->x_map);
    printf("y_map: %d\n", ray->y_map);
    printf("x_step: %d\n", ray->x_step);
    printf("y_step: %d\n", ray->y_step);
    printf("hit: %d\n", ray->hit);
    printf("side: %d\n", ray->side);
    printf("line_height: %d\n", ray->line_height);
    printf("draw_start: %d\n", ray->draw_start);
    printf("draw_end: %d\n", ray->draw_end);
    printf("x_text: %d\n", ray->x_text);
    printf("y_text: %d\n", ray->y_text);
    printf("wall_x: %f\n", ray->wall_x);
    printf("z_index: %p\n", (void*)ray->z_index);
    printf("camera_x: %f\n", ray->camera_x);
    printf("wall_dist: %f\n", ray->wall_dist);
    printf("dir_x: %f\n", ray->dir_x);
    printf("dir_y: %f\n", ray->dir_y);
    printf("sx: %f\n", ray->sx);
    printf("sy: %f\n", ray->sy);
    printf("dx: %f\n", ray->dx);
    printf("dy: %f\n", ray->dy);
}

void print_ray_texture_info(t_data *data, t_ray *ray, t_image *texture)
{
    // Print the values of ray's coordinates
    printf("Ray Coordinates: x = %d, y = %d\n", ray->x, ray->y);

    // Print the values of texture coordinates
    printf("Texture Coordinates: x_text = %d, y_text = %d\n", ray->x_text, ray->y_text); //

    // Print the values of data->image's properties
    printf("Data Image Line Length: %d\n", data->image->line_length);
    printf("Data Image Bits Per Pixel: %d\n", data->image->bits_per_pixel);

    // Print the values of texture's properties
    printf("Texture Line Length: %d\n", texture->line_length);
    printf("Texture Bits Per Pixel: %d\n", texture->bits_per_pixel);

    // Print the final calculated indices
    int data_index = ray->y * data->image->line_length + ray->x * data->image->bits_per_pixel / 8;
    int texture_index = ray->y_text * texture->line_length + ray->x_text * (texture->bits_per_pixel / 8);

    printf("Data Index: %d\n", data_index);
    printf("Texture Index: %d\n", texture_index); 
}

void print_image_info(t_image *image) 
{
    if (image == NULL) 
    {
        printf("Image structure is NULL\n");
        return;
    }
    printf("Image Info:\n");
    printf("  Width: %d\n", image->width);
    printf("  Height: %d\n", image->height);
    printf("  Bits per pixel: %d\n", image->bits_per_pixel);
    printf("  Line length: %d\n", image->line_length);
    printf("  Endian: %d\n", image->endian);
    printf("  Img pointer: %p\n", image->img);
    printf("  DATA Addr: %p\n", image->addr);
    // printf("  Data: %s\n", image->data ? image->data : "NULL");
    printf("  Road: %s\n", image->road ? image->road : "NULL");
    printf("  Texture found: %d\n", image->texture_found);
}
