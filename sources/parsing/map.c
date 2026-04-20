/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 16:41:56 by nclavel           #+#    #+#             */
/*   Updated: 2026/04/17 18:36:02 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

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
