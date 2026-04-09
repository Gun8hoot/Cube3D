
#include "includes/cube3d.h"

void	show_fps(t_game *game)
{
	struct timeval	end;
	long long		timestamp;

	if (game->old_time > 0)
	{

	}
	gettimeofday(&end, 0);
	timestamp = (end.tv_sec * 1000 + end.tv_sec / 1000);
	game->old_time = timestamp;
}
