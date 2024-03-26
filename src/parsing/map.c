
#include "../../include/cub3d.h"


void print_string_array(char **array) {
	if (array == NULL) {
		printf("NULL\n");
		return;
	}

	// Parcourir chaque élément du tableau
	for (int i = 0; array[i] != NULL; i++) {
		printf("%s\n", array[i]);  // Imprimer chaque chaîne de caractères
	}
}

void tab_to_space(char* string)
{
	char* p = string;
	while (*p != '\0')
	{
		if (*p == '\t')
		{
			char* q = string + strlen(string);
			while (q > p)
			{
				*(q + 3) = *q;
				q--;
			}
			*p++ = ' ';
			*p++ = ' ';
			*p++ = ' ';
			*p = ' ';
		}
		p++;
	}
}

void only_space_or_one(char *string)
{
	int i;

	i = 0;
	while (string[i + 1] != '\0')
	{
		if (string[i] != ' ' && string[i] != '1')
			ft_error(ERROR_MAP_ONLY_SPACE_ONE);
		i++;
	}
}

void	check_start_end(char *string)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(string);
	printf("check_start_end string to check:%s", string);
	while(string[i] == ' ')
	{
		i++;
		printf("check_start_end In while\n");
	}
	if (string[i] != '1')
	{
		printf("check_start_end first if\n");
		ft_error(ERROR_MAP_NOT_ONE_START);
	}
	printf("string à len:%c\n", string[len - 2]);
	if(string[len - 1] == '\n')
		len -= 2;
	if(string[len - 1] != '\n')
		len -= 1;
	while(string[len] == ' ')
	{
		len--;
		printf("check_start_end In while 2\n");
	}
	if (string[len] != '1')
	{
		printf("kakoukakou");
		printf("check_start_end second if\n");
		ft_error(ERROR_MAP_NOT_ONE_END);
	}
}


void complet_string_with_space(char **string, int len)
{
	int string_len;
	char *return_string;
	int i;

	printf("complet_string_with_space start string: %s\n", *string);
	string_len = strlen(*string);
	if (string_len < len)
	{
		printf("complet_string_with_space in if: %s\n", *string);
		return_string = malloc(len + 1);
		if (return_string == NULL)
			ft_error(ERROR_MALLOC);
		strcpy(return_string, *string);
		i = string_len;
		while (i < len)
		{
			return_string[i] = ' ';
			i++;
		}
		return_string[len] = '\0';
		free(*string);
		*string = return_string;
	}
	printf("complet_string_with_space end: %s\n", *string);
}


int on_map(char car)
{
	if (car == 'N' || car == 'S' || car == 'E' || car == 'W' || car == '0')
		return 1;
	else
		return 0;
}

void	check_upper(char *string_up, char *string_down)
{
	int i;

	i = 0;
	while (string_up[i] && string_down[i])
	{
		if (on_map(string_down[i]) == 1)
		{
			if (string_up[i] != '1')
				ft_error(ERROR_MAP_CHECK_UPER);
		}
		i++;
	}
}

void	check_down(char *string_up, char *string_down)
{
	int i;

	i = 0;
	while (string_up[i] && string_down[i])
	{
		if (on_map(string_up[i]) == 1)
		{
			if (string_down[i] != '1' && string_down[i] != '0' && string_down[i] != 'N'
				&& string_down[i] != 'S' && string_down[i] != 'W' && string_down[i] != 'E')
				ft_error(ERROR_MAP_CHECK_DOWN);
		}
		i++;
	}
}

void check_map(char *fname, t_data *data)
{
	int fd_cub;
	char *line;
	int i;
	int map_x_new;

	printf("check_map start\n");
	i = 0;
	fd_cub = open(fname, O_RDONLY);
	if (fd_cub < 0)
	{
		ft_error("Error opening file");
		return;
	}
	data->map = malloc(sizeof(char*) * data->map_y);
	if (!data->map)
	{
		ft_error("Memory allocation failed");
		close(fd_cub);
		return;
	}
	line = ignore_texture(fd_cub);
	printf("check_map ignore_texture after\n");
	while (line && i < data->map_y)
	{
		data->map[i] = malloc(strlen(line) + 1);
		if (!data->map[i])
		{
			ft_error("Memory allocation failed");
			close(fd_cub);
			return;
		}
		strcpy(data->map[i], line);
		i++;
		if (i < data->map_y)
			line = get_next_line(fd_cub);
	}
	printf("check_map while 1 after\n");
	i = 0;
	while(data->map[i])
	{
		printf("check_map while 2 in start string check:%s\n", data->map[i]);
		tab_to_space(data->map[i]);
		map_x_new = ft_strlen(data->map[i]);
		if (map_x_new > data->map_x)
			data->map_x = map_x_new;
		printf("check_map while 2 in before i++ string check:%s\n", data->map[i]);
		printf("check_map while 2 in before i++ map_y check:%d\n", data->map_y);
			i++;
		printf("check_map while 2 in end string check:%s\n", data->map[i]);
	}
	i = 0;
	printf("check_map while 2 after\n");
	print_string_array(data->map);
	while(i < data->map_y)
	{
		printf("check_map in while 3 data->map[i]:%s\n", data->map[i]);
		complet_string_with_space(&data->map[i], data->map_x);
		printf("check_map in while 3 after complet data->map[i]:%s\n", data->map[i]);
		check_start_end(data->map[i]);
		printf("check_map end while 3 i:%d map->y:%d\n", i, data->map_y);
		i++;
	}
	printf("check_map while 3 after\n");
	only_space_or_one(data->map[0]);
	printf("check_map betwen only space\n");
	only_space_or_one(data->map[data->map_y - 1]);
	printf("check_map after seconde only space\n");
	check_upper(data->map[0], data->map[1]);
	i = 1;
	while(i < data->map_y - 1)
	{
		check_down(data->map[i], data->map[i + 1]);
		i++;
	}
	printf("check_map while 4 after\n");
	close(fd_cub);
}
