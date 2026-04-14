/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:19:45 by thlibers          #+#    #+#             */
/*   Updated: 2026/04/13 16:46:54 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

static int	can_move(t_game *game, double new_x, double new_y)
{
	if (new_x < 0 || new_y < 0 || new_x >= WIDTH || new_y >= HEIGHT)
		return (0);
	if (game->map.grid[(int)new_y][(int)new_x] == WALL
		|| game->map.grid[(int)new_y][(int)new_x] == DOOR_CLOSE)
		return (0);
	return (1);
}

void	move_player(t_game *game, double dx, double dy, unsigned short keycode)
{
	static struct timeval	last_move[65535] = {0};
	double					new_x;
	double					new_y;

	new_x = game->player.pos_x + dx * PLA_SPEED;
	new_y = game->player.pos_y + dy * PLA_SPEED;
	if (ms_time(NULL) - timeval_to_ms(last_move[keycode], NULL) < 10)
		return ;
	gettimeofday(&last_move[keycode], 0);
	if (can_move(game, new_x, new_y))
	{
		if (game->map.grid[(int)game->player.pos_y][(int)game->player.pos_x] != WALL
			&& game->map.grid[(int)game->player.pos_y][(int)game->player.pos_x] != DOOR_CLOSE)
		{
			if (game->map.grid[(int)new_y][(int)new_x] == DOOR_OPEN)
			{
				game->player.door.is_on_door = true;
				game->player.door.door_cord[0] = new_y;
				game->player.door.door_cord[1] = new_x;
			}
			// printf("[+] is_ondoor=%d\ndoor coords\n\tx=%ld\n\ty=%ld\nNew coords\n\tx=%ld\n\ty=%ld\n\n", game->player.door.is_on_door, game->player.door.door_cord[1], game->player.door.door_cord[0], (size_t)new_x, (size_t)new_y);
			if (game->player.door.is_on_door
				&& (game->player.door.door_cord[0] != (size_t)new_y
					|| game->player.door.door_cord[1] != (size_t)new_x))
			{
				game->map.grid[(int)game->player.pos_y][(int)game->player.pos_x] = DOOR_OPEN;
				ft_memset(&game->player.door, '\0', sizeof(t_door));
			}
			else
				game->map.grid[(int)game->player.pos_y][(int)game->player.pos_x] = FLOOR;
			game->map.grid[(int)new_y][(int)new_x] = PLAYER;
		}
		game->player.pos_x = new_x;
		game->player.pos_y = new_y;
	}
}

void	move_camera(t_game *game, double rot_speed)
{
	static struct timeval	last_move = {0};
	double					olddir;
	double					oldplane;

	if (ms_time_cmp(ms_time(NULL), timeval_to_ms(last_move, NULL), NULL) < 10)
		return ;
	gettimeofday(&last_move, 0);
	olddir = game->player.dir_x;
	oldplane = game->render.plane.x;
	game->player.dir_x = game->player.dir_x * cos(rot_speed)
		- game->player.dir_y * sin(rot_speed);
	game->player.dir_y = olddir * sin(rot_speed) + game->player.dir_y
		* cos(rot_speed);
	game->render.plane.x = game->render.plane.x * cos(rot_speed)
		- game->render.plane.y * sin(rot_speed);
	game->render.plane.y = oldplane * sin(rot_speed) + game->render.plane.y
		* cos(rot_speed);
}

void	chose_action(t_game *game)
{
	if (game->keys_pressed[KEY_W] == 1 || game->keys_pressed[KEY_S] == 1
		|| game->keys_pressed[KEY_A] == 1 || game->keys_pressed[KEY_D] == 1)
	{
		if (!game->weapon.is_animating)
			game->weapon.is_animating = true;
	}
	if (game->keys_pressed[KEY_R] == 1 && game->weapon.is_reloading == false)
		weapon_reload(game);
	if (game->keys_pressed[KEY_W] == 1 && game->keys_pressed[KEY_S] == 0)
		move_player(game, game->player.dir_x, game->player.dir_y, KEY_W);
	if (game->keys_pressed[KEY_S] == 1 && game->keys_pressed[KEY_W] == 0)
		move_player(game, -game->player.dir_x, -game->player.dir_y, KEY_S);
	if (game->keys_pressed[KEY_D] == 1 && game->keys_pressed[KEY_A] == 0)
		move_player(game, -game->player.dir_y, game->player.dir_x, KEY_D);
	if (game->keys_pressed[KEY_A] == 1 && game->keys_pressed[KEY_D] == 0)
		move_player(game, game->player.dir_y, -game->player.dir_x, KEY_A);
	if (game->keys_pressed[KEY_RIGHT] == 1 && game->keys_pressed[KEY_LEFT] == 0)
		move_camera(game, ROT_SPEED);
	if (game->keys_pressed[KEY_LEFT] == 1 && game->keys_pressed[KEY_RIGHT] == 0)
		move_camera(game, -ROT_SPEED);
	if (game->keys_pressed[KEY_E] == 1 ^ game->keys_pressed[KEY_SPC] == 1)
		open_door(game);
}
