#include "cub3d.h"

//check si le fichier map est en cub 
//et que le fichier peut etre open et renvoie le fd
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

//main du parsing
int	parsing(char *fname, t_data *data)
{
	// TO DO : HANDLE FT_CHECK_FILE
	// printf("start parsing\n");
	ft_check_file(fname, ".cub");
	printf("finish ft_check_file\n");

	// TO DO : HANDLE MAP OPEN
	len_map(fname, data);
	printf("finish len_map\n");

	// TO DO : HANDLE MAP OPEN in found textures data
	found_textures_data(fname, data, &data->mlx);
	printf("finish found_textures_data\n");

	color_data(fname, data);
	printf("finish color_data\n");

	check_map(fname, data);
	printf("finish check_map\n");

	return (0);
}