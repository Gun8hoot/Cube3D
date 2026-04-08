/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:42:33 by nclavel           #+#    #+#             */
/*   Updated: 2026/04/02 17:24:42 by nclavel          ###   ########.fr       */
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
}

bool	init(t_game *game, char *filepath)
{
	init_struct(game);
	if (!init_map(&game->map, filepath))
		return (false);
	return (true);
}
