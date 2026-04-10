/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 08:56:35 by thlibers          #+#    #+#             */
/*   Updated: 2026/04/10 17:09:32 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

// void	textures(t_game *game)
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

	if (!game->w_img.img)
		return ;
	game->weapon.start_x = WIDTH - game->w_img.width - 280;
	game->weapon.start_y = HEIGHT - game->w_img.height;
	if (game->weapon.is_animating)
		game->weapon.start_y += (10 * game->weapon.anim_frame);	
	y = 0;
	while (y < game->w_img.height)
	{
		x = 0;
		while (x < game->w_img.width)
		{
			game->weapon.dst = game->w_img.addr + (y
					* game->w_img.line_length) + (x
					* (game->w_img.bits_per_pixel / 8));
			game->weapon.color = *(int *)game->weapon.dst;
			if (game->weapon.color != 0x000000)
				my_mlx_pixel_put(game, game->weapon.start_x + x,
					game->weapon.start_y + y, game->weapon.color);
			x++;
		}
		y++;
	}
}

void	animating_weapon(t_game *game)
{
	if (game->weapon.is_animating && game->weapon.anim_frame < ANIM_FRAME)
		game->weapon.anim_frame++;
	else if (game->weapon.anim_frame == ANIM_FRAME)
	{
		game->weapon.is_animating = false;
		game->weapon.anim_frame = 0;
	}
}
