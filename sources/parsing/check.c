/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 16:41:54 by nclavel           #+#    #+#             */
/*   Updated: 2026/04/08 12:29:04 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

bool	define_pos(t_map *map, char direction)
{
	if (map->looking_at[0] != 0.0 || map->looking_at[1] != 0.0)
		return (false);
	if (direction == 'N')
	{
		map->looking_at[0] = -1.0;
		map->looking_at[1] = 0.0;
	}
	else if (direction == 'E')
	{
		map->looking_at[0] = 0.0;
		map->looking_at[1] = 1.0;
	}
	else if (direction == 'S')
	{
		map->looking_at[0] = 1.0;
		map->looking_at[1] = 0.0;
	}
	else if (direction == 'W')
	{
		map->looking_at[0] = 0.0;
		map->looking_at[1] = -1.0;
	}
	return (true);
}

bool	get_player_pos(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map->grid[i])
	{
		j = 0;
		while(map->grid[i][j])
		{
			if (map->grid[i][j] == 'N'
					|| map->grid[i][j] == 'E'
					|| map->grid[i][j] == 'S'
					|| map->grid[i][j] == 'W')
			{
				if (!define_pos(map, map->grid[i][j]))
					return (ft_fprintf(STDERR_FILENO, MULT_PLAYER_ERROR), false);
				map->start_pos[0] = i;
				map->start_pos[1] = j;
				map->grid[i][j] = PLAYER;
			}
			j++;
		}
		i++;
	}
	if (map->looking_at[0] == 0.0 && map->looking_at[1] == 0.0)
		return (ft_fprintf(STDERR_FILENO, "ABC\n"), false);
	return (true);
}

void	init_door(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map->grid[i])
	{
		j = 0;
		while(map->grid[i][j])
		{
			if (map->grid[i][j] == 'D')
			{
				map->grid[i][j] = DOOR_CLOSE;
			}
			j++;
		}
		i++;
	}
}
