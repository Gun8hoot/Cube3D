/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 09:59:26 by thlibers          #+#    #+#             */
/*   Updated: 2026/04/10 17:35:06 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

int	handle_key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		clear_game(game);
	game->keys_pressed[keycode] = 1;
	return (0);
}

int	handle_key_release(int keycode, t_game *game)
{
	game->keys_pressed[keycode] = 0;
	return (0);
}
