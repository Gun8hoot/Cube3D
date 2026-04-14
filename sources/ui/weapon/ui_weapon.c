
#include "includes/cube3d.h"

static void	reloading_msg(t_game *game)
{
	static struct timeval	time = {0};

	if (game->weapon.cannot_shoot)
	{
		if (ms_time(NULL) - timeval_to_ms(time, 0) < 500)
		{
			mlx_string_put(game->mlx, game->win, (WIDTH / 2) - 50, (HEIGHT / 2) + 200,
				B_RED, "Press R to reload");
		}
		else if (ms_time(NULL) - timeval_to_ms(time, 0) > 1000)
			gettimeofday(&time, 0);
		return ;
	}
}

void	weapon_reload(t_game *game)
{
	// game->weapon.is_reloading = true;	// Need to handle it on the weapon animation function
	game->weapon.cannot_shoot = false;
	game->weapon.remaining_bullet = MAX_AMMO_NUM;
}

void	bullet_nb(t_game *game)
{
	char	string[27];

	if (game->weapon.is_reloading == false)
	{
		sprintf(string, "Ammo %d/%d", (u_int32_t)game->weapon.remaining_bullet,
			(u_int32_t)MAX_AMMO_NUM);
		mlx_string_put(game->mlx, game->win, WIDTH - 150, HEIGHT - 50, B_WHITE,
			string);
	}
	else
	{
		sprintf(string, "Ammo .../%d", (u_int32_t)MAX_AMMO_NUM);
		mlx_string_put(game->mlx, game->win, WIDTH - 150, HEIGHT - 50, B_WHITE,
			string);
	}
	if (game->weapon.remaining_bullet == 0)
		reloading_msg(game);
}

void	shoot(t_game *game)
{
	t_ray	ray;
	double	camera;

	camera = (double)HEIGHT / (double)WIDTH;
	ray.ray_dir.x = game->player.dir_x * camera;
	ray.ray_dir.y = game->player.dir_y * camera;
	ray.map_x = (int)game->player.pos_x;
	ray.map_y = (int)game->player.pos_y;
	ray.delta_dist.x = fabs(1.0 / ray.ray_dir.x);
	ray.delta_dist.y = fabs(1.0 / ray.ray_dir.y);
	ft_dda(&ray, game);
	check_hit(&ray, game);
	if (ray.hit == 1)
	{
		if (game->map.grid[ray.map_y][ray.map_x] == 'C')
			game->map.grid[ray.map_y][ray.map_x] = '0';
	}
}

int	weapon_gunfire(int keycode, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (keycode == 1)
	{
		if (game->weapon.remaining_bullet > 0)
		{
			game->weapon.remaining_bullet--;
			hitmarker(game);
			shoot(game);
		}
		if (game->weapon.remaining_bullet == 0
			&& game->weapon.cannot_shoot == false)
			game->weapon.cannot_shoot = true;
	}
	return (0);
}
