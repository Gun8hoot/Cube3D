/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:03:20 by nclavel           #+#    #+#             */
/*   Updated: 2026/04/20 16:03:21 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

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

bool	confirm_is_map(t_map *map, char *raw_line, size_t nb_line)
{
	if (is_map(raw_line))
	{
		map->line_number++;
		map->pos_start_map += nb_line + 1;
		countline(map);
		return (true);
	}
	return (false);
}

t_map	*extract_info(t_map *map)
{
	size_t	i;
	char	*raw_line;

	i = 0;
	raw_line = NULL;
	map->fd = open(map->filepath, O_RDONLY);
	if (map->fd < 3)
		return (fprintf(stderr, OPEN_ERROR, map->filepath), NULL);
	while (i == 0 || raw_line)
	{
		raw_line = get_next_line(map->fd);
		if (errno == EGNL)
			return (NULL);
		if (confirm_is_map(map, raw_line, i))
			break ;
		else if (!extract_texture_path(map, raw_line))
			return (NULL);
		i++;
	}
	safe_free(&raw_line);
	if (map->fd > 2)
		(close(map->fd), map->fd = 0);
	return (map);
}
