/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 10:45:55 by nclavel           #+#    #+#             */
/*   Updated: 2026/04/07 09:25:13 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

t_identifier	check_info_type(char *info)
{
	if (ft_strncmp(info, "C ", 2) == 0)
		return (C);
	else if (ft_strncmp(info, "F ", 2) == 0)
		return (F);
	else if (ft_strncmp(info, "NO", 2) == 0)
		return (NO);
	else if (ft_strncmp(info, "EA", 2) == 0)
		return (EA);
	else if (ft_strncmp(info, "SO", 2) == 0)
		return (SO);
	else if (ft_strncmp(info, "WE", 2) == 0)
		return (WE);
	else
		return (NONE);
}

bool	get_color(int *color, char *line)
{
	int		shift;
	size_t	i;
	size_t	j;
	char	number[4];
	int		tmp;

	i = 0;
	shift = 16;
	ft_bzero(&number, sizeof(int));
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	while (line[i])
	{
		tmp = 0;
		ft_memset(&number, '\0', sizeof(char) * 4);
		j = 0;
		while (line[i + j] && ft_isdigit(line[i + j]))
			j++;
		if (line[i + j] != ',' && line[i + j] != '\0')
			return (false);
		if (!ft_strlcpy(number, &line[i], j + 1))
			return (ft_fprintf(STDERR_FILENO, CPY_ERROR), false);
		tmp = ft_atoi(number);
		if (tmp < 0 || tmp > 255)
			return (ft_fprintf(STDERR_FILENO, OOB_ERROR), false);
		*color += tmp << shift;
		shift -= 8;
		if (line[i + j] == '\0')
			i += j;
		else
			i += j + 1;
	}
	return (true);
}

bool	set_texture(char **dest, char *src)
{
	if (*dest)
		return (ft_fprintf(STDERR_FILENO, DUPLICAT_ERROR), false);
	*dest = ft_strdup(src);
	if (!dest)
		return (ft_fprintf(STDERR_FILENO, ALLOC_ERROR), false);
	return (true);
}

bool	set_info_texture(t_map *map, char *info_string, t_identifier id)
{
	size_t	i;

	i = 0;
	while (info_string[i] && info_string[i] != ' ')
		i++;
	while (info_string[i] && info_string[i] == ' ')
		i++;
	if (id == NO)
		return (set_texture(&map->NO_texture, &info_string[i]));
	else if (id == EA)
		return (set_texture(&map->EA_texture, &info_string[i]));
	else if (id == SO)
		return (set_texture(&map->SO_texture, &info_string[i]));
	else if (id == WE)
		return (set_texture(&map->WE_texture, &info_string[i]));
	else if (id == C)
		return (get_color(&map->c_color, info_string));
	else if (id == F)
		return (get_color(&map->f_color, info_string));
	return (false);
}

bool	extract_texture_path(t_map *map, char *raw_line)
{
	char			*line;
	t_identifier	id;

	id = 0;
	line = ft_strtrim(raw_line, " \n");
	if (errno == ENOMEM)
		return (false);
	else if ((line && line[0] == '\0') || !line)
		return (free(line),true);
	if (line[0] != '\0')
	{
		id = check_info_type(line);
		if (id == 0 && line[0] != '\0')
			return (free(line), ft_fprintf(STDERR_FILENO, ID_ERROR), false);
		if (!set_info_texture(map, line, id))
			return (free(line), false);
	}
	free(line);
	return (true);
}
