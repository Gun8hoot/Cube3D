/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 17:34:48 by nclavel           #+#    #+#             */
/*   Updated: 2026/04/13 16:52:42 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "includes/includes.h"
# include "includes/struct.h"

/* ======= SOURCES ROOT ======= */
/* --- ./init.c --- */
void			init_struct(t_game *game);
void			init_render(t_game *game);
t_map			*init_map(t_map *map, char *filepath);
bool			init(t_game *game, char *filepath);
/* -------------------- */
/* ======= ENVIRONEMENT ======= */
/* --- door.c --- */
void			init_door(t_map *map);
void			open_door(t_game *game);
/* -------------------- */
/* ======= PARSING ======= */
t_map			*extract_info(t_map *map);
char			**extract_map(t_map *map);
bool			extract_texture(void);
/* --- check.c --- */								// A trier
void	floodfill(size_t x, size_t y, t_map *map);
bool	check_floodfill(char **grid);
bool			get_player_pos(t_map *map);
/* --- map.c --- */
bool			check_extension(char *filepath);
void			show_map(t_map *map);
char			**export_map(t_map *map, char *filepath);
t_map			*init_map(t_map *map, char *filepath);
/* --- texture.c --- */
t_id			check_info_type(char *info);
bool			extract_texture_path(t_map *map, char *raw_line);
bool			set_info_texture(t_map *map, char *info_string, t_id id);
/* --- maps_utils.c --- */
bool			is_map(char *line);
/* -------------------- */
/* ======= PLAYER ======= */
/* --- events.c --- */
int				handle_key_press(int keycode, t_game *game);
int				handle_key_release(int keycode, t_game *game);
int				handle_close(t_game *game);
/* --- mouse.c --- */
int				mouse(t_game *game);
/* --- movements.c --- */
void			move_player(t_game *game, double dx, double dy, unsigned short keycode);
void			move_camera(t_game *game, double rot_speed);
void			chose_action(t_game *game);
/* -------------------- */
/* ======= RAYCASTING ======= */
/* --- ray_utils.c --- */
void			line_height(t_render *render, t_ray ray);
void			draw_textured_line(t_game *game, int x, int img_x);
void			get_texture(t_ray *ray, t_game *game);
int				convert_coords_textures(t_ray *ray, t_game *game);
/* --- raycasting.c --- */
void			ft_dda(t_ray *ray, t_game *game);
void			check_hit(t_ray *ray, t_game *game);
void			ft_rayshooter(t_ray *ray, t_game *game);
/* -------------------- */
/* ======= RENDER ======= */
/* --- render.c --- */
void			celling_floor(t_game *game);
void			weapon(t_game *game);
void			animating_weapon(t_game *game);
/* --- shape.c --- */
void			draw_box(t_game *game, int max_x, int max_y, int color, int pad);
void			draw_square(t_game *game, int pos_y, int pos_x, int len, int color);
void			draw_line(t_game *game, int x0, int y0, int x1, int y1);
/* --- load_texture.c --- */
void			load_textures(t_game *game);
t_img			*ft_text_load(t_game *game, t_img *img, char *texture);

/* -------------------- */
/* ======= USER INTERFACE ======= */
/* --- ui_crosshair.c --- */
void			crosshair(t_game *game);
void			hitmarker(t_game *game);
/* --- ui_fps.c --- */
void			show_fps(t_game *game);
void			fps_limiter(t_game *game);
/* --- ui_minimap.c --- */
bool			calculate_minimap(t_game *game);
void			show_minimap(t_game *game);
/* --- ui_weapon.c --- */
void			bullet_nb(t_game *game);
void			weapon_reload(t_game *game);
int				weapon_gunfire(int keycode, int x, int y, t_game *game);
bool			init_anim_weapon(t_game *game);

/* -------------------- */
/* ======= UTILS ======= */
/* --- clean.c --- */

/* Free the vars and put it to NULL */
void			safe_free(char **to_free);
/* Free and put an char ** to NULL */
void			free_tab(char ***tab, ssize_t size);
/* Free everything allocated and put everything to NULL */
int			clear_game(t_game *game);
/* --- mlx_utils.c --- */
void			my_mlx_pixel_put(t_game *game, int x, int y, int color);
/* --- time_based.c --- */
ll				ms_time(ll *ll_ptr);
ll				ms_to_s(ll timestamp, ll *ll_ptr);
ll				timeval_to_ms(struct timeval time, ll *ll_ptr);
ll				ms_time_cmp(ll timestamp1, ll timestamp2, ll *ll_ptr);
/* -------------------- */

#endif
