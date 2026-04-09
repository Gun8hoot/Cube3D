/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 10:23:11 by nclavel           #+#    #+#             */
/*   Updated: 2026/04/09 15:06:57 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

void	show_grid(char **grid)
{
	size_t	i;

	i = 0;
	if (grid)
		printf("[+] Grid content\n\n");
	while (grid && grid[i])
	{
		printf("%s\n", grid[i]);
		i++;
	}
}

void	debug_show_t_map(t_map map)
{
	printf("\n--- t_map Content ---\n");
	if (map.filepath)
		printf("[+] Filepath = \"%s\"\n", map.filepath);
	if (map.no_texture)
		printf("[+] Texture file NO = \"%s\"\n", map.no_texture);
	if (map.ea_texture)
		printf("[+] Texture file EA = \"%s\"\n", map.ea_texture);
	if (map.so_texture)
		printf("[+] Texture file SO = \"%s\"\n", map.so_texture);
	if (map.we_texture)
		printf("[+] Texture file WE = \"%s\"\n", map.we_texture);
	printf("[+] Floor color = #%X\n", map.c_color);
	printf("[+] Celling color = #%X\n", map.f_color);
	printf("[+] Map started pos %ld\n", map.pos_start_map);
	printf("[+] Map size y %ld\n", map.line_number);
	printf("[+] Size max of a line %ld\n", map.number_char_max);
	printf("[+] Player looking direction y = %.2f, x = %.2f\n", map.looking_at[0], map.looking_at[1]);
	printf("[+] Player starting position y = %.2f, x = %.2f\n", map.start_pos[0], map.start_pos[1]);
	printf("\n");
	show_grid(map.grid);
}

int	game_loop(t_game *game)
{
	chose_action(game);
    celling_floor(game);
    ft_rayshooter(&game->ray, *game);
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	weapon(game);
	show_minimap(game);
    return (0);
}

int main(int argc, char **argv)
{
    t_game game;

	ft_memset(&game, '\0', sizeof(t_game));
	if (argc != 2)
    {
        ft_fprintf(STDERR_FILENO, ARG_ERROR);
        return (1);
    }
	if (!init(&game, argv[1]))
		return (1);
    debug_show_t_map(game.map);
    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT, "Cube3D");
    game.img = mlx_new_image(game.mlx, WIDTH, HEIGHT);
    game.addr = mlx_get_data_addr(game.img, &game.bits_per_pixel, &game.line_length, &game.endian);
	game.balista = mlx_xpm_file_to_image(game.mlx, "textures/weapon.xpm", &game.w_width, &game.w_height);
	if (!game.balista)
        return (ft_fprintf(2, "Error: Impossible de charger weapon.xpm\n"), 1);
	game.weapon_addr = mlx_get_data_addr(game.balista, &game.weapon_bits_per_pixel, &game.weapon_line_length, &game.weapon_endian);

	game.player.pos_x = game.map.start_pos[1];
	game.player.pos_y = game.map.start_pos[0];
  	game.player.dir_x =	game.map.looking_at[1];
	game.player.dir_y = game.map.looking_at[0];

	if (!calculate_minimap(&game))
		return (ft_fprintf(2, "ERROR MINIMAP\n"), false);

	mlx_hook(game.win, 17, 0, handle_close, &game);
	mlx_hook(game.win, 2, 1L<<0, handle_key_press, &game);
	mlx_hook(game.win, 3, 1L<<1, handle_key_release, &game);
    mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
    return (0);
}
