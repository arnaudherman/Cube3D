#include "cub3d-bis.h"

void	init_image(t_data *data)
{
		data->image.bits_per_pixel = 0;
		data->image.line_length = 0;
		data->image.endian = 0;
		data->image.relative_path = "./test.xpm";
		data->image.img = NULL;
		data->image.addr = NULL;
		return ;
}
