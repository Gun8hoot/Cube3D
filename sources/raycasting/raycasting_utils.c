/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 14:33:17 by thlibers          #+#    #+#             */
/*   Updated: 2026/04/01 14:54:24 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

void	ft_dda(t_ray *raycasting, )
{
	
}

void	ray_init()
{
	
}

void	ft_raycasting(t_ray *raycasting)
{
	raycasting->delta_dist_x = fabs(1 / raycasting->ray_dir_x);
	raycasting->delta_dist_y = fabs(1 / raycasting->ray_dir_y);
}