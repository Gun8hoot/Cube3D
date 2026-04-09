/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 17:06:12 by thlibers          #+#    #+#             */
/*   Updated: 2026/04/09 17:24:18 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->r_img.addr + (y * game->r_img.line_length) + (x * (game->r_img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
