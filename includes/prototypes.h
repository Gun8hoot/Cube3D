/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 17:34:48 by nclavel           #+#    #+#             */
/*   Updated: 2026/04/01 12:29:50 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "includes/includes.h"
# include "includes/struct.h"

/* ##### SOURCES ROOT #####*/
/* --- ./clean.c --- */
void			free_tab(char ***tab, ssize_t size);
void			clear_game(t_game *game);

/* --- ./cube3d.c --- */

/* --- ./init.c --- */
void			init_struct(t_game *game);
bool			init(t_game *game, char *filepath);

/* -------------------- */

/* ##### PARSING ##### */
/* --- ./parsing/check.c --- */
bool			extract_texture(void);

/* --- ./parsing/map.c --- */
bool			check_extension(char *filepath);
void			show_map(t_map *map);
char			**export_map(t_map *map, char *filepath);

/* --- ./parsing/texture.c --- */
t_identifier	check_info_type(char *info);
char			*set_info_texture(t_map *map, char *texture_path,
					t_identifier id);
bool			extract_texture_path(t_map *map);

/* -------------------- */

#endif