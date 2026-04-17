/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 12:36:27 by thlibers          #+#    #+#             */
/*   Updated: 2026/04/17 17:49:33 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

static bool	minimap_padding(t_game *game, size_t data, size_t inferior_to)
{
	size_t	px_per_line;
	bool	has_modify;

	has_modify = false;
	while (game->minimap.pixel_per_elem > 0)
	{
		px_per_line = game->minimap.pixel_per_elem * data;
		if (px_per_line >= inferior_to - INBOX_PADD)
		{
			game->minimap.pixel_per_elem--;
			has_modify = true;
		}
		else
			break ;
	}
	if (has_modify == true)
		return (false);
	if (inferior_to == MINIMAP_WIDTH)
		game->minimap.padding_right_left = (MINIMAP_WIDTH - px_per_line) / 2;
	else
		game->minimap.padding_top_bottom = (MINIMAP_HEIGHT - px_per_line) / 2;
	return (true);
}

bool	calculate_minimap(t_game *game)
{
	game->minimap.pixel_per_elem = DEFAULT_ELEM_SIZE;
	while (game->minimap.pixel_per_elem > 0)
	{
		if (!minimap_padding(game, game->map.line_number, MINIMAP_HEIGHT))
			continue ;
		if (!minimap_padding(game, game->map.number_char_max, MINIMAP_WIDTH))
			continue ;
		break ;
	}
	if (game->minimap.pixel_per_elem == 0)
		return (false);
	return (true);
}

static void	show_vision(t_game *game)
{
	t_ray	ray;
	double	camera;
	double	hit_x;
	double	hit_y;

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
	{
		hit_x = game->player.pos_x + ray.perp_wall_dist * ray.ray_dir.x;
		hit_y = game->player.pos_y + ray.perp_wall_dist * ray.ray_dir.y;
		t_vec v0 = {(int)(game->minimap.padding_right_left + 4
			+ game->minimap.pixel_per_elem / 2 + (int)game->player.pos_x
			* game->minimap.pixel_per_elem), (int)(game->minimap.padding_top_bottom + 4
			+ game->minimap.pixel_per_elem / 2 + (int)game->player.pos_y
			* game->minimap.pixel_per_elem)};
		t_vec v1 = {(int)(game->minimap.padding_right_left + 4
			+ hit_x * game->minimap.pixel_per_elem),
			(int)(game->minimap.padding_top_bottom + 4 + hit_y
			* game->minimap.pixel_per_elem)};
		draw_line(game, v0, v1);
	}
}

void	show_minimap(t_game *game)
{
	double	py;
	double	px;

	draw_box(game, (t_vec){MINIMAP_WIDTH + 4, MINIMAP_HEIGHT + 4}, 0xFFFFFF, 4);
	draw_box(game, (t_vec){MINIMAP_WIDTH, MINIMAP_HEIGHT}, 0x202020, 8);
	py = game->minimap.padding_top_bottom + 4;
	for (double y = 0; game->map.grid[(size_t)y]; y++)
	{
		px = game->minimap.padding_right_left + 4;
		for (double x = 0; game->map.grid[(size_t)y][(size_t)x]; x++)
		{
			if (game->map.grid[(size_t)y][(size_t)x] == WALL)
				draw_square(game, (t_vec){px, py},
					game->minimap.pixel_per_elem, B_GREEN);
			else if (game->map.grid[(size_t)y][(size_t)x] == PLAYER)
				draw_square(game, (t_vec){px, py},
					game->minimap.pixel_per_elem, B_RED);
			else if (game->map.grid[(size_t)y][(size_t)x] == DOOR_CLOSE)
				draw_square(game, (t_vec){px, py},
					game->minimap.pixel_per_elem, B_YELLOW);
			else if (game->map.grid[(size_t)y][(size_t)x] == DOOR_OPEN)
				draw_square(game, (t_vec){px, py},
					game->minimap.pixel_per_elem, B_BLUE);
			px += game->minimap.pixel_per_elem;
		}
		py += game->minimap.pixel_per_elem;
	}
	show_vision(game);
}
