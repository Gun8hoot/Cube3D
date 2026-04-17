/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_crosshair.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 12:33:54 by thlibers          #+#    #+#             */
/*   Updated: 2026/04/17 17:49:26 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

void	crosshair(t_game *game)
{
	t_vec	v0;
	t_vec	v1;

	v0 = (t_vec){WIDTH / 2 + CR_PADD_CENTER, HEIGHT / 2};
	v1 = (t_vec){WIDTH / 2 + CR_SIZE, HEIGHT / 2};
	draw_line(game, v0, v1);
	v0 = (t_vec){WIDTH / 2 - CR_PADD_CENTER, HEIGHT / 2};
	v1 = (t_vec){WIDTH / 2 - CR_SIZE, HEIGHT / 2};
	draw_line(game, v0, v1);
	v0 = (t_vec){WIDTH / 2, HEIGHT / 2 + CR_PADD_CENTER};
	v1 = (t_vec){WIDTH / 2, HEIGHT / 2 + CR_SIZE};
	draw_line(game, v0, v1);
	v0 = (t_vec){WIDTH / 2, HEIGHT / 2 - CR_PADD_CENTER};
	v1 = (t_vec){WIDTH / 2, HEIGHT / 2 - CR_SIZE};
	draw_line(game, v0, v1);
}

void	draw_hitmarker(t_game *game)
{
	t_vec	v0;
	t_vec	v1;

	v0 = (t_vec){WIDTH / 2 + 10, HEIGHT / 2 + 10};
	v1 = (t_vec){WIDTH / 2 + 15, HEIGHT / 2 + 15};
	draw_line(game, v0, v1);
	v0 = (t_vec){WIDTH / 2 + 10, HEIGHT / 2 - 10};
	v1 = (t_vec){WIDTH / 2 + 15, HEIGHT / 2 - 15};
	draw_line(game, v0, v1);
	v0 = (t_vec){WIDTH / 2 - 10, HEIGHT / 2 + 10};
	v1 = (t_vec){WIDTH / 2 - 15, HEIGHT / 2 + 15};
	draw_line(game, v0, v1);
	v0 = (t_vec){WIDTH / 2 - 10, HEIGHT / 2 - 10};
	v1 = (t_vec){WIDTH / 2 - 15, HEIGHT / 2 - 15};
	draw_line(game, v0, v1);
}

void	hitmarker(t_game *game)
{
	draw_hitmarker(game);
}
