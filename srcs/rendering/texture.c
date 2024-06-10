#include "cub3d.h"

// TO DO : handle dans mon .cub
// F 220,100,0 for floor
// C 225,30,0 = ceiling

// void render_texture_column(t_image *world, int x, int wall_height, int wall_top, t_image *texture_img) {
    
// 	// TO DO Calcul de tex_x : Dans render_texture_column, 
// 	// tex_x doit être calculé ou passé en paramètre, selon votre logique de raycasting.
// 	int tex_x, tex_y;
//     float tex_step;
// 	float tex_pos;
// 	int y;
// 	int color;
	
// 	tex_step = (float)texture_img->height / wall_height;
// 	tex_x = 0;
//     tex_pos = 0;
// 	y = wall_top;

//     while (y < wall_top + wall_height) {
//         if (y >= 0 && y < mlx_HEIGHT) {
//             tex_y = (int)tex_pos & (texture_img->height - 1);
//             tex_pos += tex_step;
// 			// TO DO WTF HERE ??? 
// 			color = *(int *)(texture_img->addr + (tex_y * texture_img->line_length + tex_x * (texture_img->bits_per_pixel / 8)));
//             my_mlx_pixel_put(world, x, y, color);
//         }
// 		y++;
//     }
// }

// void render_wall_texture(t_image *world, int x, int wall_height, int wall_top, t_texture *texture, char wall_dir) {
// 	t_image *texture_img;

// 	if (wall_dir == 'N')
// 		texture_img = &texture->NO;
// 	else if (wall_dir == 'S')
// 		texture_img = &texture->SO;
// 	else if (wall_dir == 'E')
// 		texture_img = &texture->EA;
// 	else if (wall_dir == 'W')
// 		texture_img = &texture->WE;
// 	else {
// 		perror("Error: Invalid wall direction. Looking for north/south/east/west\n");
// 		exit(1);
// 	}

// 	render_texture_column(world, x, wall_height, wall_top, texture_img);
// }

void		pixel_put(t_image *image, int x, int y, int color)
{
	unsigned char *src;
	unsigned char r;
	unsigned char g;
	unsigned char b;

	src = (unsigned char *)&color;
	r = src[0];
	g = src[1];
	b = src[2];
	image->addr[y * image->line_length + x * image->bits_per_pixel / 8] = r;
	image->addr[y * image->line_length + x * image->bits_per_pixel / 8 + 1] = g;
	image->addr[y * image->line_length + x * image->bits_per_pixel / 8 + 2] = b;
}

void		set_color_on_image(t_data *data, t_ray *ray)
{
	int	y;

	y = 0;
	while (y < ray->draw_start)
		pixel_put(data->image, ray->x, y++, data->c_color);
	y = ray->draw_end + 1;
	while (y < data->mlx.win_height)
		pixel_put(data->image, ray->x, y++, data->f_color);
}

// First values coming in texture_put()
// Ray Coordinates: x = 0, y = 460
// Texture Coordinates: x_text = -1, y_text = 0
// Data Image Line Length: 0
// Data Image Bits Per Pixel: 0
// Texture Line Length: 0
// Texture Bits Per Pixel: 0
// Data Index: 0
// Texture Index: 0

// Image texture data edit here
void	texture_put(t_data *data, t_image *texture, t_ray *ray)
{
	int	d;

	// DEBUG CHECK CONDITION
	if (data->image->line_length == 0 || data->image->bits_per_pixel == 0) {
		write(2, "Erreur: In texture_put() function, data->image->line_length or bpp = 0.\n", 45);
		exit(1);
	}

	d = ray->y * texture->line_length - data->mlx.win_height
		* texture->line_length / 2 + ray->line_height * texture->line_length / 2;
	ray->y_text = ((d * texture->height) / ray->line_height)
		/ texture->line_length;

	// TO DO : DEBUG HERE data->image->addr
	// WRONG VALUES, images bad init???
	printf("          RAY TEXTURE INFO chorizooooooooooooooooooooooooo\n");
	// TO DO : DEBUG HERE values below = 0
	// printf("Texture Line Length: %d\n", texture->line_length);
    // printf("Texture Bits Per Pixel: %d\n", texture->bits_per_pixel);
	print_ray_texture_info(data, ray, texture); // DEBUG RAY TEXTURE

	data->image->addr[ray->y * data->image->line_length
		+ ray->x * data->image->bits_per_pixel / 8] =
		texture->addr[ray->y_text * texture->line_length
		+ ray->x_text * (texture->bits_per_pixel / 8)];

	data->image->addr[ray->y * data->image->line_length
		+ ray->x * data->image->bits_per_pixel / 8 + 1] =
		texture->addr[ray->y_text * texture->line_length
		+ ray->x_text * (texture->bits_per_pixel / 8) + 1];

	data->image->addr[ray->y * data->image->line_length
		+ ray->x * data->image->bits_per_pixel / 8 + 2] =
		texture->addr[ray->y_text * texture->line_length
		+ ray->x_text * (texture->bits_per_pixel / 8) + 2];

	ray->y++;
}

void		set_texture_on_image(t_data *data, t_image *texture, t_ray *ray)
{
	ray->y = ray->draw_start;
	printf("          RAY INFO : separationaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n");
	print_ray_info(ray); // DEBUG RAY STRUCT

	printf("          TEXTURE IMAGE INFO separationxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
	print_image_info(texture); // DEBUG IMAGE STRUCT

	// Here values sent are :
	// ray->y = 460
	// ray->draw_start = 460
	// ray->draw_end = 620
	while (ray->y <= ray->draw_end)
		texture_put(data, texture, ray);
}
