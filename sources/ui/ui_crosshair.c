
#include "includes/cube3d.h"

void	crosshair(t_game *game)
{
	draw_line(game, WIDTH / 2 + CR_PADD_CENTER, HEIGHT /2,
					WIDTH /2 + CR_SIZE, HEIGHT / 2);
	draw_line(game, WIDTH / 2 - CR_PADD_CENTER, HEIGHT /2,
					WIDTH /2 - CR_SIZE, HEIGHT / 2);
	draw_line(game, WIDTH / 2, HEIGHT /2 + CR_PADD_CENTER,
					WIDTH /2 , HEIGHT / 2 + CR_SIZE);
	draw_line(game, WIDTH / 2, HEIGHT /2 - CR_PADD_CENTER,
					WIDTH /2 , HEIGHT / 2 - CR_SIZE);
}
