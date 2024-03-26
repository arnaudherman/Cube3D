
#include "../../include/cub3d.h"

//check si le fichier map est en cub 
//et que le fichier peut etre open et renvoie le fd
void	ft_check_file(char *fname, char *name)
{
	int		fd;
	char	*s1;

	s1 = ft_strrchr(fname, '.');
	if (s1 && !ft_strcmp(s1, name))
		ft_error(ERROR_MAP_EXT);
	else if (!fname || !s1)
		ft_error(ERROR_MAP_OPEN);
	fd = open(fname, O_RDONLY);
	if (fd == -1)
		ft_error(ERROR_MAP_OPEN);
	close(fd);
}

//main du parsing
int	parsing(char *argv[], t_data *data)
{
	printf("start parsing\n");
	ft_check_file(argv[1], "cub");
	printf("finish ft_check_file\n");
	len_map(argv[1], data);
	printf("finish len_map\n");
	found_textures_data(argv[1], data);
	printf("finish found_textures_data\n");
	color_data(argv[1], data);
	printf("finish color_data\n");
	check_map(argv[1], data);
	printf("finish check_map\n");

	return (0);
}
