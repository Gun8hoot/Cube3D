

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

void	draw_square(t_game *game, int pos_y, int pos_x, int len)
{
	int	x;
	int	y;

	y = pos_y;
	while (y < pos_y + len)
	{
		x = pos_x;
		while (x < pos_x + len)
		{
			my_mlx_pixel_put(game, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
	(void)game;
}

void	render_minimap(t_game *game)
{
	// size_t	i;
	// size_t	j;

	// i = 0;
	// while (game->map.grid[i])
	// {
	// 	j = 0;
	// 	while (game->map.grid[j])
	// 	{

	// 	}
	// }
	int i = 0;
	int px = 0;
	while (i < 32)
	{
		draw_square(game, 0, px, PIXEL_PER_TILES);
		px += 8;
	}
	(void)game;
}

void	show_minimap(t_game *game)
{
	draw_box(game, MINIMAP_WIDTH, MINIMAP_HEIGHT, 0x000000);
	int i = 0;
	int px = 0;
	while (i < MINIMAP_WIDTH / PIXEL_PER_TILES)
	{
		draw_square(game, 0, px, PIXEL_PER_TILES);
		px += 8;
		i++;
	}
	// draw_square(game, 25, 25+8, 8);
	;
}
