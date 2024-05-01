#include "cub3d-bis.h"

	// int rows = sizeof(data->map.map2d)/sizeof(data->map.map2d[0]);
	// int columns = sizeof(data->map.map2d[0])/sizeof(data->map.map2d[0][0]);
	// printf("rows: %d\n", rows);
	// printf("columns: %d\n", columns);

// TO DO free all allocated structs when not needed anymroe
int	main(int ac, char **av) 
{
	t_data	data;
	// sleep(10);

	// CHECK
	// if (ac != 2)
	// 	perror("There must be precisely 2 arguments\n");

	// INIT
	if (init_default_all(&data) != 0) {
        perror("Failed to init_default_all in main\n");
        return -1;
    }
	printf("A) After init_default_all data->player.x_pos is : %d\n",  data.player->x_pos);
	// 73896

	// TO DO : MALLOC ?
	// // malloc_all(&data);
	// // printf("After malloc_all data->player.x_pos is : %d\n",  data.player.x_pos);

	init_custom_all(&data);
	printf("3) data->player.x_pos is : %d\n",  data.player->x_pos);
	// 73896

	// mlx_put_image_to_window(data.mlx.mlx_ptr, data.mlx.mlx_win_ptr, data.image.img, 0, 0);
	
	mlx_loop_hook(data.mlx.mlx_ptr, render_next_frame, &data);
	// printf("Face to face mlx_loop_hook line_length = %d, bits_per_pixel = %d\n", data.image->line_length, data.image->bits_per_pixel);
	// HERE :line_length = 7680, bits_per_pixel = 32

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
	free_all(&data);

	return (0);
}

