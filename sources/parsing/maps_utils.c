/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 17:25:46 by nclavel           #+#    #+#             */
/*   Updated: 2026/04/02 16:51:54 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

bool	is_map(char *line)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(line);
	if (!line || line[i] == '\n')
		return (false);
	while (line && (line[i] == ' ' || line[i] == '0' || line[i] == '1'
			|| line[i] == 'D' || line[i] == 'N' || line[i] == 'E'
			|| line[i] == 'S' || line[i] == 'W'))
		i++;
	if (i + 1 != len)
		return (false);
	else
		return (true);
}

char **cpy_map(t_map *map, char **dest, char **src)
{
	size_t	i;

	i = 0;
	if (!src || dest)
	{
		fprintf(stderr, CPY_ERROR);
		return (NULL);
	}
	dest = ft_calloc(map->line_number + 1, sizeof(char *));
	if (!dest)
		return (fprintf(stderr, ALLOC_ERROR), NULL);
	while (src[i])
	{
		dest[i] = ft_strdup(src[i]);
		if (!dest[i])
		{
			free_tab(&dest, 0);
			return (fprintf(stderr, ALLOC_ERROR), NULL);
		}
		i++;
	}
	return (dest);
}
