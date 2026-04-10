/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:42:14 by thlibers          #+#    #+#             */
/*   Updated: 2026/04/10 12:46:14 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

// taille des textures 64x64, 128x128 ou 256x256 pixels.
void	load_textures(t_game *game)
{
	int tex_width;
	int tex_height;
	int i;
	char *paths[4] = {"textures/jhauvill.xpm", "textures/zombie.xpm", "textures/wall1.xpm", "textures/wall1.xpm"};
	
	i = 0;
	while (i < 4)
	{
		game->textures[i].img = mlx_xpm_file_to_image(game->mlx, paths[i], &tex_width, &tex_height);
		if (!game->textures[i].img)
		{
			ft_fprintf(2, "Error: Failed to load texture %s\n", paths[i]);
			return ;
		}
		game->textures[i].width = tex_width;
		game->textures[i].height = tex_height;
		game->textures[i].addr = mlx_get_data_addr(game->textures[i].img, &game->textures[i].bits_per_pixel, &game->textures[i].line_length, &game->textures[i].endian);
		if (!game->textures[i].addr)
		{
			ft_fprintf(2, "Error: Failed to get data from texture %s\n", paths[i]);
			return ;
		}
		i++;
	}
}
