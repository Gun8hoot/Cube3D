/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 10:23:11 by nclavel           #+#    #+#             */
/*   Updated: 2026/04/02 12:21:59 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

void	show_grid(char **grid)
{
	size_t	i;

	i = 0;
	printf("[+] Grid content\n\n");
	while (grid && grid[i])
		printf("%s\n", grid[i++]);
}

void	debug_show_t_map(t_map map)
{
	printf("\n\n--- t_map Content ---\n");
	if (map.filepath)
		printf("[+] Filepath = \"%s\"\n", map.filepath);
	if (map.NO_texture)
		printf("[+] Texture file NO = \"%s\"\n", map.NO_texture);
	if (map.EA_texture)
		printf("[+] Texture file EA = \"%s\"\n", map.EA_texture);
	if (map.SO_texture)
		printf("[+] Texture file SO = \"%s\"\n", map.SO_texture);
	if (map.WE_texture)
		printf("[+] Texture file WE = \"%s\"\n", map.WE_texture);
	printf("[+] Floor color = %X\n", map.C_color);
	printf("[+] Celling color = %X\n", map.F_color);
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

int main(void)
{
    t_data data;
    
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, HEIGHT, WIDTH, "Cube3D");
    data.img = mlx_new_image(data.mlx, HEIGHT, WIDTH);
    data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian); // ???
    mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
    mlx_loop(data.mlx);
    return (0);
}
