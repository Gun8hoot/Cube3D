/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:42:27 by nclavel           #+#    #+#             */
/*   Updated: 2026/03/31 18:36:53 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_map
{
	unsigned char	celling_color[3];	// RGB COLORS VALUE 
	unsigned char	floor_color[3];		// RGB COLORS VALUE
	char			*filepath;			// Map filepath
	char			**grid;				// BASE MAP
	ssize_t			line_number;
}				t_map;

typedef struct s_game
{
	t_map	map;
}				t_game;

#endif