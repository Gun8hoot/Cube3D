/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 16:41:54 by nclavel           #+#    #+#             */
/*   Updated: 2026/04/13 16:01:46 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

bool	check_extension(char *filepath)
{
	size_t	len;

	len = ft_strlen(filepath) - 1;
	if (!filepath || filepath[0] == '\0')
		return (fprintf(stderr, STR_PATH_ERROR), false);
	if (ft_strncmp(&filepath[len - 3], ".cub", 4) != 0)
		return (fprintf(stderr, FNAME_ERROR, filepath), false);
	return (true);
}

static bool	define_pos(t_map *map, char direction)
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
		while (map->grid[i][j])
		{
			if (map->grid[i][j] == 'N' || map->grid[i][j] == 'E'
				|| map->grid[i][j] == 'S' || map->grid[i][j] == 'W')
			{
				if (!define_pos(map, map->grid[i][j]))
					return (ft_fprintf(STDERR_FILENO, MULT_ERROR), false);
				map->start_pos[0] = i;
				map->start_pos[1] = j;
				map->grid[i][j] = PLAYER;
			}
			j++;
		}
		i++;
	}
	if (map->looking_at[0] == 0.0 && map->looking_at[1] == 0.0)
		return (ft_fprintf(STDERR_FILENO, PLAYER_ERR), false);
	return (true);
}

bool	check_parsing(t_map *map)
{
	if (map->door_num > 0 && (!map->d_texture || !map->d_texture[0]))
		return (fprintf(stderr, MISS_TEXT_ERROR, "DO"), false);
	if (!map->ea_texture)
		return (fprintf(stderr, MISS_TEXT_ERROR, "EA"), false);
	if (!map->no_texture)
		return (fprintf(stderr, MISS_TEXT_ERROR, "NO"), false);
	if (!map->so_texture)
		return (fprintf(stderr, MISS_TEXT_ERROR, "SO"), false);
	if (!map->we_texture)
		return (fprintf(stderr, MISS_TEXT_ERROR, "WE"), false);
	if (!map->c_color)
		return (fprintf(stderr, MISS_TEXT_ERROR, "C"), false);
	if (!map->f_color)
		return (fprintf(stderr, MISS_TEXT_ERROR, "F"), false);
	if (map->number_char_max >= 280 || map->line_number >= 160)
		return (fprintf(stderr, TOO_BIG_ERROR), false);
	return (true);
}
