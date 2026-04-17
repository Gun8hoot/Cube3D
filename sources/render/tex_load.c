/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:42:14 by thlibers          #+#    #+#             */
/*   Updated: 2026/04/17 12:31:54 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

// taille des textures 64x64, 128x128 ou 256x256 pixels.
bool	load_wall(t_game *game)
{
	int		i;
	char	*paths[5];

	path[5] = {game->map.no_texture, game->map.so_texture,
		game->map.ea_texture, game->map.we_texture, game->map.d_texture};
	i = 0;
	while (i < 5)
	{
		if (!paths[i] && i == 4)
			break ;
		printf("\x1b[0;33m[+] Loading '%s'\n\x1b[0m", paths[i]);
		game->textures[i].img = mlx_xpm_file_to_image(game->mlx, paths[i],
				&game->textures[i].width, &game->textures[i].height);
		if (!game->textures[i].img)
			return (ft_fprintf(2, TEXT_ERROR, paths[i]), false);
		game->textures[i].addr = mlx_get_data_addr(game->textures[i].img,
				&game->textures[i].bits_per_pixel,
				&game->textures[i].line_length, &game->textures[i].endian);
		if (!game->textures[i].addr)
			return (ft_fprintf(2, TEXT_ERROR, paths[i]), false);
		i++;
	}
	return (true);
}

t_img	*ft_text_load(t_game *game, t_img *img, char *texture)
{
	ft_memset(img, '\0', sizeof(t_img));
	img->img = mlx_xpm_file_to_image(game->mlx, texture,
			&img->width, &img->height);
	printf("\x1b[0;33m[+] Loading '%s'\n\x1b[0m", texture);
	if (!img->img)
	{
		img = NULL;
		fprintf(stderr, TEXT_ERROR, texture);
		return (NULL);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (!img->addr)
	{
		img = NULL;
		fprintf(stderr, TEXT_ERROR, texture);
		return (NULL);
	}
	return (img);
}
