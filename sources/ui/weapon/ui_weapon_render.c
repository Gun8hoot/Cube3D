/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_weapon_render.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 12:38:41 by thlibers          #+#    #+#             */
/*   Updated: 2026/04/17 18:32:16 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

bool	init_anim_weapon(t_game *game)
{
	if (!ft_text_load(game, &game->weapon.idle, IDLE))
		return (false);
	if (!ft_text_load(game, &game->weapon.fire[0], FIRE_A1))
		return (false);
	if (!ft_text_load(game, &game->weapon.fire[1], FIRE_A2))
		return (false);
	if (!ft_text_load(game, &game->weapon.fire[2], FIRE_A3))
		return (false);
	if (!ft_text_load(game, &game->weapon.fire[3], FIRE_A4))
		return (false);
	if (!ft_text_load(game, &game->weapon.fire[4], FIRE_A5))
		return (false);
	if (!ft_text_load(game, &game->weapon.reload[0], RELOAD_A1))
		return (false);
	if (!ft_text_load(game, &game->weapon.reload[1], RELOAD_A2))
		return (false);
	if (!ft_text_load(game, &game->weapon.reload[2], RELOAD_A3))
		return (false);
	if (!ft_text_load(game, &game->weapon.reload[3], RELOAD_A4))
		return (false);
	if (!ft_text_load(game, &game->weapon.reload[4], RELOAD_A5))
		return (false);
	return (true);
}

static void	set_weapon_pos(t_game *game, t_img img)
{
	int	offset;

	game->weapon.start_x = WIDTH - img.width;
	game->weapon.start_y = HEIGHT - img.height;
	if (game->weapon.is_animating)
	{
		offset = (ANIM_FRAME / 2) - abs(game->weapon.frame - (ANIM_FRAME / 2));
		game->weapon.start_y += offset * 2;
		game->weapon.start_x -= offset;
	}
}

static void	draw_weapon_texture(t_game *game, t_img img)
{
	int	x;
	int	y;

	y = 0;
	while (y < img.height)
	{
		x = 0;
		while (x < img.width)
		{
			game->weapon.dst = img.addr + (y * img.line_length) + (x
					* (img.bits_per_pixel / 8));
			game->weapon.color = *(int *)game->weapon.dst;
			if (game->weapon.color != B_BLACK)
				my_mlx_pixel_put(game, game->weapon.start_x + x,
					game->weapon.start_y + y, game->weapon.color);
			x++;
		}
		y++;
	}
}

void	weapon(t_game *game, t_img img)
{
	if (!img.img)
		return ;
	set_weapon_pos(game, img);
	draw_weapon_texture(game, img);
}
