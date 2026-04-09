/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 17:34:48 by nclavel           #+#    #+#             */
/*   Updated: 2026/04/09 18:02:50 by thlibers         ###   ########.fr       */
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
void			safe_free(char **to_free);

/* --- ./cube3d.c --- */

/* --- ./init.c --- */
void			init_struct(t_game *game);
bool			init(t_game *game, char *filepath);
void			render_init(t_game *game);

void	show_grid(char **grid);

/* -------------------- */

/* ##### PARSING ##### */
/* --- ./parsing/check.c --- */
bool			extract_texture(void);
void	show_grid(char **grid);
bool	get_player_pos(t_map *map);
void	init_door(t_map *map);

/* --- ./parsing/map.c --- */
bool			check_extension(char *filepath);
void			show_map(t_map *map);
char			**export_map(t_map *map, char *filepath);
t_map			*init_map(t_map *map, char *filepath);

/* --- ./parsing/texture.c --- */
t_identifier	check_info_type(char *info);
bool			extract_texture_path(t_map *map, char *raw_line);
bool			set_info_texture(t_map *map, char *info_string,
					t_identifier id);

/* --- ./parsing/maps_utils.c --- */
bool			is_map(char *line);

/* -------------------- */

void	ft_dda(t_ray *ray, t_game game);
void	check_hit(t_ray *ray, t_game game);
void	ft_rayshooter(t_ray *ray, t_game game);
void	line_height(t_render *render, t_ray ray);
void	my_mlx_pixel_put(t_game *game, int x, int y, int color);
void	celling_floor(t_game *game);

int		handle_key_press(int keycode, t_game *game);
int		handle_key_release(int keycode, t_game *game);
int		handle_close(t_game *game);

void	move_player(t_game *game, double dx, double dy);
void	move_camera(t_game *game, double rot_speed);
void	chose_action(t_game *game);

void	show_minimap(t_game *game);
bool	calculate_minimap(t_game *game);

void	draw_box(t_game *game, int max_x, int max_y, int color, int pad);
void	draw_square(t_game *game, int pos_y, int pos_x, int len, int color);
void 	draw_line(t_game *game, int x0, int y0, int x1, int y1);

void	weapon(t_game *game);
void	draw_textured_line(t_game *game, int x, int img_x);
void	get_texture(t_ray *ray, t_game *game);
void	draw_textured_line(t_game *game, int x, int img_x);
int		convert_coords_textures(t_ray *ray, t_game *game);
void	load_textures(t_game *game);

#endif
