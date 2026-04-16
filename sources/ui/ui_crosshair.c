
#include "includes/cube3d.h"

void	crosshair(t_game *game)
{
	draw_line(game, WIDTH / 2 + CR_PADD_CENTER, HEIGHT / 2, WIDTH / 2 + CR_SIZE,
		HEIGHT / 2);
	draw_line(game, WIDTH / 2 - CR_PADD_CENTER, HEIGHT / 2, WIDTH / 2 - CR_SIZE,
		HEIGHT / 2);
	draw_line(game, WIDTH / 2, HEIGHT / 2 + CR_PADD_CENTER, WIDTH / 2, HEIGHT
		/ 2 + CR_SIZE);
	draw_line(game, WIDTH / 2, HEIGHT / 2 - CR_PADD_CENTER, WIDTH / 2, HEIGHT
		/ 2 - CR_SIZE);
}


void	draw_hitmarker(t_game *game)
{
	draw_line(game, WIDTH / 2 + 10, HEIGHT / 2 + 10, WIDTH / 2 + 15, HEIGHT / 2
		+ 15);
	draw_line(game, WIDTH / 2 + 10, HEIGHT / 2 - 10, WIDTH / 2 + 15, HEIGHT / 2
		- 15);
	draw_line(game, WIDTH / 2 - 10, HEIGHT / 2 + 10, WIDTH / 2 - 15, HEIGHT / 2
		+ 15);
	draw_line(game, WIDTH / 2 - 10, HEIGHT / 2 - 10, WIDTH / 2 - 15, HEIGHT / 2
		- 15);
}

void	hitmarker(t_game *game)
{
	draw_hitmarker(game);
}
