/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 09:59:56 by nclavel           #+#    #+#             */
/*   Updated: 2026/04/02 17:32:03 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

void	free_tab(char ***tab, ssize_t size)
{
	ssize_t	i;

	i = 0;
	if (size < 0)
	{
		while ((*tab)[i])
		{
			if ((*tab)[i])
				(free((*tab)[i]), (*tab)[i] = NULL);
			i++;
		}
		if (*tab)
			(free(*tab), *tab = NULL);
	}
	else
	{
		while (i < size)
		{
			if ((*tab)[i])
				(free((*tab)[i]), (*tab)[i] = NULL);
			i++;
		}
		if (*tab)
			(free(*tab), *tab = NULL);
	}
}

void	safe_free(char **to_free)
{
	if (*(char **)to_free)
	{
		free(*(char **)to_free);
		*(char **)to_free = NULL;
	}
}

void	clear_t_map(t_map *map)
{
	if (map->NO_texture)
		(free(map->NO_texture), map->NO_texture = NULL);
	if (map->EA_texture)
		(free(map->EA_texture), map->EA_texture = NULL);
	if (map->SO_texture)
		(free(map->SO_texture), map->SO_texture = NULL);
	if (map->WE_texture)
		safe_free(&map->WE_texture);
	if (map->fd > 2)
		(get_next_line(-1), close(map->fd), map->fd = 0);
	if (map->grid)
		free_tab(&map->grid, map->line_number);
}

void	clear_game(t_game *game)
{
	clear_t_map(&game->map);
}
