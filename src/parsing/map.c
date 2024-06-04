
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

void afficherAvecEspaces(const char *chaine) {
	printf("La chaîne de destination est : ");
	for (int i = 0; chaine[i] != '\0'; i++) {
		if (chaine[i] == '\t') {
			printf("\\t"); // Afficher une tabulation sous forme d'échappement
		} else if (chaine[i] == ' ') {
			printf("_"); // Remplacer les espaces par un caractère de soulignement pour la visibilité
		} else if (chaine[i] == '\n') {
			printf("b"); // Remplacer les espaces par un caractère de soulignement pour la visibilité
		} else {
			printf("%c", chaine[i]); // Afficher les autres caractères normalement
		}
	}
	printf("\n");
}

void remove_newline(char **array)
{
	if (array == NULL || *array == NULL)
	{
		return;
	}
	char **ptr = array;

	while (*ptr != NULL) {
		size_t len = strlen(*ptr);

		if (len > 0 && (*ptr)[len - 1] == '\n')
		{
						(*ptr)[len - 1] = '\0';
		}
		ptr++;
	}
}

void tab_to_space(char* string)
{
	char* p = string;
	size_t len = strlen(string);
	char* new_string = malloc((len * 3) + 1);

	if (new_string == NULL) {
		ft_error(ERROR_MALLOC);
		return;
	}

	char* q = new_string;

	while (*p != '\0')
	{
		if (*p == '\t')
		{
			*(q++) = ' ';
			*(q++) = ' ';
			*(q++) = ' ';
			*(q++) = ' ';
			p++;
		}
		else
		{
			*(q++) = *(p++);
		}
	}
	*q = '\0';
	strcpy(string, new_string);
	free(new_string);
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
	while(string[i] == ' ')
	{
		i++;
	}
	if (string[i] != '1')
	{
		ft_error(ERROR_MAP_NOT_ONE_START);
	}
	if(string[len - 1] == '\n')
		len -= 1;
	if(string[len - 1] != '\n')
		len -= 1;
	while(string[len] == ' ')
	{
		len--;
	}
	if (string[len] != '1')
	{
		printf("string len a -2 lol:%d\n", string[len]);
		ft_error(ERROR_MAP_NOT_ONE_END);
	}
}

void complet_string_with_space(char **string, int len) {
	int max_len = 0;
	int i = 0;

	while (string[i] != NULL) {
		int string_len = strlen(string[i]);
		if (string_len > max_len)
			max_len = string_len;
		i++;
	}

	if (len > max_len)
		max_len = len;

	i = 0;
	while (string[i] != NULL) {
		int string_len = strlen(string[i]);
		if (string_len < max_len) {
			string[i] = realloc(string[i], max_len + 1);
			if (string[i] == NULL) {
				ft_error(ERROR_MALLOC);
				return;
			}
			for (int j = string_len; j < max_len; j++) {
				string[i][j] = ' ';
			}
			string[i][max_len] = '\0';
		}
		i++;
	}
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

void	check_zero(char *string_up, char *string_down)
{
	int i;

	i = 0;
	while (string_up[i] && string_down[i])
	{
		if (on_map(string_down[i]) == 1)
		{
			if (string_up[i] != '1' && string_up[i] != '0' && string_up[i] != 'N'
				&& string_up[i] != 'S' && string_up[i] != 'W' && string_up[i] != 'E')
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

	i = 0;
	fd_cub = open(fname, O_RDONLY);
	if (fd_cub < 0)
	{
		ft_error("Error opening file");
		return;
	}
	data->map = malloc(sizeof(char*) * (data->map_y + 1));
	if (!data->map)
	{
		ft_error("Memory allocation failed");
		close(fd_cub);
		return;
	}
	line = ignore_texture(fd_cub);
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
	i = 0;
	while (i < data->map_y && data->map[i])
	{
		tab_to_space(data->map[i]);
		map_x_new = ft_strlen(data->map[i]);
		if (map_x_new > data->map_x)
			data->map_x = map_x_new - 1;
		i++;
	}
	i = 0;
	print_string_array(data->map);
	remove_newline(data->map);
	print_string_array(data->map);
	complet_string_with_space(data->map, data->map_x);
	while(i < data->map_y)
	{
		printf("check_map string send to check start end:%s\n", data->map[i]);
		afficherAvecEspaces(data->map[i]);
		check_start_end(data->map[i]);
		i++;
	}
	only_space_or_one(data->map[0]);
	only_space_or_one(data->map[data->map_y - 1]);
	check_upper(data->map[0], data->map[1]);
	i = 1;
	while(i < data->map_y - 1)
	{
		check_down(data->map[i], data->map[i + 1]);
		i++;
	}
	i = 1;
	while(i < data->map_y - 1)
	{
		check_zero(data->map[i], data->map[i + 1]);
		i++;
	}
	close(fd_cub);
	i = 0;
	while(data->map[i])
	{
		afficherAvecEspaces(data->map[i]);
		i++;
	}
	printf("map_x:%d\n", data->map_x);
	printf("map_y:%d\n", data->map_y);
}
