/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 13:50:21 by thlibers          #+#    #+#             */
/*   Updated: 2026/04/13 14:54:44 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

void	ft_dda(t_ray *ray, t_game *game)
{
	if (ray->ray_dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (game->player.pos_x - ray->map_x)
			* ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map_x + 1.0 - game->player.pos_x)
			* ray->delta_dist.x;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (game->player.pos_y - ray->map_y)
			* ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map_y + 1.0 - game->player.pos_y)
			* ray->delta_dist.y;
	}
}

void	check_hit(t_ray *ray, t_game *game)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map_x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map_y += ray->step.y;
			ray->side = 1;
		}
		if (ray->map_x < 0 || ray->map_x >= (int)game->map.number_char_max
			|| ray->map_y < 0 || ray->map_y >= (int)game->map.line_number)
			ray->hit = 1;
		else if (game->map.grid[ray->map_y][ray->map_x] == WALL
			|| game->map.grid[ray->map_y][ray->map_x] == DOOR_CLOSE)
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->side_dist.x - ray->delta_dist.x);
	else
		ray->perp_wall_dist = (ray->side_dist.y - ray->delta_dist.y);
}

void	ft_rayshooter(t_ray *ray, t_game *game)
{
	int		x;
	double	camera;

	x = 0;
	init_render(game);
	while (x < WIDTH)
	{
		camera = 2 * x / (double)WIDTH - 1;
		ray->ray_dir.x = game->player.dir_x + game->render.plane.x * camera;
		ray->ray_dir.y = game->player.dir_y + game->render.plane.y * camera;
		ray->map_x = (int)game->player.pos_x;
		ray->map_y = (int)game->player.pos_y;
		ray->delta_dist.x = fabs(1.0 / ray->ray_dir.x);
		ray->delta_dist.y = fabs(1.0 / ray->ray_dir.y);
		ft_dda(ray, game);
		check_hit(ray, game);
		line_height(&game->render, *ray);
		get_texture(ray, game);
		draw_textured_line(game, x, convert_coords_textures(ray, game));
		x++;
	}
}
