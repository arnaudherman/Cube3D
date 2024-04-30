#include "cub3d-bis.h"

	// int rows = sizeof(data->map.map2d)/sizeof(data->map.map2d[0]);
	// int columns = sizeof(data->map.map2d[0])/sizeof(data->map.map2d[0][0]);
	// printf("rows: %d\n", rows);
	// printf("columns: %d\n", columns);

// TO DO free all allocated structs when not needed anymroe
int	main(int ac, char **av) 
{
	t_data	data;

	// CHECK
	// if (ac != 2)
	// 	perror("There must be precisely 2 arguments\n");

	printf("1) data->player.x_pos is : %d\n",  data.player.x_pos);

	// INIT
	init_default_all(&data);
	printf("2) After init_default_all data->player.x_pos is : %d\n",  data.player.x_pos);

	// TO DO : MALLOC ?
	// // malloc_all(&data);
	// // printf("After malloc_all data->player.x_pos is : %d\n",  data.player.x_pos);

	init_custom_all(&data);
	printf("3) After init_custom_all data->player.x_pos is : %d\n",  data.player.x_pos);

	mlx_put_image_to_window(data.mlx.mlx_ptr, data.mlx.mlx_win_ptr, data.image.img, 0, 0);
	mlx_loop_hook(data.mlx.mlx_ptr, render_next_frame, &data);

	// TEST
	// printf("Image pointer: %p\n", data.image);
    // printf("Map pointer: %p\n", data.map);
    // printf("Player pointer: %p\n", data.player);
    // printf("Ray pointer: %p\n", data.ray);
    // printf("Texture pointer: %p\n", data.texture);
    // printf("Color pointer: %p\n", data.color);

	// PARSE ARGS	TO DO : ???) 

	// RENDER
	// create function render_next_frame function to render images
	// int	render_next_frame(void *YourStruct);
	// mlx_loop_hook(data.mlx_ptr, render_next_frame, &data);

	// LISTENER
	// event_listener(&data);

	// LOOP
	mlx_loop(data.mlx.mlx_ptr);
	
	// CLEAN
	// clean_all(&data);

	return (0);
}

