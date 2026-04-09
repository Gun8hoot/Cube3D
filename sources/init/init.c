/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:42:33 by nclavel           #+#    #+#             */
/*   Updated: 2026/04/09 13:02:19 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

void	init_struct(t_game *game)
{
	ft_memset(game, '\0', sizeof(t_game));
	ft_memset(&game->map, '\0', sizeof(t_game));
	ft_memset(&game->minimap, '\0', sizeof(t_minimap));
	ft_memset(&game->player, '\0', sizeof(t_player));
	ft_memset(&game->ray, '\0', sizeof(t_ray));
	ft_memset(&game->render, '\0', sizeof(t_render));
	ft_memset(&game->weapon, '\0', sizeof(t_weapon));
	ft_memset(game->keys_pressed, 0, sizeof(game->keys_pressed));
}

bool	init(t_game *game, char *filepath)
{
	init_struct(game);
	if (!init_map(&game->map, filepath))
		return (false);
	return (true);
}
