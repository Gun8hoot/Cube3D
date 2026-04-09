/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 14:33:17 by thlibers          #+#    #+#             */
/*   Updated: 2026/04/09 18:17:07 by thlibers         ###   ########.fr       */
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

static int	get_texture_color(t_img *r_img, int x, int y)
{
	char	*dst;

	if (x < 0 || x >= r_img->width || y < 0 || y >= r_img->height)
		return (0);
	dst = r_img->addr + (y * r_img->line_length + x * (r_img->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	draw_textured_line(t_game *game, int x, int img_x)
{
	int		y;
	double	step;
	double	tex_pos;
	int		img_y;
	int		color;

	if (!game->img || !game->img->addr)
		return ;
	step = (double)game->img->height / game->render.line_height;
	tex_pos = (game->render.draw_start - HEIGHT / 2 + game->render.line_height / 2) * step;
	y = game->render.draw_start;
	while (y < game->render.draw_end)
	{
		img_y = (int)tex_pos;
		if (img_y < 0)
			img_y = 0;
		if (img_y >= game->img->height)
			img_y = game->img->height - 1;
		tex_pos += step;
		color = get_texture_color(game->img, img_x, img_y);
		my_mlx_pixel_put(game, x, y, color);
		y++;
	}
}

void	get_texture(t_ray *ray, t_game *game)
{
	char	wall_type;

	wall_type = game->map.grid[ray->map_y][ray->map_x];
	if (ray->side == 0)
	{
		if (ray->dir.x > 0)
			game->img = &game->textures[0];
		else
			game->img = &game->textures[1];
	}
	else
	{
		if (ray->dir.y > 0)
			game->img = &game->textures[2];
		else
			game->img = &game->textures[3];
	}
}

int	convert_coords_textures(t_ray *ray, t_game *game)
{
	int		img_x;
	double	wall_x;

	if (!game->img)
		return (0);
	if (ray->side == 0)
		wall_x = game->player.pos_y + ray->perp_wall_dist * ray->dir.y;
	else
		wall_x = game->player.pos_x + ray->perp_wall_dist * ray->dir.x;
	wall_x -= floor(wall_x);
	img_x = (int)(wall_x * (double)game->img->width);
	if (img_x >= game->img->width)
		img_x = game->img->width - 1;
	if (img_x < 0)
		img_x = 0;
	if (ray->side == 0 && ray->dir.x < 0)
		img_x = game->img->width - img_x - 1;
	if (ray->side == 1 && ray->dir.y > 0)
		img_x = game->img->width - img_x - 1;
	return (img_x);
}
