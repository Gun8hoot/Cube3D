
#include "includes/cube3d.h"

static char	is_door(t_game *game, char **grid)
{
	if (grid[game->ray.map_y][game->ray.map_x] == DOOR_CLOSE)
		return (DOOR_CLOSE);
	else if (grid[game->ray.map_y][game->ray.map_x] == DOOR_OPEN)
		return (DOOR_OPEN);
	return (FLOOR);
}

void	open_door(t_game *game)
{
	double x = game->player.dir_x + game->render.plane.x * ((double)HEIGHT / (double)WIDTH);
	double y = game->player.dir_y + game->render.plane.y * ((double)HEIGHT / (double)WIDTH);

	if (ms_time(NULL) - timeval_to_ms(game->player.door.start, NULL) < 400)
		return;
	if (is_door(game, game->map.grid) == DOOR_CLOSE)
		game->map.grid[(int)(game->player.pos_y + y)][(int)(game->player.pos_y + x)] = DOOR_OPEN;
	else if (is_door(game, game->map.grid) == DOOR_OPEN)
		game->map.grid[(int)(game->player.pos_y + y)][(int)(game->player.pos_y + x)] = DOOR_CLOSE;
	gettimeofday(&game->player.door.start, 0);
}
