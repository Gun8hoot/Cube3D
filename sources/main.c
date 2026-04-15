/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
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
	mlx_hook(game->win, 17, 0, clear_game, game);
	mlx_hook(game->win, 2, 1L << 0, handle_key_press, game);
	mlx_hook(game->win, 3, 1L << 1, handle_key_release, game);
	game->loop_started = true;
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
	ft_hooks(&game);
	return (0);
}
