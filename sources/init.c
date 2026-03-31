/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:42:33 by nclavel           #+#    #+#             */
/*   Updated: 2026/03/31 19:47:11 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

void	init_struct(t_game *game)
{
	ft_memset(game, '\0', sizeof(t_game));
	ft_memset(&game->map, '\0', sizeof(t_game));

}

bool	init(t_game *game, char *filepath)
{
	init_struct(game);
	if (export_map(&game->map, filepath))
		return(false);
	return(true);
}