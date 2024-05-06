#include "cub3d-bis.h"

int	go_up(t_data *data)
{
	printf("before go_up data->player->x_pos: %f\n", data->player->x_pos);
	printf("before go_up data->player->y_pos: %f\n", data->player->y_pos);
	// 250.000000
	// 250.000000
	double	x_new;
	double	y_new;

	x_new = data->player->x_pos + data->player->x_dir * SPEED;
	y_new = data->player->y_pos + data->player->y_dir * SPEED;
	printf("x_new : %f\n", x_new);
	printf("y_new : %f\n", y_new);
	// x_new : 254.200000
	// y_new : 245.800000

	// Vérifiez si le déplacement est autorisé avant de mettre à jour la position
	if (good_move(data, x_new, y_new)) {
		data->player->x_pos = x_new;
		data->player->y_pos = y_new;
	}
	printf("bis x_new : %f\n", x_new);
	printf("bis y_new : %f\n", y_new);
	// x_new : 254.200000
	// y_new : 245.800000
	printf("after go_up data->player->x_pos: %f\n", data->player->x_pos);
	printf("after go_up data->player->y_pos: %f\n", data->player->y_pos);
	// 250.000000
	// 250.000000
	return (0);
}

int	go_left(t_data *data)
{
	double	x_new;
	double	y_new;

	x_new = data->player->x_pos + data->player->y_dir * SPEED;
	y_new = data->player->y_pos - data->player->x_dir * SPEED;

	// Vérifiez si le déplacement est autorisé avant de mettre à jour la position
	if (good_move(data, x_new, y_new)) {
		data->player->x_pos = x_new;
		data->player->y_pos = y_new;
	}

	return (0);
}

int	go_down(t_data *data)
{
	double	x_new;
	double	y_new;

	x_new = data->player->x_pos - data->player->x_dir * SPEED;
	y_new = data->player->y_pos - data->player->y_dir * SPEED;

	// Vérifiez si le déplacement est autorisé avant de mettre à jour la position
	if (good_move(data, x_new, y_new)) {
		data->player->x_pos = x_new;
		data->player->y_pos = y_new;
	}

	return (0);
}

int	go_right(t_data *data)
{
	double	x_new;
	double	y_new;

	x_new = data->player->x_pos - data->player->y_dir * SPEED;
	y_new = data->player->y_pos + data->player->x_dir * SPEED;

	// Vérifiez si le déplacement est autorisé avant de mettre à jour la position
	if (good_move(data, x_new, y_new)) {
		printf("1) before x_new : %f\n", data->player->x_pos);
		data->player->x_pos = x_new;
		printf("2) after x_new : %f\n", data->player->x_pos);

		printf("3) before x_new : %f\n", data->player->y_pos);
		data->player->y_pos = y_new;
		printf("4) afer y_new : %f\n", data->player->y_pos);
	}

	return (0);
}

// pour connaître le nb total de mouvements effectués bro
// int	go_move(t_data *data)
// {
// 	int	go;

// 	go = 0;
	
// 	if (data->player->y_move == 1)
// 		go += go_up(data);
// 	if (data->player->x_move == -1)
// 		go += go_left(data);
// 	if (data->player->y_move == -1)
// 		go += go_down(data);
// 	if (data->player->x_move == 1)
// 		go += go_right(data);
// 	// if (data->player->rotate != 0)
// 	// 	go += go_rotate(data, data->player->rotate);
// 	return (go);
// }
