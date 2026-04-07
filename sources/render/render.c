/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 08:56:35 by thlibers          #+#    #+#             */
/*   Updated: 2026/04/07 09:28:55 by thlibers         ###   ########.fr       */
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
