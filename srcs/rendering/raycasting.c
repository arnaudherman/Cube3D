#include "cub3d.h"

// TO DO : Check < 20 et * 10 cause magic numbers
void	get_perp_and_height(t_ray *ray, t_player *player, t_mlx *mlx)
{
	if (ray->side == 0 || ray->side == 1)
		ray->wall_dist = (ray->x_map - player->x_pos
				+ (1 - ray->x_step) / 2) / ray->dir_x;
	else
		ray->wall_dist = (ray->y_map - player->y_pos
				+ (1 - ray->y_step) / 2) / ray->dir_y;
	// ray->wall_dist *= cos(ray->camera_x * M_PI / 180);
	ray->line_height = (int)(mlx->win_height / ray->wall_dist) * WALL_HEIGHT_MULT;
	ray->draw_start = -ray->line_height / 2 + mlx->win_height / 2;
	if (ray->draw_start < 20)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + mlx->win_height / 2;
	if (ray->draw_end >= mlx->win_height)
		ray->draw_end = mlx->win_height - 1;
}

void	raycasting(t_data *data, t_player *player, t_mlx *mlx)
{
	t_ray	ray;
	int		x;

	x = 0;
	if (!(ray.z_index = (double *)malloc(sizeof(double) * mlx->win_width)))
		perror("Malloc z_index failed in raycasting();\n");
	ft_bzero(ray.z_index, sizeof(double) * mlx->win_width);
	while (x < mlx->win_width)
	{
		init_default_ray(&ray);
		ray.x = x;
		init_ray(&ray, player);
		dda(data, &data->map, &ray);
		get_perp_and_height(&ray, player, mlx);
		draw_col(data, mlx, &ray);
		x += 1;
	}
	free(ray.z_index);
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.mlx_win_ptr,
		data->world->img, 0, 0);
}
