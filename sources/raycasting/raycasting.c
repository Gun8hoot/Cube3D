/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 13:50:21 by thlibers          #+#    #+#             */
/*   Updated: 2026/04/08 12:22:04 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

void	render_init(t_game *game)
{
	game->render.plane_length = tan((FOV * M_PI / 180.0) / 2.0);
	game->render.plane.x = -game->player.dir_y * game->render.plane_length;
    game->render.plane.y = game->player.dir_x * game->render.plane_length;
	game->render.time = 0.0;
	game->render.oldtime = 0.0;
	game->render.draw_start = 0;
	game->render.draw_end = 0;
	game->render.line_height = 0;
}

void	check_hit(t_ray *ray, t_game game)
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
      if (game.map.grid[ray->map_y][ray->map_x] == '1')
		ray->hit = 1;
    }
      if(ray->side == 0)
	  	ray->perp_wall_dist = (ray->side_dist.x - ray->delta_dist.x);
    else
	  	ray->perp_wall_dist = (ray->side_dist.y - ray->delta_dist.y);
}

void	ft_rayshooter(t_ray *ray, t_game game)
{
	int		x;
	int		y;
	int	color = 0xFF808080;
	double	camera;

	x = 0;
	while(x < WIDTH)
    {
	  	render_init(&game);
    	camera = 2 * x / (double)WIDTH - 1;
    	ray->ray_dir.x = game.player.dir_x + game.render.plane.x * camera;
		ray->ray_dir.y = game.player.dir_y + game.render.plane.y * camera;
		ray->map_x = (int)game.player.pos_x;
        ray->map_y = (int)game.player.pos_y;
		ray->delta_dist.x = fabs(1.0 / ray->ray_dir.x);
		ray->delta_dist.y = fabs(1.0 / ray->ray_dir.y);
		ft_dda(ray, game);
		check_hit(ray, game);
		line_height(&game.render, *ray);
        y = game.render.draw_start;
        while (y < game.render.draw_end)
        {
            my_mlx_pixel_put(&game, x, y, color);
            y++;
        }
		x++;
	}
}
