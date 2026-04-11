
#include "includes/cube3d.h"

void	ui_reloading_msg(t_game *game)
{
	if (game->weapon.cannot_shoot)
	{
		mlx_string_put(game->mlx, game->win, (WIDTH / 2) - 50, (HEIGHT / 2) + 200,
			B_RED, "Press R to reload");
	}
}

void	ui_weapon_reload(t_game *game)
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
		sprintf(string, "Ammo %d/%d", (u_int32_t)game->weapon.remaining_bullet, (u_int32_t)MAX_AMMO_NUM);
		mlx_string_put(game->mlx, game->win, WIDTH - 150, HEIGHT - 50,
			B_WHITE, string);
	}
	else
	{
		sprintf(string, "Ammo .../%d", (u_int32_t)MAX_AMMO_NUM);
		mlx_string_put(game->mlx, game->win, WIDTH - 150, HEIGHT - 50,
			B_WHITE, string);
	}
	if (game->weapon.remaining_bullet == 0)
		ui_reloading_msg(game);
}

int	ui_weapon_gunfire(int keycode, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (keycode == 1)
	{
		if (game->weapon.remaining_bullet > 0)
			game->weapon.remaining_bullet--;
		if (game->weapon.remaining_bullet == 0 && game->weapon.cannot_shoot == false)
			game->weapon.cannot_shoot = true;
	}
	return (0);
}
