/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 14:33:17 by thlibers          #+#    #+#             */
/*   Updated: 2026/04/09 17:19:18 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

void	line_height(t_render *render, t_ray ray)
{
	int h = (int)HEIGHT;
    render->line_height = (int)(h / ray.perp_wall_dist);
    render->draw_start = -render->line_height / 2 + h / 2;
    if(render->draw_start < 0)
		render->draw_start = 0;
    render->draw_end = render->line_height / 2 + h / 2;
    if(render->draw_end >= h)
		render->draw_end = h - 1;
}

// int	get_texture_color(t_img *img, int x, int y)
// {
// 	char	*dst;

// 	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
// 		return (0);
// 	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
// 	return (*(unsigned int *)dst);
// }

