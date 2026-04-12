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

bool	check_floodfill(char **grid)
{
	size_t x;
	size_t y;

	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] != ' '
				&& grid[y][x] != 'F'
				&& grid[y][x] != '1')
			{
				return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}

void	floodfill(size_t x, size_t y, t_map *map)
{
	if (	x < 0
			|| x >= ft_strlen(map->flood_filled[y])
			|| y < 0
			|| y >= map->line_number
			|| map->flood_filled[y][x] == '1'
			|| map->flood_filled[y][x] == 'F')
	{
		return;
	}
	map->flood_filled[y][x] = 'F';
	floodfill(x, y - 1, map);
	floodfill(x, y + 1, map);
	floodfill(x - 1, y, map);
	floodfill(x + 1, y, map);
}

// void	check_side_border(t_game *game, t_vec vec, bool *reach_end, int ope)
// {
// 	if (vec.x == game->map.number_char_max)
// 		return;
// 	if (vec.y == game->map.line_number)
// 	{
// 		*reach_end = true;
// 		return;
// 	}
// 	if (game->map.grid[(int)vec.y + ope][(int)vec.x])
// 	{

// 	}
// }
