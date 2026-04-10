
#include "includes/cube3d.h"

void	crosshair(t_game *game)
{
	draw_line(game, WIDTH / 2 + 110, HEIGHT /2, WIDTH /2 + 130, HEIGHT / 2);
	draw_line(game, WIDTH / 2 - 110, HEIGHT /2, WIDTH /2 - 130, HEIGHT / 2);
	draw_line(game, WIDTH / 2, HEIGHT /2 + 110, WIDTH /2 , HEIGHT / 2 + 130);
	draw_line(game, WIDTH / 2, HEIGHT /2 - 110, WIDTH /2 , HEIGHT / 2 - 130);
}
