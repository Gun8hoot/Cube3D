
#include "includes/cube3d.h"

void	reloading_anim(t_game *game)
{
	static struct timeval	time_last_frame = {0};
	static int				frame = 0;

	if (ms_time(NULL) - timeval_to_ms(time_last_frame, NULL) < 300)
		return ;
	gettimeofday(&time_last_frame, NULL);
	if (frame < 6)
		game->w_img = &game->weapon.reload[frame++];
	else
	{
		game->weapon.is_reloading = false;
		frame = 0;
	}
}

void	shooting_anim(t_game *game)
{
	static struct timeval	time_last_frame = {0};
	static int				frame = 0;


	hitmarker(game);
	if (ms_time(NULL) - timeval_to_ms(time_last_frame, NULL) < 200)
		return ;
	gettimeofday(&time_last_frame, NULL);
	if (frame < 6)
		game->w_img = &game->weapon.fire[frame++];
	else
	{
		game->weapon.is_shooting = false;
		frame = 0;
	}
}
