/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 16:41:56 by nclavel           #+#    #+#             */
/*   Updated: 2026/04/08 12:33:33 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

bool	check_extension(char *filepath)
{
	size_t	len;

	len = ft_strlen(filepath) - 1;
	if (!filepath || filepath[0] == '\0')
		return (false);
	if (ft_strncmp(&filepath[len - 3], ".cub", 4) != 0)
		return (false);
	return (true);
}

char	*save_line(char **raw_line)
{
	char	*line;
	char	*ret_line;

	line = NULL;
	ret_line = NULL;
	line = ft_strtrim(*raw_line, "\n");
	if (!line || line[0] == '\0')
		return (NULL);
	raw_line = NULL;
	ret_line = ft_strdup(line);
	if (!ret_line)
		return (NULL);
	return (ret_line);
}

ssize_t	countline(t_map *map)
{
	char	*line;

	line = get_next_line(map->fd);
	if (!line)
		return (0);
	while (line && line[0] != '\n')
	{
		if (line)
			free(line);
		map->line_number++;
		line = get_next_line(map->fd);
		if (errno == EGNL)
			return (-1);
	}
	return (map->line_number);
}

t_map	*extract_info(t_map *map)
{
	size_t	i;
	char	*raw_line;

	i = 0;
	map->fd = open(map->filepath, O_RDONLY);
	if (map->fd < 3)
		return (NULL);
	while (i == 0 || raw_line)
	{
		raw_line = get_next_line(map->fd);
		if (errno == EGNL)
			return (NULL);
		if (is_map(raw_line))
		{
			map->line_number++;
			map->pos_start_map += i + 1;
			countline(map);
			break ;
		}
		else if (!extract_texture_path(map, raw_line))
			return (NULL);
		i++;
	}
	safe_free(&raw_line);
	if (map->fd > 2)
		(close(map->fd), map->fd = 0);
	return (map);
}

char **extract_map(t_map *map)
{
	size_t	i;
	char	*raw_line;

	i = -1;
	raw_line = NULL;
	map->grid = ft_calloc(map->line_number + 1, sizeof(char *));
	if (!map->grid)
		return (NULL);
	map->fd = open(map->filepath, O_RDONLY);
	if (map->fd < 3)
		return (NULL);
	while (++i < map->pos_start_map - 1)
	{
		raw_line = get_next_line(map->fd);
		safe_free(&raw_line);
	}
	i = 0;
	while (i <= map->line_number)
	{
		raw_line = get_next_line(map->fd);
		if (errno == EGNL)
			return (NULL);
		if (raw_line && raw_line[0] != '\0')
		{
			map->grid[i] = ft_strtrim(raw_line, "\n");
			if (!map->grid[i])
				return (NULL);
			if (map->number_char_max < ft_strlen(map->grid[i]))
				map->number_char_max = ft_strlen(map->grid[i]);
			i++;
		}
		else
			break ;
	}
	return (map->grid);
}

t_map	*init_map(t_map *map, char *filepath)
{
	map->filepath = filepath;

	if (!extract_info(map))
		return (NULL);
	if (!extract_map(map))
		return (NULL);
	if (!get_player_pos(map))
		return (NULL);

	return (map);
}
