/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 08:56:35 by thlibers          #+#    #+#             */
/*   Updated: 2026/04/14 19:06:01 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

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
			my_mlx_pixel_put(game, x, y, *game->map.c_color);
			x++;
		}
		y++;
	}
	while (y <= HEIGHT)
	{
		x = 0;
		while (x <= WIDTH)
		{
			my_mlx_pixel_put(game, x, y, *game->map.f_color);
			x++;
		}
		y++;
	}
}

void	animating_weapon(t_game *game)
{
	static struct timeval	last_anim = {0};

	if (ms_time(NULL) - timeval_to_ms(last_anim, NULL) < 15)
		return ;
	gettimeofday(&last_anim, NULL);
	if (game->weapon.is_animating && game->weapon.frame < ANIM_FRAME)
		game->weapon.frame++;
	else if (game->weapon.frame == ANIM_FRAME)
	{
		game->weapon.is_animating = false;
		game->weapon.frame = 0;
	}
}
