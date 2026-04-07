/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:19:45 by thlibers          #+#    #+#             */
/*   Updated: 2026/04/07 14:28:12 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

static int	can_move(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_y < 0 || new_x >= WIDTH
		|| new_y >= HEIGHT)
		return (0);
	if (game->map.grid[new_y][new_x] == WALL)
		return (0);
	return (1);
}

static void	update_player_position(t_game *game, int new_x, int new_y)
{
	int	old_pos_x;
	int	old_pos_y;

	old_pos_x = game->player.pos_x;
	old_pos_y = game->player.pos_y;
	game->map.grid[old_pos_y][old_pos_x] = FLOOR;
	game->player.pos_x = new_x;
	game->player.pos_y = new_y;
	game->map.grid[new_y][new_x] = PLAYER;
}

void	move_player(t_game *game, double dx, double dy)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + dx;
	new_y = game->player.pos_y + dy;
	if (can_move(game, (int)new_x, (int)new_y))
		update_player_position(game, (int)new_x, (int)new_y);
}

void	move_camera(t_game *game, double rot_speed)
{
	double	olddir;
	double	oldplane;

	olddir = game->player.dir_x;
	oldplane = game->render.plane.x;
	game->player.dir_x = game->player.dir_x * cos(rot_speed) - game->player.dir_y * sin(rot_speed);
	game->player.dir_y = olddir * sin(rot_speed) + game->player.dir_y * cos(rot_speed);
	game->render.plane.x = game->render.plane.x * cos(rot_speed) - game->render.plane.y * sin(rot_speed);
	game->render.plane.y = oldplane * sin(rot_speed) + game->render.plane.y * cos(rot_speed);
}
