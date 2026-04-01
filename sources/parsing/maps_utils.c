/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 17:25:46 by nclavel           #+#    #+#             */
/*   Updated: 2026/04/01 17:40:50 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

bool	is_map_top_bottom(char *line)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(line);
	if (!line || line[i] == '\n')
		return (false);
	while (line && (line[i] == ' ' || line[i] == '1'))
		i++;
	if (i + 1 != len)
		return (false);
	else
		return (true);
}