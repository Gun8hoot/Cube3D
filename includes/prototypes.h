/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 17:34:48 by nclavel           #+#    #+#             */
/*   Updated: 2026/04/16 15:59:17 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "includes/includes.h"
# include "includes/struct.h"

/* ======= SOURCES ROOT ======= */
/* --- ./init.c --- */

/* Initialized raycasting */
void			init_render(t_game *game);
/* Initialized t_map structure */
t_map			*init_map(t_map *map, char *filepath);
/* Main initialization function */
bool			init(t_game *game, char *filepath);

/* -------------------- */

/* ======= ENVIRONEMENT ======= */
/* --- door.c --- */

/* Initialized door on the map */
void			init_door(t_map *map);
/* Function how is called when open a door */
void			open_door(t_game *game);

/* -------------------- */

/* ======= PARSING ======= */

/* Extract data like color and texture filepath from the provide .cub file */
t_map			*extract_info(t_map *map);
/* Extract the map from the .cub file */
char			**extract_map(t_map *map);
/* Extract the texture string and color from the file */
bool			extract_texture(void);

/* --- check.c --- */

/* DFS Flood fill */
bool			floodfill(size_t x, size_t y, t_map *map, char c);
/* Function that check if floodfilled map is ok */
bool			check_floodfill(char **grid);
/* Get the player position on the grid */
bool			get_player_pos(t_map *map);
/* Check if ive got every info needed */
bool			check_parsing(t_map *map);
/* --- map.c --- */
/* Check if the map end with a .cub extension */
bool			check_extension(char *filepath);
void			show_map(t_map *map);
/* Extract the map from the .cub file */
char			**export_map(t_map *map, char *filepath);
/* Initialized map and his data */
t_map			*init_map(t_map *map, char *filepath);
/* --- texture.c --- */
t_id			check_info_type(char *info);
bool			extract_texture_path(t_map *map, char *raw_line);
bool			set_info_texture(t_map *map, char *info_string, t_id id);
/* --- maps_utils.c --- */
bool			is_map(char *line);
char			**cpy_map(t_map *map, char **dest, char **src);

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
void			weapon(t_game *game, t_img img);
void			animating_weapon(t_game *game);
/* --- shape.c --- */
void			draw_box(t_game *game, int max_x, int max_y, int color, int pad);
void			draw_square(t_game *game, int pos_y, int pos_x, int len, int color);
void			draw_line(t_game *game, int x0, int y0, int x1, int y1);
/* --- load_texture.c --- */
bool			load_wall(t_game *game);
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
void			reloading_anim(t_game *game);
void			shooting_anim(t_game *game);
/* -------------------- */
/* ======= UTILS ======= */
/* --- clean.c --- */
/* Free the vars and put it to NULL */
void			safe_free(char **to_free);
/* Free and put an char ** to NULL */
void			free_tab(char ***tab, ssize_t size);
/* Free everything allocated and put everything to NULL */
int				clear_game(t_game *game);
/* --- mlx_utils.c --- */
void			my_mlx_pixel_put(t_game *game, int x, int y, int color);
/* --- time_based.c --- */
t_ll				ms_time(t_ll *ll_ptr);
t_ll				ms_to_s(t_ll timestamp, t_ll *ll_ptr);
t_ll				timeval_to_ms(struct timeval time, t_ll *ll_ptr);
t_ll				ms_time_cmp(t_ll timestamp1, t_ll timestamp2, t_ll *ll_ptr);
/* -------------------- */
void			loading_msg(t_game *game, char *texture);

#endif
