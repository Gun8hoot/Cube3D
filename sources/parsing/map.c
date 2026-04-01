/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 16:41:56 by nclavel           #+#    #+#             */
/*   Updated: 2026/04/01 17:43:41 by nclavel          ###   ########.fr       */
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

static ssize_t	countline(t_map *map)
{
	char	*line;
	int		fd;

	if (!check_extension(map->filepath))
		return (ft_fprintf(STDERR_FILENO, EXT_ERROR), -1);
	fd = open(map->filepath, O_RDONLY);
	if (fd < 2)
		return (ft_fprintf(STDERR_FILENO, OPEN_ERROR), -1);
	line = get_next_line(fd);
	if (!line)
	{
		ft_fprintf(STDERR_FILENO, ALLOC_ERROR);
		return (ft_fprintf(STDERR_FILENO, ALLOC_ERROR), close(fd), -1);
	}
	while (line)
	{
		free(line);
		map->line_number++;
		line = get_next_line(fd);
	}
	get_next_line(-1);
	close(fd);
	return (map->line_number);
}

void	show_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->line_number)
	{
		printf("%s", map->grid[i]);
		i++;
	}
}

t_map	*init_map(t_map *map, char *filepath)
{
	char	*raw_line;
	size_t	i;
	bool	is_map;

	i = 0;
	is_map = false;
	(void)countline;
	raw_line = NULL;
	map->fd = open(filepath, O_RDONLY);
	if (map->fd < 3)
		return (NULL);
	while (i == 0 || raw_line)
	{
		raw_line = get_next_line(map->fd);
		if (errno == EGNL)
			return (NULL);
		if (is_map_top_bottom(raw_line) || is_map)
		{
			is_map = true;
			printf("%s", raw_line);
		}
		else if (!is_map && !extract_texture_path(map, raw_line))
			return (NULL);
		i++;
	}
	return (map);
}
