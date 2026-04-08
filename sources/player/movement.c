/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:19:45 by thlibers          #+#    #+#             */
/*   Updated: 2026/04/08 17:12:22 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

static int	can_move(t_game *game, double new_x, double new_y)
{
	if (new_x < 0 || new_y < 0 || new_x >= WIDTH
		|| new_y >= HEIGHT)
		return (0);
	if (game->map.grid[(int)new_y][(int)new_x] == WALL) // ne fonctionne pas
		return (0);
	return (1);
}

// static void	update_player_position(t_game *game, double new_x, double new_y)
// {
// 	game->player.pos_x = new_x;
// 	game->player.pos_y = new_y;
// 	system("clear");					// DEBUG
// 	show_grid(game->map.grid);
// }

void	move_player(t_game *game, double dx, double dy)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + dx;
	new_y = game->player.pos_y + dy;
	if (can_move(game, new_x, new_y))
	{
		game->player.pos_x = new_x;
		game->player.pos_y = new_y;
		system("clear");					// DEBUG
		show_grid(game->map.grid);
	}
}

void	chose_action(t_game *game)
{
	if (game->keys_pressed[KEY_W] == 1 && game->keys_pressed[KEY_S] == 0)
		move_player(game, game->player.dir_x * PLA_SPEED, game->player.dir_y * PLA_SPEED);
	else if (game->keys_pressed[KEY_S] == 1 && game->keys_pressed[KEY_W] == 0)
		move_player(game, -game->player.dir_x * PLA_SPEED, -game->player.dir_y * PLA_SPEED);		// quand deux input sont presses simutanement
	else if (game->keys_pressed[KEY_D] == 1 && game->keys_pressed[KEY_A] == 0)
		move_player(game, -game->player.dir_y * PLA_SPEED, game->player.dir_x * PLA_SPEED);
	else if (game->keys_pressed[KEY_A] == 1 && game->keys_pressed[KEY_D] == 0)
		move_player(game, game->player.dir_y * PLA_SPEED, -game->player.dir_x * PLA_SPEED);
	else if (game->keys_pressed[KEY_RIGHT] == 1 && game->keys_pressed[KEY_LEFT] == 0)
		move_camera(game, ROT_SPEED);
	else if (game->keys_pressed[KEY_LEFT] == 1 && game->keys_pressed[KEY_RIGHT] == 0)
		move_camera(game, -ROT_SPEED);
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
	system("clear");					// DEBUG
	show_grid(game->map.grid);
	printf("\n[+] Direction of view:\n\tx = %.2f\n\ty = %.2f\n", game->player.dir_x, game->player.dir_y);
}
