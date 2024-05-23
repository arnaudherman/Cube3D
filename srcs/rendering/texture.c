#include "cub3d-bis.h"

// To draw my column
// void calculate_draw_positions(t_mlx *mlx, t_ray *ray) 
// {
//     ray->draw_start = -ray->line_height / 2 + mlx->win_height / 2;
//     ray->draw_end = ray->line_height / 2 + mlx->win_height / 2;
//     if (ray->draw_start < 0) ray->draw_start = 0;
//     if (ray->draw_end >= mlx->win_height) ray->draw_end = mlx->win_height - 1;
// }

// // wall position when hit
// void calculate_wall_x(t_data *data, t_ray *ray) 
// {
//     if (ray->side == 0 || ray->side == 1)
//         ray->wall_x = data->player->y_pos + ray->wall_dist * ray->dir_y;
//     else
//         ray->wall_x = data->player->x_pos + ray-> wall_dist * ray->dir_x;
//     ray->wall_x -= floor(ray->wall_x);
// }

// // choose right texture
// t_image *select_texture(t_data *data, t_ray *ray) 
// {
//     if (ray->side == 0 && ray->dir_x < 0)
//         return &data->WE;
//     else if (ray->side == 1 && ray->dir_x >= 0)
//         return &data->EA;
//     else if (ray->side == 2 && ray->dir_y > 0)
//         return &data->SO;
//     else
//         return &data->NO;
// }

// // calculate x position on texture to use for rendering
// void calculate_texture_x(t_ray *ray, t_image *texture) 
// {
//     ray->text_x = (int)(ray->wall_x * (double)texture->width);
//     if ((ray->side == 0 && ray->dir_x > 0) || (ray->side == 1 && ray->dir_y < 0))
//         ray->text_x = texture->width - ray->text_x - 1;
// }

// void set_wall_texture(t_data *data, t_ray *ray) 
// {
//     t_image *texture;
	
// 	texture = select_texture(data, ray);
//     calculate_texture_x(ray, texture);
//     set_texture_on_image(data, texture, ray);
// }

// // Draw column with the rigth texture
// void draw_col(t_data *data, t_mlx *mlx, t_ray *ray) {
//     calculate_draw_positions(mlx, ray);
//     calculate_wall_x(data, ray);
//     set_color_on_image(data, ray);
//     set_wall_texture(data, ray);
// }

// // TO DO : handle dans mon .cub
// // F 220,100,0 for floor
// // C 225,30,0 = ceiling

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
//         if (y >= 0 && y < WINDOW_HEIGHT) {
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

// ************************* Use Github below *************************

// void		pixel_put(t_image *image, int x, int y, int color)
// {
// 	unsigned char *src;
// 	unsigned char r;
// 	unsigned char g;
// 	unsigned char b;

// 	src = (unsigned char *)&color;
// 	r = src[0];
// 	g = src[1];
// 	b = src[2];
// 	image->img_data[y * image->size_line + x * image->bpp / 8] = r;
// 	image->img_data[y * image->size_line + x * image->bpp / 8 + 1] = g;
// 	image->img_data[y * image->size_line + x * image->bpp / 8 + 2] = b;
// }

// void		set_color_on_image(t_data *data, t_ray *ray)
// {
// 	int	y;

// 	y = 0;
// 	while (y < ray->draw_start)
// 		pixel_put(data->image, ray->x, y++, data->c_color);
// 	y = ray->draw_end + 1;
// 	while (y < data->window->height)
// 		pixel_put(data->image, ray->x, y++, data->f_color);
// }

// void	texture_put(t_data *data, t_image *texture, t_ray *ray)
// {
// 	int	d;

// 	d = ray->y * texture->size_line - data->window->height
// 		* texture->size_line / 2 + ray->line_height * texture->size_line / 2;
// 	ray->text_y = ((d * texture->height) / ray->line_height)
// 		/ texture->size_line;
// 	data->image->img_data[ray->y * data->image->size_line
// 		+ ray->x * data->image->bpp / 8] =
// 		texture->img_data[ray->text_y * texture->size_line
// 		+ ray->text_x * (texture->bpp / 8)];
// 	data->image->img_data[ray->y * data->image->size_line
// 		+ ray->x * data->image->bpp / 8 + 1] =
// 		texture->img_data[ray->text_y * texture->size_line
// 		+ ray->text_x * (texture->bpp / 8) + 1];
// 	data->image->img_data[ray->y * data->image->size_line
// 		+ ray->x * data->image->bpp / 8 + 2] =
// 		texture->img_data[ray->text_y * texture->size_line
// 		+ ray->text_x * (texture->bpp / 8) + 2];
// 	ray->y++;
// }

// void		set_texture_on_image(t_data *data, t_image *texture, t_ray *ray)
// {
// 	ray->y = ray->draw_start;
// 	while (ray->y <= ray->draw_end)
// 		texture_put(data, texture, ray);
// }