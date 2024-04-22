#include "cub3d-bis.h"

// L'offset mémoire pour un pixel à une certaine position (x, y) dans l'image
// y * line_length : cela détermine la position verticale dans l'image en prenant en compte la longueur de la ligne.
// x * (bits_per_pixel / 8) : cela détermine la position horizontale en prenant en compte le nombre de bits par pixel et le divisant par 8 pour obtenir le nombre d'octets.
// int offset = (y * line_length + x * (bits_per_pixel / 8));
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->image.addr + (y * data->image.line_length + x * (data->image.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

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

