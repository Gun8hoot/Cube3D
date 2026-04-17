/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:42:31 by thlibers          #+#    #+#             */
/*   Updated: 2026/04/17 16:35:29 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

void	draw_box(t_game *game, t_vec max, int color, int pad)
{
	int	x;
	int	y;

	y = pad;
	while (y < max.y)
	{
		x = pad;
		while (x < max.x)
		{
			my_mlx_pixel_put(game, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_square(t_game *game, t_vec pos, int len, int color)
{
	int	x;
	int	y;

	y = pos.y;
	while (y < pos.y + len)
	{
		x = pos.x;
		while (x < pos.x + len)
		{
			my_mlx_pixel_put(game, x, y, color);
			x++;
		}
		y++;
	}
	(void)game;
}

void	draw_line(t_game *game, t_vec *v0, t_vec *v1)
{
	t_vec d;
	t_vec s;
	int	err;
	int	e2;

	d.x = abs(v1->x - v0->x);
	d.y = abs(v1->y - v0->y);
	if (v0->x < v1->x)
		s.x = 1;
	else
		s.x = -1;
	if (v0->y < v1->y)
		s.y = 1;
	else
		s.y = -1;
	err = (int)d.x - (int)d.y;
	while (1)
	{
		mlx_pixel_put(game->mlx, game->win, v0->x, v0->y, 0xFFFFFF);
		if (v0->x == v1->x && v0->y == v1->y)
			break ;
		e2 = 2 * err;
		if (e2 > -(int)d.y)
		{
			err -= (int)d.y;
			v0->x += s.x;
		}
		if (e2 < (int)d.x)
		{
			err += (int)d.x;
			v0->y += s.y;
		}
	}
}
