/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 14:17:34 by thlibers          #+#    #+#             */
/*   Updated: 2026/04/13 14:17:37 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

int	mouse(t_game *game)
{
	int		new_x;
	int		new_y;
	double	rotation;

	(void)new_y;
	mlx_mouse_get_pos(game->mlx, game->win, &new_x, &new_y);
	rotation = (new_x - ((double)WIDTH / 2));
	mlx_mouse_move(game->mlx, game->win, WIDTH / 2, HEIGHT / 2);
	if (rotation != 0)
		move_camera(game, rotation / 500);
	game->old_mouse_pos = new_x;
	return (0);
}
