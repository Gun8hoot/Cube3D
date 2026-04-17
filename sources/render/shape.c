/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:42:31 by thlibers          #+#    #+#             */
/*   Updated: 2026/04/17 17:59:09 by thlibers         ###   ########.fr       */
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

static void	ft_nathan(t_line *line, t_vec *v0, t_vec *v1)
{
	line->d.x = abs(v1->x - v0->x);
	line->d.y = abs(v1->y - v0->y);
	if (v0->x < v1->x)
		line->s.x = 1;
	else
		line->s.x = -1;
	if (v0->y < v1->y)
		line->s.y = 1;
	else
		line->s.y = -1;
	line->err = (int)line->d.x - (int)line->d.y;
}

void	draw_line(t_game *game, t_vec v0, t_vec v1)
{
	t_line	line;

	ft_nathan(&line, &v0, &v1);
	while (1)
	{
		mlx_pixel_put(game->mlx, game->win, v0.x, v0.y, 0xFFFFFF);
		if (v0.x == v1.x && v0.y == v1.y)
			break ;
		line.e2 = 2 * line.err;
		if (line.e2 > -(int)line.d.y)
		{
			line.err -= (int)line.d.y;
			v0.x += line.s.x;
		}
		if (line.e2 < (int)line.d.x)
		{
			line.err += (int)line.d.x;
			v0.y += line.s.y;
		}
	}
}
