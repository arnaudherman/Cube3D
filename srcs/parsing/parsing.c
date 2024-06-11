#include "cub3d.h"

void	ft_check_file(char *fname, char *name)
{
	int		fd;
	char	*s1;

	s1 = ft_strrchr(fname, '.');
	if (!s1 || ft_strcmp(s1, name) != 0)
		ft_error(ERROR_MAP_EXT);
	fd = open(fname, O_RDONLY);
	if (fd == -1)
		ft_error(ERROR_MAP_OPEN);
	close(fd);
}

int	parsing(char *fname, t_data *data)
{
	ft_check_file(fname, ".cub");
	printf("finish ft_check_file\n");
	len_map(fname, data);
	printf("finish len_map\n");
	found_textures_data(fname, data, &data->mlx);
	printf("finish found_textures_data\n");
	color_data(fname, data);
	printf("finish color_data\n");
	check_map(fname, data);
	printf("finish check_map\n");
	return (0);
}
