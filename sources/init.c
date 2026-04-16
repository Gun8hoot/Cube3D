/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:42:33 by nclavel           #+#    #+#             */
/*   Updated: 2026/04/13 15:53:35 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

bool	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (fprintf(stderr, MLX_ERROR), false);
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Cube3D");
	if (!game->win)
		return (fprintf(stderr, MLX_ERROR), false);
	game->r_img.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->r_img.img)
		return (fprintf(stderr, MLX_ERROR), false);
	game->r_img.addr = mlx_get_data_addr(game->r_img.img, &game->r_img.bits_per_pixel, &game->r_img.line_length, &game->r_img.endian);
	if (!game->r_img.addr)
		return (fprintf(stderr, MLX_ERROR), false);
	if (!load_textures(game))
		return (false);
	game->player.pos_x = game->map.start_pos[1] + 0.50;
	game->player.pos_y = game->map.start_pos[0] + 0.50;
	game->player.dir_x = game->map.looking_at[1];
	game->player.dir_y = game->map.looking_at[0];
	game->weapon.remaining_bullet = MAX_AMMO_NUM;
	if (!init_anim_weapon(game))
		return (false);
	return (true);
}
void	init_render(t_game *game)
{
	game->render.plane_length = tan((FOV * M_PI / 180.0) / 2.0);
	game->render.plane.x = -game->player.dir_y * game->render.plane_length;
	game->render.plane.y = game->player.dir_x * game->render.plane_length;
	game->render.time = 0.0;
	game->render.oldtime = 0.0;
	game->render.draw_start = 0;
	game->render.draw_end = 0;
	game->render.line_height = 0;
}

t_map	*init_map(t_map *map, char *filepath)
{
	map->filepath = filepath;
	if (!extract_info(map))
		return (NULL);
	if (!extract_map(map))
		return (NULL);
	if (!get_player_pos(map))
		return (NULL);
	if (!check_parsing(map))
		return (NULL);
	map->flood_filled = cpy_map(map, map->flood_filled, map->grid);
	if (!map->flood_filled)
		return (NULL);
	floodfill(map->start_pos[1], map->start_pos[0], map, 'F');
	init_door(map);
	if (map->number_char_max > 320 || map->line_number > 180)
		return (NULL);
	return (map);
}

bool	init(t_game *game, char *filepath)
{
	ft_memset(game, '\0', sizeof(t_game));
	if (!init_map(&game->map, filepath))
		return (false);
	if (!calculate_minimap(game))
		return (ft_fprintf(2, TOO_BIG_ERROR), false);
	if (!init_game(game))
		return (false);
	printf(INIT_COMPLET);
	return (true);
}
