
#include "includes/cube3d.h"

static char	is_door(char **grid, int x, int y)
{
	if (grid[y][x] == DOOR_CLOSE)
		return (DOOR_CLOSE);
	else if (grid[y][x] == DOOR_OPEN)
		return (DOOR_OPEN);
	return (FLOOR);
}

void	open_door(t_game *game)
{
	int	angle_x = (int)round(game->player.dir_x);
	int	angle_y = (int)round(game->player.dir_y);
	int	look_pos[2];

	if (ms_time(NULL) - timeval_to_ms(game->player.door.start, NULL) < 200)
		return;
	look_pos[0] = (int)(game->player.pos_y + angle_y);
	look_pos[1] = (int)(game->player.pos_x + angle_x);
	if (is_door(game->map.grid, look_pos[1], look_pos[0]) == DOOR_CLOSE)
		game->map.grid[look_pos[0]][look_pos[1]] = DOOR_OPEN;
	else if (is_door(game->map.grid, look_pos[1], look_pos[0]) == DOOR_OPEN)
		game->map.grid[look_pos[0]][look_pos[1]] = DOOR_CLOSE;
	gettimeofday(&game->player.door.start, 0);
}
