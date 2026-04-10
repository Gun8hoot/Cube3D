

#include "includes/cube3d.h"

bool	minimap_padding(t_game *game, size_t data, size_t inferior_to)
{
	size_t	px_per_line;
	bool	has_modify;

	has_modify = false;
	while (game->minimap.pixel_per_elem > 0)
	{
		px_per_line = game->minimap.pixel_per_elem * data;
		if (px_per_line >= inferior_to - INBOX_PADD)
		{
			game->minimap.pixel_per_elem--;
			has_modify = true;
		}
		else
			break;
	}
	if (has_modify == true)
		return (false);
	if (inferior_to == MINIMAP_WIDTH)
		game->minimap.padding_right_left = (MINIMAP_WIDTH - px_per_line) / 2;
	else
		game->minimap.padding_top_bottom = (MINIMAP_HEIGHT - px_per_line) / 2;
	return (true);
}

bool	calculate_minimap(t_game *game)
{
	game->minimap.pixel_per_elem = DEFAULT_ELEM_SIZE;
	while (game->minimap.pixel_per_elem > 0)
	{
		if (!minimap_padding(game, game->map.line_number, MINIMAP_HEIGHT))
			continue ;
		if (!minimap_padding(game, game->map.number_char_max, MINIMAP_WIDTH))
			continue ;
		break ;
	}
	if (game->minimap.pixel_per_elem == 0)
		return (false);
	return (true);
}

void	show_vision(t_game *game, int height, int width)
{
	t_ray	ray;
	double	camera;
	double	hit_x;
	double	hit_y;

	camera = (double)height / (double)width;						
	ray.ray_dir.x = game->player.dir_x + game->render.plane.x * camera;
	ray.ray_dir.y = game->player.dir_y + game->render.plane.y * camera;
	ray.map_x = (int)game->player.pos_x;
    ray.map_y = (int)game->player.pos_y;
    ray.delta_dist.x = fabs(1.0 / ray.ray_dir.x);
    ray.delta_dist.y = fabs(1.0 / ray.ray_dir.y);
    ft_dda(&ray, game);
    check_hit(&ray, game);
    if (ray.hit == 1)
    {
    	hit_x = game->player.pos_x + ray.perp_wall_dist * ray.ray_dir.x;
    	hit_y = game->player.pos_y + ray.perp_wall_dist * ray.ray_dir.y;
   		draw_line(game, game->minimap.padding_right_left + 4 + game->minimap.pixel_per_elem/2 + (int)game->player.pos_x * game->minimap.pixel_per_elem,
     					game->minimap.padding_top_bottom + 4 + game->minimap.pixel_per_elem/2 +  (int)game->player.pos_y * game->minimap.pixel_per_elem,
          				game->minimap.padding_right_left + 4 + hit_x * game->minimap.pixel_per_elem,
              			game->minimap.padding_top_bottom + 4 + hit_y * game->minimap.pixel_per_elem);
    }
}

void	show_minimap(t_game *game)
{
	draw_box(game, MINIMAP_WIDTH + 4, MINIMAP_HEIGHT + 4, 0xFFFFFF, 4);
	draw_box(game, MINIMAP_WIDTH, MINIMAP_HEIGHT, 0x202020, 8);

	double py = game->minimap.padding_top_bottom + 4;

	for (double y = 0; game->map.grid[(size_t)y]; y++)
	{
		double px = game->minimap.padding_right_left + 4;

		for (double x = 0; game->map.grid[(size_t)y][(size_t)x]; x++)
		{
			if (game->map.grid[(size_t)y][(size_t)x] == WALL)
				draw_square(game, py, px, game->minimap.pixel_per_elem, 0x00FF00);
			else if (game->map.grid[(size_t)y][(size_t)x] == PLAYER)
				draw_square(game, py, px, game->minimap.pixel_per_elem, 0xFF0000);
			else if (game->map.grid[(size_t)y][(size_t)x] == DOOR_CLOSE || game->map.grid[(size_t)y][(size_t)x] == DOOR_OPEN)
				draw_square(game, py, px, game->minimap.pixel_per_elem, 0xFFFF00);
			px += game->minimap.pixel_per_elem;
		}
		py += game->minimap.pixel_per_elem;
	}
	show_vision(game, HEIGHT, WIDTH);
}
