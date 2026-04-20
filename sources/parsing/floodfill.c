/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:03:43 by nclavel           #+#    #+#             */
/*   Updated: 2026/04/20 16:03:44 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

bool	arr_copy(t_map *map)
{
	size_t	y;

	y = 0;
	if (!map->grid)
		return (false);
	map->flood_filled = ft_calloc(map->line_number, sizeof(char *));
	if (!map->flood_filled)
		return (false);
	while (y < map->line_number)
	{
		map->flood_filled[y] = ft_strdup(map->grid[y]);
		if (!map->flood_filled[y])
			return (false);
		y++;
	}
	map->flood_filled[y] = NULL;
	return (true);
}

bool	check_floodfill(size_t x, size_t y, t_map *map)
{
	if (!map->flood_filled[y] || !map->flood_filled[y][x])
		return (false);
	if ((x <= 0 && map->flood_filled[y][x] != '1')
			|| (y <= 0 && map->flood_filled[y][x] != '1')
			|| (x >= map->number_char_max - 1 && map->flood_filled[y][x] != '1')
			|| (y >= map->line_number - 1 && map->flood_filled[y][x] != '1'))
		return (false);
	return (true);
}

bool	floodfill(size_t x, size_t y, t_map *map, char c)
{
	if (!check_floodfill(x, y, map))
		return (false);
	if (map->flood_filled[y][x] == '1' || map->flood_filled[y][x] == 'F')
		return (true);
	if (!map->flood_filled[y][x + 1] || (map->flood_filled[y][x + 1] == ' '))
		return (false);
	if (!map->flood_filled[y][x - 1] || (map->flood_filled[y][x - 1] == ' '))
		return (false);
	if (!map->flood_filled[y - 1][x] || (map->flood_filled[y - 1][x] == ' '))
		return (false);
	if (!map->flood_filled[y + 1][x] || (map->flood_filled[y + 1][x] == ' '))
		return (false);
	map->flood_filled[y][x] = c;

	if (!floodfill(x, y - 1, map, c))
		return (false);
	if (!floodfill(x, y + 1, map, c))
		return (false);
	if (!floodfill(x - 1, y, map, c))
		return (false);
	if (!floodfill(x + 1, y, map, c))
		return (false);
	return (true);
}
