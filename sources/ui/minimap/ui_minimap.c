/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 12:36:27 by thlibers          #+#    #+#             */
/*   Updated: 2026/04/17 19:45:29 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

static bool	minimap_padding(t_game *game, size_t data, size_t inferior_to)
{
	size_t	px_per_line;
	bool	has_modify;

	has_modify = false;
	while (game->minimap.pixel_per_elem > 0)
	{
		px_per_line = game->minimap.pixel_per_elem * data;
		if (px_per_line >= inferior_to - INBOX_PADD)
		{
			game->minimap.pixel_per_elem--;
			has_modify = true;
		}
		else
			break ;
	}
	if (has_modify == true)
		return (false);
	if (inferior_to == WIDTH / 4)
		game->minimap.padding_right_left = (WIDTH / 4 - px_per_line) / 2;
	else
		game->minimap.padding_top_bottom = (HEIGHT / 4 - px_per_line) / 2;
	return (true);
}

bool	calculate_minimap(t_game *game)
{
	game->minimap.pixel_per_elem = DEFAULT_ELEM_SIZE;
	while (game->minimap.pixel_per_elem > 0)
	{
		if (!minimap_padding(game, game->map.line_number, HEIGHT / 4))
			continue ;
		if (!minimap_padding(game, game->map.number_char_max, WIDTH / 4))
			continue ;
		break ;
	}
	if (game->minimap.pixel_per_elem == 0)
		return (false);
	return (true);
}

static void	draw_element(t_game *game, char type, t_vec pos)
{
	if (type == WALL)
		draw_square(game, pos, game->minimap.pixel_per_elem, B_GREEN);
	else if (type == PLAYER)
		draw_square(game, pos, game->minimap.pixel_per_elem, B_RED);
	else if (type == DOOR_CLOSE)
		draw_square(game, pos, game->minimap.pixel_per_elem, B_YELLOW);
	else if (type == DOOR_OPEN)
		draw_square(game, pos, game->minimap.pixel_per_elem, B_BLUE);
}

static void	draw_minimap_elements(t_game *game)
{
	size_t	y;
	size_t	x;
	t_vec	pos;

	pos.y = game->minimap.padding_top_bottom + 4;
	y = 0;
	while (game->map.grid[y])
	{
		pos.x = game->minimap.padding_right_left + 4;
		x = 0;
		while (game->map.grid[y][x])
		{
			draw_element(game, game->map.grid[y][x], pos);
			pos.x += game->minimap.pixel_per_elem;
			x++;
		}
		pos.y += game->minimap.pixel_per_elem;
		y++;
	}
}

void	show_minimap(t_game *game)
{
	draw_box(game, (t_vec){WIDTH / 4 + 4, HEIGHT / 4 + 4}, 0xFFFFFF, 4);
	draw_box(game, (t_vec){WIDTH / 4, HEIGHT / 4}, 0x202020, 8);
	draw_minimap_elements(game);
	show_vision(game);
}
