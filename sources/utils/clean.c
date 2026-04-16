/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 09:59:56 by nclavel           #+#    #+#             */
/*   Updated: 2026/04/13 15:50:30 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

void	safe_free(char **to_free)
{
	if (*(char **)to_free)
	{
		free(*(char **)to_free);
		*(char **)to_free = NULL;
	}
}

void	free_tab(char ***tab, ssize_t size)
{
	ssize_t	i;

	i = 0;
	if (size <= 0)
	{
		while ((*tab)[i])
		{
			if ((*tab)[i])
				(free((*tab)[i]), (*tab)[i] = NULL);
			i++;
		}
		if (*tab)
			(free(*tab), *tab = NULL);
	}
	else
	{
		while (i < size)
		{
			if ((*tab)[i])
				(free((*tab)[i]), (*tab)[i] = NULL);
			i++;
		}
		if (*tab)
			(free(*tab), *tab = NULL);
	}
}

void	clear_t_map(t_map *map)
{
	if (map->no_texture)
		safe_free(&map->no_texture);
	if (map->ea_texture)
		safe_free(&map->ea_texture);
	if (map->so_texture)
		safe_free(&map->so_texture);
	if (map->we_texture)
		safe_free(&map->we_texture);
	if (map->fd > 2)
		(get_next_line(-1), close(map->fd), map->fd = 0);
	if (map->grid)
		free_tab(&map->grid, 0);
	if (map->flood_filled)
		free_tab(&map->flood_filled, 0);
}

void	safety_kill_render(void *mlx_ptr, void *win_ptr, bool loop)
{
	if (win_ptr)
		mlx_destroy_window(mlx_ptr, win_ptr);
	if (mlx_ptr)
	{
		if (loop)
			mlx_loop_end(mlx_ptr);
		mlx_destroy_display(mlx_ptr);
	}
}

void	destroy_graphics(t_game *game)
{
	size_t	x;

	x = 0;
	if (game->r_img.img)
		mlx_destroy_image(game->mlx, game->r_img.img);
	if (game->weapon.idle.img)
		mlx_destroy_image(game->mlx, game->weapon.idle.img);
	while (x < 4)
	{
		mlx_destroy_image(game->mlx, game->textures[x].img);
		x++;
	}
	x = 0;
	while (x < 5)
	{
		if (game->weapon.fire[x].img)
			mlx_destroy_image(game->mlx, game->weapon.fire[x].img);
		x++;
	}
	x = 0;
	while (x < 5)
	{
		if (game->weapon.fire[x].img)
			mlx_destroy_image(game->mlx, game->weapon.reload[x].img);
		x++;
	}
	safety_kill_render(game->mlx, game->win, game->loop_started);
}

int	clear_game(t_game *game)
{
	static bool	state = false;

	if (state == true)
		return (0);
	state = true;
	printf("Closing game...\n");
	mlx_loop_end(game->mlx);
	clear_t_map(&game->map);
	destroy_graphics(game);
	exit (game->exit_code);
}
