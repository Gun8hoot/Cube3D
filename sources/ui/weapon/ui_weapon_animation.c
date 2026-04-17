/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_weapon_animation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 12:38:45 by thlibers          #+#    #+#             */
/*   Updated: 2026/04/17 12:38:48 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

void	reloading_anim(t_game *game)
{
	static struct timeval	time_last_frame = {0};
	static int				frame = 0;

	if (ms_time(NULL) - timeval_to_ms(time_last_frame, NULL) < 300)
		return ;
	gettimeofday(&time_last_frame, NULL);
	if (frame < 6)
		game->w_img = &game->weapon.reload[frame++];
	else
	{
		game->weapon.is_reloading = false;
		frame = 0;
	}
}

void	shooting_anim(t_game *game)
{
	static struct timeval	time_last_frame = {0};
	static int				frame = 0;

	hitmarker(game);
	if (ms_time(NULL) - timeval_to_ms(time_last_frame, NULL) < 200)
		return ;
	gettimeofday(&time_last_frame, NULL);
	if (frame < 6)
		game->w_img = &game->weapon.fire[frame++];
	else
	{
		game->weapon.is_shooting = false;
		frame = 0;
	}
}
