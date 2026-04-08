

#include "includes/cube3d.h"

void	draw_box(t_game *game, int max_x, int max_y, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < max_y)
	{
		x = 0;
		while (x < max_x)
		{
			my_mlx_pixel_put(game, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_square(t_game *game, int pos_y, int pos_x, int len, int color)
{
	int	x;
	int	y;

	y = pos_y;
	while (y < pos_y + len)
	{
		x = pos_x;
		while (x < pos_x + len)
		{
			my_mlx_pixel_put(game, x, y, color);
			x++;
		}
		y++;
	}
	(void)game;
}

bool	calculate_minimap(t_game *game)
{
	size_t	px_per_line;

	game->minimap.pixel_per_elem = 8;
	while (game->minimap.pixel_per_elem > 0)
	{
		px_per_line = game->minimap.pixel_per_elem * game->map.number_char_max;
		if (px_per_line > MINIMAP_WIDTH)
			game->minimap.pixel_per_elem--;
		else
			break;
	}
	if (game->minimap.pixel_per_elem == 0)
		return (false);
	game->minimap.padding_right_left = (MINIMAP_WIDTH - px_per_line) / 2;

	while (game->minimap.pixel_per_elem > 0)
	{
		px_per_line = game->minimap.pixel_per_elem * game->map.line_number;
		if (px_per_line > MINIMAP_HEIGHT)
			game->minimap.pixel_per_elem--;
		else
			break;
	}
	if (game->minimap.pixel_per_elem == 0)
		return (false);
	game->minimap.padding_top_bottom = (MINIMAP_HEIGHT - px_per_line) / 2;
	return (true);
}

void	render_minimap(t_game *game)
{
	(void)game;
}

void	show_minimap(t_game *game)
{
	calculate_minimap(game);
	draw_box(game, MINIMAP_WIDTH, MINIMAP_HEIGHT, 0x000000);
	size_t py = game->minimap.padding_top_bottom;

	for (size_t y = 0; game->map.grid[y]; y++)
	{
		size_t px = game->minimap.padding_right_left;

		for (size_t x = 0; game->map.grid[y][x]; x++)
		{
			if (game->map.grid[y][x] == WALL)
				draw_square(game, py, px, 8, 0x00FF00);
			else if (game->map.grid[y][x] == PLAYER)
				draw_square(game, py, px, 8, 0xFF0000);

			px += 8;
		}
		py += 8;
	}
}
