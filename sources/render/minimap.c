

#include "includes/cube3d.h"

bool	minimap_padding(t_game *game, size_t data, size_t inferior_to)
{
	size_t	px_per_line;
	bool	has_modify;

	has_modify = 0;
	while (game->minimap.pixel_per_elem > 0)
	{
		px_per_line = game->minimap.pixel_per_elem * data;
		if (px_per_line >= inferior_to)
		{
			game->minimap.pixel_per_elem--;
			has_modify = 1;
		}
		else
			break;
	}
	if (has_modify == 1)
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
	printf("padding top = %ld ; padding right = %ld\n", game->minimap.padding_top_bottom, game->minimap.padding_right_left);
	return (true);
}

bool	is_wall(t_map map, int ray_x, int ray_y)
{
	if (ray_x < 0 || ray_y == 0 || ray_y >= (int)map.line_number || ray_x >= (int)map.number_char_max)
		return (false);
	return (map.grid[ray_y][ray_x] == '1');
}

void	show_vision(t_game *game)
{
	t_vec	ray;
	(void)game;
	(void)ray;
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
	show_vision(game);
}
