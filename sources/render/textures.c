/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:42:14 by thlibers          #+#    #+#             */
/*   Updated: 2026/04/09 15:27:38 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

// taille des textures 64x64, 128x128 ou 256x256 pixels.
void	load_textures(t_game *game)
{
	int tex_width;
	int tex_height;
	
	game->map.no_texture = mlx_xpm_file_to_image(game->mlx, "jhauvill.xpm", &tex_width, &tex_height);
	game->map.so_texture = mlx_xpm_file_to_image(game->mlx, "zombie.xpm", &tex_width, &tex_height);
	game->map.ea_texture = mlx_xpm_file_to_image(game->mlx, "wall1.xpm", &tex_width, &tex_height);
	game->map.we_texture = mlx_xpm_file_to_image(game->mlx, "wall2.xpm", &tex_width, &tex_height);
}
