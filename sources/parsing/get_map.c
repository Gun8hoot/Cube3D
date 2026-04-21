/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:03:28 by nclavel           #+#    #+#             */
/*   Updated: 2026/04/20 16:03:31 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

static char	**init_extract_map(t_map *map)
{
	char	*raw_line;
	size_t	i;

	i = 0;
	map->fd = open(map->filepath, O_RDONLY);
	if (map->fd < 3)
		return (fprintf(stderr, OPEN_ERROR, map->filepath), NULL);
	map->grid = ft_calloc(map->line_number + 1, sizeof(char *));
	if (!map->grid)
		return (NULL);
	while (i < map->pos_start_map - 1)
	{
		raw_line = get_next_line(map->fd);
		if (errno == EGNL)
			return (fprintf(stderr, ALLOC_ERROR), NULL);
		if (!raw_line)
			return (fprintf(stderr, MISS_MAP_ERROR, map->filepath),
				safe_free(&raw_line), NULL);
		safe_free(&raw_line);
		i++;
	}
	return (map->grid);
}

static bool	append_line(t_map *map, char **raw_line, size_t *i)
{
	map->grid[*i] = ft_strtrim(*raw_line, "\n");
	if (!map->grid[*i])
		return (safe_free(raw_line), false);
	if (map->number_char_max < ft_strlen(map->grid[*i]))
		map->number_char_max = ft_strlen(map->grid[*i]);
	(*i)++;
	return (true);
}

char	**extract_map(t_map *map)
{
	size_t	i;
	char	*raw_line;

	i = 0;
	if (!init_extract_map(map))
		return (NULL);
	while (i <= map->line_number)
	{
		raw_line = get_next_line(map->fd);
		if (errno == EGNL)
			return (NULL);
		if (raw_line && raw_line[0] != '\0' && raw_line[0] != '\n')
		{
			if (!append_line(map, &raw_line, &i))
				return (NULL);
		}
		else
		{
			safe_free(&raw_line);
			map->grid[i] = NULL;
			break ;
		}
	}
	return (map->grid);
}
