
#include "includes/cube3d.h"

void	show_fps(t_game *game)
{
	struct timeval	curr_frame_time;

	gettimeofday(&curr_frame_time, 0);
	game->fps.delta_fps = (curr_frame_time.tv_sec - game->fps.last_frame_time.tv_sec)
						+ (curr_frame_time.tv_usec - game->fps.last_frame_time.tv_usec)
						/ 1000000.0; // CONVERT TO SEC
	game->fps.last_frame_time = curr_frame_time;
	game->fps.fps_counter++;
	game->fps.fps_timer += game->fps.delta_fps;

	if (game->fps.fps_timer >= 1)
	{
		sprintf(game->fps.string, "FPS: %d",game->fps.fps_counter);
		game->fps.fps_counter = 0;
		game->fps.fps_timer = 0;
	}
	mlx_string_put(game->mlx, game->win, WIDTH - 75, 25, 0xFFFF00, game->fps.string);
}

void	fps_limiter(t_game *game)
{
	double	elapsed;
	struct timespec sleep_time;

	gettimeofday(&game->fps.frame_end, 0);

	elapsed = (game->fps.frame_end.tv_sec - game->fps.frame_start.tv_sec) * 1000000
						+ (game->fps.frame_end.tv_usec - game->fps.frame_start.tv_usec);
	sleep_time.tv_nsec = (FPS_TIME - elapsed) * 1000;
	sleep_time.tv_sec = 0;
	if (sleep_time.tv_nsec > 0)
		nanosleep(&sleep_time, 0);
}
