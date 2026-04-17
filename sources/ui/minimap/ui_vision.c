/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_vision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 19:28:20 by thlibers          #+#    #+#             */
/*   Updated: 2026/04/17 19:56:50 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

static void	draw_vision_line(t_game *game, t_ray *ray)
{
	double	hit_x;
	double	hit_y;
	t_vec	v0;
	t_vec	v1;

	hit_x = game->player.pos_x + ray->perp_wall_dist * ray->ray_dir.x;
	hit_y = game->player.pos_y + ray->perp_wall_dist * ray->ray_dir.y;
	v0.x = (int)(game->minimap.padding_right_left + 4
			+ game->minimap.pixel_per_elem / 2 + (int)game->player.pos_x
			* game->minimap.pixel_per_elem);
	v0.y = (int)(game->minimap.padding_top_bottom + 4
			+ game->minimap.pixel_per_elem / 2 + (int)game->player.pos_y
			* game->minimap.pixel_per_elem);
	v1.x = (int)(game->minimap.padding_right_left + 4 + hit_x
			* game->minimap.pixel_per_elem);
	v1.y = (int)(game->minimap.padding_top_bottom + 4 + hit_y
			* game->minimap.pixel_per_elem);
	draw_line(game, v0, v1);
}

void	show_vision(t_game *game)
{
	t_ray	ray;
	double	camera;

	camera = (double)HEIGHT / (double)WIDTH;
	ray.ray_dir.x = game->player.dir_x * camera;
	ray.ray_dir.y = game->player.dir_y * camera;
	ray.map_x = (int)game->player.pos_x;
	ray.map_y = (int)game->player.pos_y;
	ray.delta_dist.x = fabs(1.0 / ray.ray_dir.x);
	ray.delta_dist.y = fabs(1.0 / ray.ray_dir.y);
	setup_dda(&ray, game);
	check_hit(&ray, game);
	if (ray.hit == 1)
		draw_vision_line(game, &ray);
}
