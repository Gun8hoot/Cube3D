/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:19:45 by thlibers          #+#    #+#             */
/*   Updated: 2026/04/07 10:52:49 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

static int	can_move(t_game *game, int new_x, int new_y)
{
	char	tile;

	if (new_x < 0 || new_y < 0 || new_x >= WIDTH
		|| new_y >= HEIGHT)
		return (0);
	tile = game->map.grid[new_y][new_x];
	if (tile == WALL)
		return (0);
	return (1);
}

static void	update_player_position(t_game *game, int new_x, int new_y)
{
	int	p_pos_x;
	int	p_pos_y;

	p_pos_x = game->player.pos_x;
	p_pos_y = game->player.pos_y;
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

void	move_camera(t_game *game, double dx, double dy)
{
	game->player.dir_x += dx;
	game->player.dir_y += dy;
}
