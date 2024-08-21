/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joojeon <joojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:14:48 by joojeon           #+#    #+#             */
/*   Updated: 2024/08/21 17:33:01 by joojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	set_delta_dist(t_dpable_ray *ray)
{
	if (ray -> ray_dir_x == 0)
		ray -> ddx = 1e30;
	else
		ray -> ddx = fabs(1 / ray -> ray_dir_x);
	if (ray -> ray_dir_y == 0)
		ray -> ddy = 1e30;
	else
		ray -> ddy = fabs(1 / ray -> ray_dir_y);
}

void	set_side_dist(t_dpable_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray-> step_x = -1;
		ray->sdx = (ray -> pos_x - ray -> map_x) * ray->ddx;
	} else {
		ray->step_x = 1;
		ray->sdx = (ray-> map_x + 1.0 - ray -> pos_x) * ray -> ddx;
	}

	if (ray -> ray_dir_y < 0)
	{
		ray-> step_y = -1;
		ray->sdy = (ray -> pos_y - ray-> map_y) * ray->ddy;
	} else {
		ray->step_y = 1;
		ray->sdy = (ray -> map_y + 1.0 - ray -> pos_y) * ray->ddy;
	}
}

void	init_ray(t_cub3d *cub3d, t_dpable_ray *ray, int x)
{
	double	camera_x;
	t_user	user;

	user = cub3d -> user;
	camera_x = 2 * x / (double) WINDOW_WIDTH - 1;
	ray -> ray_dir_x = user.dx + user.v_dx * camera_x;
	ray -> ray_dir_y = user.dy + user.v_dy * camera_x;
	ray -> pos_x = cub3d -> user.x;
	ray -> pos_y = cub3d -> user.y;
	ray -> map_x = (int) ray -> pos_x;
	ray -> map_y = (int) ray -> pos_y;
	set_delta_dist(ray);
	set_side_dist(ray);
}