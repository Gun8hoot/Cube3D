/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 14:33:17 by thlibers          #+#    #+#             */
/*   Updated: 2026/04/02 11:45:26 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

void	ft_dda(t_ray *ray, t_game game)
{
    if (ray->ray_dir.x < 0)
    {
      ray->step.x = -1;
      ray->side_dist.x = (game.player.pos_x - ray->map_x) * ray->delta_dist.x;
    }
    else
    {
      ray->step.x = 1;
      ray->side_dist.x = (ray->map_x + 1.0 - game.player.pos_x) * ray->delta_dist.x;
    }
    if (ray->ray_dir.y < 0)
    {
      ray->step.y = -1;
      ray->side_dist.y = (game.player.pos_y - ray->map_y) * ray->delta_dist.y;
    }
    else
    {
      ray->step.y = 1;
      ray->side_dist.y = (ray->map_y + 1.0 - game.player.pos_y) * ray->delta_dist.y;
    }
}

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

void	choose_color()
{
	// //choose wall color
    //   ColorRGB color;
    //   switch(worldMap[mapX][mapY])
    //   {
    //     case 1:  color = RGB_Red;  break; //red
    //     case 2:  color = RGB_Green;  break; //green
    //     case 3:  color = RGB_Blue;   break; //blue
    //     case 4:  color = RGB_White;  break; //white
    //     default: color = RGB_Yellow; break; //yellow
    //   }

    //   //give x and y sides different brightness
    //   if (side == 1) {color = color / 2;}

    //   //draw the pixels of the stripe as a vertical line
    //   verLine(x, drawStart, drawEnd, color);
    // }
}

void	calculate_fps(t_render *render, double *movespeed, double *rotspeed)
{
	double frametime;
	
    frametime = (render->time - render->oldtime) / 1000.0;
	if (frametime > 0)
	{
		*movespeed = frametime * 5.0; //the constant value is in squares/second
    	*rotspeed = frametime * 3.0; //the constant value is in radians/second
	}
	render->oldtime = render->time;
}
