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
	if (size < 0)
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
		(free(map->no_texture), map->no_texture = NULL);
	if (map->ea_texture)
		(free(map->ea_texture), map->ea_texture = NULL);
	if (map->so_texture)
		(free(map->so_texture), map->so_texture = NULL);
	if (map->we_texture)
		safe_free(&map->we_texture);
	if (map->fd > 2)
		(get_next_line(-1), close(map->fd), map->fd = 0);
	if (map->grid)
		free_tab(&map->grid, map->line_number);
	if (map->flood_filled)
		free_tab(&map->flood_filled, map->line_number);
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
		safe_free(mlx_ptr);
	}
}

void	destroy_graphics(t_game *game)
{
	safety_kill_render(game->mlx, game->win, game->loop_started);
	if (game->r_img.img)
		mlx_destroy_image(game->mlx, &game->r_img.img);
	if (game->w_img.img)
		mlx_destroy_image(game->mlx, &game->w_img.img);
	if (game->weapon.idle.img)
		mlx_destroy_image(game->mlx, &game->weapon.idle.img);
	if (game->weapon.fire[0].img)
		mlx_destroy_image(game->mlx, &game->weapon.fire[0].img);
	if (game->weapon.fire[1].img)
		mlx_destroy_image(game->mlx, &game->weapon.fire[1].img);
	if (game->weapon.fire[2].img)
		mlx_destroy_image(game->mlx, &game->weapon.fire[2].img);
	if (game->weapon.fire[3].img)
		mlx_destroy_image(game->mlx, &game->weapon.fire[3].img);
	if (game->weapon.fire[4].img)
		mlx_destroy_image(game->mlx, &game->weapon.fire[4].img);
	if (game->weapon.reload[0].img)
		mlx_destroy_image(game->mlx, &game->weapon.reload[0].img);
	if (game->weapon.reload[1].img)
		mlx_destroy_image(game->mlx, &game->weapon.reload[1].img);
	if (game->weapon.reload[2].img)
		mlx_destroy_image(game->mlx, &game->weapon.reload[2].img);
	if (game->weapon.reload[3].img)
		mlx_destroy_image(game->mlx, &game->weapon.reload[3].img);
	if (game->weapon.reload[4].img)
		mlx_destroy_image(game->mlx, &game->weapon.reload[4].img);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
}

void	clear_game(t_game *game)
{
	clear_t_map(&game->map);
	destroy_graphics(game);
}
