/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 09:59:56 by nclavel           #+#    #+#             */
/*   Updated: 2026/04/09 15:25:11 by thlibers         ###   ########.fr       */
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
	if (map->no_texture)
		(free(map->no_texture), map->no_texture = NULL);
	if (map->ea_texture)
		(free(map->ea_texture), map->ea_texture = NULL);
	if (map->so_texture)
		(free(map->so_texture), map->so_texture = NULL);
	if (map->we_texture)
		safe_free(&map->we_texture);
	if (map->fd > 2)
		(get_next_line(-1), close(map->fd), map->fd = 0);
	if (map->grid)
		free_tab(&map->grid, map->line_number);
}

void	clear_game(t_game *game)
{
	clear_t_map(&game->map);
}
