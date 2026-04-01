/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 16:41:56 by nclavel           #+#    #+#             */
/*   Updated: 2026/04/01 12:01:55 by nclavel          ###   ########.fr       */
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
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
}

char	**export_map(t_map *map, char *filepath)
{
	int16_t	fd;
	size_t	i;
	char	*line;

	i = 0;
	line = NULL;
	map->filepath = filepath;
	if (countline(map) == -1)
		return (NULL);
	fd = open(filepath, O_RDONLY);
	if (fd < 3)
		return (NULL);
	map->grid = ft_calloc(map->line_number, sizeof(char *));
	if (!map->grid)
		return (ft_fprintf(STDERR_FILENO, ALLOC_ERROR), close(fd), NULL);
	while (i == 0 || line)
	{
		line = get_next_line(fd);
		if (errno == EGNL)
			return (NULL);
		map->grid[i] = line;
		i++;
	}
	show_map(map);
	return (map->grid);
}
