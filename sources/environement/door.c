/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 16:01:54 by thlibers          #+#    #+#             */
/*   Updated: 2026/04/13 16:01:56 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

void	init_door(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (map->grid[i][j] == 'D')
			{
				map->grid[i][j] = DOOR_CLOSE;
			}
			j++;
		}
		i++;
	}
}

static char	is_door(char **grid, int x, int y)
{
	if (grid[y][x] == DOOR_CLOSE)
		return (DOOR_CLOSE);
	else if (grid[y][x] == DOOR_OPEN)
		return (DOOR_OPEN);
	return (FLOOR);
}

void	open_door(t_game *game)
{
	int	angle_x;
	int	angle_y;
	int	look_pos[2];

	angle_x = (int)round(game->player.dir_x);
	angle_y = (int)round(game->player.dir_y);
	if (ms_time(NULL) - timeval_to_ms(game->player.door.start, NULL) < 200)
		return ;
	look_pos[0] = (int)(game->player.pos_y + angle_y);
	look_pos[1] = (int)(game->player.pos_x + angle_x);
	if (is_door(game->map.grid, look_pos[1], look_pos[0]) == DOOR_CLOSE)
		game->map.grid[look_pos[0]][look_pos[1]] = DOOR_OPEN;
	else if (is_door(game->map.grid, look_pos[1], look_pos[0]) == DOOR_OPEN)
		game->map.grid[look_pos[0]][look_pos[1]] = DOOR_CLOSE;
	gettimeofday(&game->player.door.start, 0);
}

void	door_logic(t_game *game)
{
	(void)game;
}
