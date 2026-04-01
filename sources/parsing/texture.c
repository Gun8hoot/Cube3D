/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 10:45:55 by nclavel           #+#    #+#             */
/*   Updated: 2026/04/01 11:53:28 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

t_identifier	check_info_type(char *info)
{
	if (ft_strncmp(info, "C ", 2))
		return (C);
	else if (ft_strncmp(info, "F ", 2))
		return (F);
	else if (ft_strncmp(info, "NO", 2))
		return (NO);
	else if (ft_strncmp(info, "EA", 2))
		return (EA);
	else if (ft_strncmp(info, "SO", 2))
		return (SO);
	else if (ft_strncmp(info, "WE", 2))
		return (WE);
	else
		return (NONE);
}

char	*set_info_texture(t_map *map, char *texture_path, t_identifier id)
{
	size_t	i;

	i = 0;
	while (texture_path[i] != ' ')
		i++;
	while (texture_path[i] == ' ')
		i++;
	if (id == NO)
		return (map->NO_texture = strdup(&texture_path[i]), map->NO_texture);
	else if (id == EA)
		return (map->EA_texture = strdup(&texture_path[i]), map->EA_texture);
	else if (id == SO)
		return (map->SO_texture = strdup(&texture_path[i]), map->SO_texture);
	else if (id == WE)
		return (map->WE_texture = strdup(&texture_path[i]), map->WE_texture);
	return (NULL);
	// else if (id == C)
	// 	return ();
	// else if (id == F)
	// 	return ();
}

bool	extract_texture_path(t_map *map)
{
	size_t			i;
	char			*line;
	t_identifier	id;

	i = 0;
	line = NULL;
	id = 0;
	while (map->grid[i])
	{
		line = ft_strtrim(map->grid[i], " ");
		if (!line)
			return (NULL);
		if (line[0] != '\n')
		{
			id = check_info_type(line);
			if (id == 0)
				return (ft_fprintf(STDERR_FILENO, ID_ERROR), false);
			if (!set_info_texture(map, line, id))
				return (ft_fprintf(STDERR_FILENO, ALLOC_ERROR), free(line),
					false);
		}
		free(line);
		i++;
	}
	return (true);
}
