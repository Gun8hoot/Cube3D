#include "includes/cube3d.h"

void	draw_box(t_game *game, int max_x, int max_y, int color, int pad)
{
	int	x;
	int	y;

	y = pad;
	while (y < max_y)
	{
		x = pad;
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

void draw_line(t_game *game, int x0, int y0, int x1, int y1)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        mlx_pixel_put(game->mlx, game->win, x0, y0, 0xFF0000);  // Red line

        if (x0 == x1 && y0 == y1)
            break;

        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}
