/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 18:22:31 by thlibers          #+#    #+#             */
/*   Updated: 2026/04/17 18:23:04 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

void	free_tab(char ***tab, ssize_t size)
{
	ssize_t	i;

	i = 0;
	if (size <= 0)
	{
		while ((*tab)[i])
		{
			if ((*tab)[i])
				(free((*tab)[i]), (*tab)[i] = NULL);
			i++;
		}
		if (*tab)
			(free(*tab), *tab = NULL);
	}
	else
	{
		while (i < size)
		{
			if ((*tab)[i])
				(free((*tab)[i]), (*tab)[i] = NULL);
			i++;
		}
		if (*tab)
			(free(*tab), *tab = NULL);
	}
}
