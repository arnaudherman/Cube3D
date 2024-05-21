#include "cub3d-bis.h"

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