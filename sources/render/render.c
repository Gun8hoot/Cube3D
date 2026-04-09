/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 08:56:35 by thlibers          #+#    #+#             */
/*   Updated: 2026/04/09 14:36:57 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

// void	choose_textures(t_game *game)
// {

// }

void	celling_floor(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y <= HEIGHT / 2)
	{
		x = 0;
		while (x <= WIDTH)
		{
			my_mlx_pixel_put(game, x, y, game->map.c_color);
			x++;
		}
		y++;
	}
	while (y <= HEIGHT)
	{
		x = 0;
		while (x <= WIDTH)
		{
			my_mlx_pixel_put(game, x, y, game->map.f_color);
			x++;
		}
		y++;
	}
}

void	weapon(t_game *game)
{
	int	x;
	int	y;

	if (!game->balista)
		return ;
	game->weapon.start_x = 1280 - game->w_width - 280;
	game->weapon.start_y = 720 - game->w_height;
	y = 0;
	while (y < game->w_height)
	{
		x = 0;
		while (x < game->w_width)
		{
			game->weapon.dst = game->weapon_addr + (y
					* game->weapon_line_length) + (x
					* (game->weapon_bits_per_pixel / 8));
			game->weapon.color = *(int *)game->weapon.dst;
			if (game->weapon.color != 0x000000)
				my_mlx_pixel_put(game, game->weapon.start_x + x,
					game->weapon.start_y + y, game->weapon.color);
			x++;
		}
		y++;
	}
}
