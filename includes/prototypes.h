/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 17:34:48 by nclavel           #+#    #+#             */
/*   Updated: 2026/03/31 19:05:01 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H
# include "includes/cube3d.h"

bool	check_extension(char *filepath);
char	**export_map(t_map *map, char *filepath);
bool	init(t_game *game, char *filepath);

#endif