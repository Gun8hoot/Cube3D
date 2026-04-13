/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 10:23:11 by nclavel           #+#    #+#             */
/*   Updated: 2026/04/13 16:48:21 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

static void	ui(t_game *game)
{
	weapon(game);
	show_minimap(game);
	crosshair(game);
	show_fps(game);
	bullet_nb(game);
	mouse(game);
	// hitmarker(game);
}

static int	game_loop(t_game *game)
{
	gettimeofday(&game->fps.frame_start, 0);
	chose_action(game);
	animating_weapon(game);
	celling_floor(game);
	ft_rayshooter(&game->ray, game);
	mlx_put_image_to_window(game->mlx, game->win, game->r_img.img, 0, 0);
	ui(game);
	fps_limiter(game);
	return (0);
}

static void	ft_hooks(t_game *game)
{
	mlx_mouse_hook(game->win, weapon_gunfire, game);
	mlx_hook(game->win, 17, 0, handle_close, game);
	mlx_hook(game->win, 2, 1L << 0, handle_key_press, game);
	mlx_hook(game->win, 3, 1L << 1, handle_key_release, game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_fprintf(STDERR_FILENO, ARG_ERROR), 1);
	if (!init(&game, argv[1]))
		return (1);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT, "Cube3D");
	game.r_img.img = mlx_new_image(game.mlx, WIDTH, HEIGHT);
	game.r_img.addr = mlx_get_data_addr(game.r_img.img,
			&game.r_img.bits_per_pixel, &game.r_img.line_length,
			&game.r_img.endian);
	game.w_img.img = mlx_xpm_file_to_image(game.mlx, "textures/weapon.xpm",
			&game.w_img.width, &game.w_img.height);
	if (!game.w_img.img)
		return (ft_fprintf(2, "Error: Impossible de charger weapon.xpm\n"), 1);
	game.w_img.addr = mlx_get_data_addr(game.w_img.img,
			&game.w_img.bits_per_pixel, &game.w_img.line_length,
			&game.w_img.endian);
	load_textures(&game);
	if (!calculate_minimap(&game))
		return (ft_fprintf(2, TOO_BIG_ERROR), false);
	ft_hooks(&game);
	return (0);
}
