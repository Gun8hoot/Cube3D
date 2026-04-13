/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:42:33 by nclavel           #+#    #+#             */
/*   Updated: 2026/04/13 15:53:35 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

void	init_struct(t_game *game)
{
	ft_memset(game, '\0', sizeof(t_game));
	ft_memset(&game->map, '\0', sizeof(t_map));
	ft_memset(&game->minimap, '\0', sizeof(t_minimap));
	ft_memset(&game->player, '\0', sizeof(t_player));
	ft_memset(&game->ray, '\0', sizeof(t_ray));
	ft_memset(&game->render, '\0', sizeof(t_render));
	ft_memset(&game->weapon, '\0', sizeof(t_weapon));
	ft_memset(&game->r_img, '\0', sizeof(t_img));
	ft_memset(&game->w_img, '\0', sizeof(t_img));
	ft_memset(&game->keys_pressed, '\0', sizeof(game->keys_pressed));
	ft_memset(&game->fps, '\0', sizeof(t_fps));
	ft_memset(&game->player.door, '\0', sizeof(t_door));
	game->weapon.remaining_bullet = MAX_AMMO_NUM;
}

void	init_render(t_game *game)
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

t_map	*init_map(t_map *map, char *filepath)
{
	map->filepath = filepath;
	if (!extract_info(map))
		return (NULL);
	if (!extract_map(map))
		return (NULL);
	if (!get_player_pos(map))
		return (NULL);
	init_door(map);
	if (map->number_char_max > 320 || map->line_number > 180)
		return (NULL);
	return (map);
}

void	init_player(t_game *game)
{
	game->player.pos_x = game->map.start_pos[1] + 0.50;
	game->player.pos_y = game->map.start_pos[0] + 0.50;
	game->player.dir_x = game->map.looking_at[1];
	game->player.dir_y = game->map.looking_at[0];
}

bool	init(t_game *game, char *filepath)
{
	init_struct(game);
	if (!init_map(&game->map, filepath))
		return (false);
	init_player(game);
	return (true);
}
