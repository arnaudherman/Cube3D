#include "cub3d.h"

void	calculate_deltas(t_ray *ray)
{
	if (ray->dir_y == 0)
		ray->dx = 0;
	else if (ray->dir_x == 0)
		ray->dx = 1;
	else
		ray->dx = fabs(1 / ray->dir_x);
	if (ray->dir_x == 0)
		ray->dy = 0;
	else if (ray->dir_y == 0)
		ray->dy = 1;
	else
		ray->dy = fabs(1 / ray->dir_y);
}

void	calculate_steps_sides(t_ray *ray, t_player *player)
{
	if (ray->dir_x < 0)
	{
		ray->x_step = -1;
		ray->sx = (player->x_pos - ray->x_map) * ray->dx;
	}
	else
	{
		ray->x_step = 1;
		ray->sx = (ray->x_map - player->x_pos + 1.0)
			* ray->dx;
	}
	if (ray->dir_y < 0)
	{
		ray->y_step = -1;
		ray->sy = (player->y_pos - ray->y_map) * ray->dy;
	}
	else
	{
		ray->y_step = 1;
		ray->sy = (ray->y_map - player->y_pos + 1.0)
			* ray->dy;
	}
}

void	init_ray(t_ray *ray, t_player *player)
{
	float	rad_fov;
	float	angle;

	ray->x_map = (int)player->x_pos;
	ray->y_map = (int)player->y_pos;
	rad_fov = player->fov * M_PI / 180;
	angle = player->angle + (player->fov / 2)
		- (ray->x * rad_fov / WINDOW_WIDTH);
	ray->dir_x = player->x_dir * cos(angle)
		- player->y_dir * sin(angle);
	ray->dir_y = player->x_dir * sin(angle)
		+ player->y_dir * cos(angle);
	ray->dx = fabs(1 / ray->dir_x);
	ray->dy = fabs(1 / ray->dir_y);
	if (ray->dir_x < 0)
	{
		ray->x_step = -1;
		ray->sx = (player->x_pos - ray->x_map) * ray->dx;
	}
	else
	{
		ray->x_step = 1;
		ray->sx = (ray->x_map + 1.0 - player->x_pos) * ray->dx;
	}
	if (ray->dir_y < 0)
	{
		ray->y_step = -1;
		ray->sy = (player->y_pos - ray->y_map) * ray->dy;
	}
	else
	{
		ray->y_step = 1;
		ray->sy = (ray->y_map + 1.0 - player->y_pos) * ray->dy;
	}
	ray->hit = 0;
}

void	init_default_ray(t_ray *ray)
{
	ray->x = 0;
	ray->y = 0;
	ray->x_map = 0;
	ray->y_map = 0;
	ray->x_step = 0;
	ray->y_step = 0;
	ray->hit = 0;
	ray->side = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
	ray->x_text = 0;
	ray->y_text = 0;
	ray->wall_x = 0.0;
	ray->z_index = NULL;
	ray->camera_x = 0.0;
	ray->wall_dist = 0.0;
	ray->dir_x = 0.0;
	ray->dir_y = 0.0;
	ray->sx = 0.0;
	ray->sy = 0.0;
	ray->dx = 0.0;
	ray->dy = 0.0;
}
