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

int handle_key_press(int keycode, t_game *game)
{
    if (keycode == KEY_ESC)
        handle_close(game);
    game->keys_pressed[keycode] = 1;
    return (0);
}

int handle_key_release(int keycode, t_game *game)
{
    game->keys_pressed[keycode] = 0;
    return (0);
}

int handle_close(t_game *game)
{
	int i;

	if (game->r_img.img)
		mlx_destroy_image(game->mlx, game->r_img.img);
	if (game->w_img.img)
		mlx_destroy_image(game->mlx, game->w_img.img);
	i = 0;
	while (i < 4)
	{
		if (game->textures[i].img)
			mlx_destroy_image(game->mlx, game->textures[i].img);
		i++;
	}
    mlx_destroy_window(game->mlx, game->win);
    mlx_destroy_display(game->mlx);
    free(game->mlx);
    clear_game(game);
    exit(0);
}
