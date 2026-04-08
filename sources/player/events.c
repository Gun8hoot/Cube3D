/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 09:59:26 by thlibers          #+#    #+#             */
/*   Updated: 2026/04/08 16:11:05 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

int	handle_keypress(int keycode, t_game *game)
{
	printf("keycode : %d\n", keycode);
	if (keycode == KEY_ESC)
		handle_close(game);
	if (keycode == KEY_W && !(keycode == KEY_S))
		move_player(game, game->player.dir_x * PLA_SPEED, game->player.dir_y * PLA_SPEED);		// les controles ne suivent pas le joueur
	if (keycode == KEY_S && !(keycode == KEY_W))
		move_player(game, -game->player.dir_x * PLA_SPEED, -game->player.dir_y * PLA_SPEED);		// quand deux input sont presses simutanement
	if (keycode == KEY_D && !(keycode == KEY_A))																				// le joueur bouge quand meme
		move_player(game, -game->player.dir_y * PLA_SPEED, game->player.dir_x * PLA_SPEED);
	if (keycode == KEY_A && !(keycode == KEY_D))
		move_player(game, game->player.dir_y * PLA_SPEED, -game->player.dir_x * PLA_SPEED);
	if (keycode == KEY_RIGHT && !(keycode == KEY_LEFT))
		move_camera(game, ROT_SPEED);
	if (keycode == KEY_LEFT && !(keycode == KEY_RIGHT))
		move_camera(game, -ROT_SPEED);
	return (0);
}

int handle_close(t_game *game)
{
    mlx_destroy_image(game->mlx, game->img);
    mlx_destroy_window(game->mlx, game->win);
    mlx_destroy_display(game->mlx);
    free(game->mlx);
    clear_game(game);
    exit(0);
}
