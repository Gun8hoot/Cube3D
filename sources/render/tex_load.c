/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:42:14 by thlibers          #+#    #+#             */
/*   Updated: 2026/04/16 13:40:26 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

// taille des textures 64x64, 128x128 ou 256x256 pixels.
bool	load_textures(t_game *game)
{
	int		tex_width;
	int		tex_height;
	int		i;
	char	*paths[5] = {game->map.no_texture, game->map.so_texture,
			game->map.ea_texture, game->map.we_texture, game->map.d_texture};
	i = 0;
	printf("%s\n", game->map.d_texture);
	while (i < 5)
	{
		if (!paths[i] && i == 4)
			break;
		if (!paths[i])
		{
            ft_fprintf(2, "Error: Texture path %d is NULL\x1b[0m\n", i);
            return (false);
		}
		game->textures[i].img = mlx_xpm_file_to_image(game->mlx, paths[i],
				&tex_width, &tex_height);
		if (!game->textures[i].img)
		{
			ft_fprintf(2, "Error: Failed to load texture %s\x1b[0m\n", paths[i]);
			return (false);
		}
		game->textures[i].width = tex_width;
		game->textures[i].height = tex_height;
		game->textures[i].addr = mlx_get_data_addr(game->textures[i].img,
				&game->textures[i].bits_per_pixel,
				&game->textures[i].line_length, &game->textures[i].endian);
		if (!game->textures[i].addr)
		{
			ft_fprintf(2, "Error: Failed to get data from texture %s\x1b[0m\n",
				paths[i]);
			return (false);
		}
		i++;
	}
	return (true);
}

t_img	*ft_text_load(t_game *game, t_img *img, char *texture)
{
	ft_memset(img, '\0', sizeof(t_img));
	img->img = mlx_xpm_file_to_image(game->mlx, texture, &img->width, &img->height);
	// mlx_string_put(game->mlx, game->win, WIDTH / 2, HEIGHT / 2, B_WHITE, "")
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
