#include "cub3d.h"

// mlx_xpm_to_image
// void	*mlx_xpm_to_image(void *mlx_ptr, char **xpm_data, int *width, int *height);

// static int	*xpm_to_img(t_data *data, char *path)
// {
// 	t_img	tmp;
// 	int		*buffer;
// 	int		x;
// 	int		y;

// 	init_texture_img(data, &tmp, path);
// 	buffer = ft_calloc(1,
// 			sizeof * buffer * data->texinfo.size * data->texinfo.size);
// 	if (!buffer)
// 		clean_exit(data, err_msg(NULL, ERR_MALLOC, 1));
// 	y = 0;
// 	while (y < data->texinfo.size)
// 	{
// 		x = 0;
// 		while (x < data->texinfo.size)
// 		{
// 			buffer[y * data->texinfo.size + x]
// 				= tmp.addr[y * data->texinfo.size + x];
// 			++x;
// 		}
// 		y++;
// 	}
// 	mlx_destroy_image(data->mlx, tmp.img);
// 	return (buffer);
// }

// Converts an xpm file to a new image instance.
// void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);

// int	render_image(t_data *data)
// {
	
// 	return 0;
// }