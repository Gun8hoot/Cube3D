/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 09:59:56 by nclavel           #+#    #+#             */
/*   Updated: 2026/04/01 11:55:24 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

void	free_tab(char ***tab, ssize_t size)
{
	ssize_t	i;

	i = 0;
	if (size < 0)
	{
		while (*tab[i])
		{
			if (*tab[i])
				(free(*tab[i]), *tab[i] = NULL);
		}
		if (*tab)
			(free(*tab), *tab = NULL);
	}
	else
	{
		while (i < size - 1)
		{
			if (*tab[i])
				(free(*tab[i]), *tab[i] = NULL);
		}
		if (*tab)
			(free(*tab), *tab = NULL);
	}
}

void	clear_game(t_game *game)
{
	(void)game;
}
