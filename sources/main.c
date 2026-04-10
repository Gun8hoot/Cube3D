/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 10:23:11 by nclavel           #+#    #+#             */
/*   Updated: 2026/04/10 11:40:59 by thlibers         ###   ########.fr       */
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

// int	main(int argc, char **argv)
// {
// 	t_game	game;

// 	ft_memset(&game, '\0', sizeof(t_game));
// 	if (argc != 2)
// 	{
// 		ft_fprintf(STDERR_FILENO, ARG_ERROR);
// 		return (1);
// 	}
// 	init(&game, argv[1]);
// 	debug_show_t_map(game.map);
// }

// int main(void)
// {
//     t_data data;

//     data.mlx = mlx_init();
//     data.win = mlx_new_window(data.mlx, HEIGHT, WIDTH, "Cube3D");
//     data.img = mlx_new_image(data.mlx, HEIGHT, WIDTH);
//     data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian); // ???
//     mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
//     mlx_loop(data.mlx);
//     return (0);
// }
void	TEST_asign(t_game *game)
{
	game->player.pos_x = 19;
	game->player.pos_y = 3;
  	game->player.dir_x = 0.0;
	game->player.dir_y = -1.0;
}

int	mouse(t_game *game)
{
	int new_x;
	int new_y;
	double	rotation;

	(void)new_y;
	mlx_mouse_get_pos(game->mlx, game->win, &new_x, &new_y);
	rotation = (new_x - (WIDTH / 2));
	mlx_mouse_move(game->mlx, game->win, WIDTH/2, HEIGHT/2);
	if (rotation != 0)
		move_camera(game, rotation / 500);
	game->old_mouse_pos = new_x;
	return (0);
}

void	ui(t_game *game)
{
	weapon(game);
	show_minimap(game);
	crosshair(game);
	show_fps(game);
}

int	game_loop(t_game *game)
{
	gettimeofday(&game->fps.frame_start, 0);
	chose_action(game);
    celling_floor(game);
    ft_rayshooter(&game->ray, *game);
    mlx_put_image_to_window(game->mlx, game->win, game->r_img.img, 0, 0);
    ui(game);
	mouse(game);
	fps_limiter(game);
	return (1);
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
    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT, "Cube3D");
    game.r_img.img = mlx_new_image(game.mlx, WIDTH, HEIGHT);
    game.r_img.addr = mlx_get_data_addr(game.r_img.img, &game.r_img.bits_per_pixel, &game.r_img.line_length, &game.r_img.endian);
	game.w_img.img = mlx_xpm_file_to_image(game.mlx, "textures/weapon.xpm", &game.w_img.width, &game.w_img.height);
	if (!game.w_img.img)
        return (ft_fprintf(2, "Error: Impossible de charger weapon.xpm\n"), 1);
	game.w_img.addr = mlx_get_data_addr(game.w_img.img, &game.w_img.bits_per_pixel, &game.w_img.line_length, &game.w_img.endian);

	load_textures(&game);

	game.player.pos_x = game.map.start_pos[1];
	game.player.pos_y = game.map.start_pos[0];
  	game.player.dir_x =	game.map.looking_at[1];
	game.player.dir_y = game.map.looking_at[0];

	if (!calculate_minimap(&game))
		return (ft_fprintf(2, TOO_BIG_ERROR), false);

	mlx_mouse_hide(game.mlx, game.win);
	mlx_hook(game.win, 17, 0, handle_close, &game);
	mlx_hook(game.win, 2, 1L<<0, handle_key_press, &game);
	mlx_hook(game.win, 3, 1L<<1, handle_key_release, &game);
    mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
    return (0);
}
