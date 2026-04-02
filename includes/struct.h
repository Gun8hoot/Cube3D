/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 17:45:48 by nclavel           #+#    #+#             */
/*   Updated: 2026/04/02 08:05:27 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

/* --- RENDER --- */
typedef struct s_player
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			angle;
	double			fov;
}					t_player;

typedef struct s_vec
{
	int				x;
	int				y;
}					t_vec;

typedef struct s_ray
{
	t_vec			direction;
	t_vec			step;
	double			ray_dir_x;
	double			ray_dir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	int				hit;
	// int		side; ?
	double			perp_wall_dist;
	int				draw_start;
	int				draw_end;
	int				line_height;
}					t_ray;

/* --- MAP --- */
typedef enum e_start_looking
{
	NORTH = 0,
	EAST = 1,
	SOUTH = 2,
	WEST = 3,
}					t_start_looking;

typedef enum e_identifier
{
	NONE = 0,
	F = 1,
	C = 2,
	NO = 3,
	EA,
	SO,
	WE
}					t_identifier;

typedef struct s_map
{
	int16_t	fd;		// Map file fd
	char *filepath; // Map filepath
	char **grid;    // BASE MAP
	ssize_t			line_number; // Map y size
	char *NO_texture; // Path of texture NORTH
	char *EA_texture; // Path of texture EAST
	char *SO_texture; // Path of texture SOUTH
	char *WE_texture; // Path of texture WEST
	int F_color;      // COLOR OF THE FLOOR
	int C_color;      // COLOR OF THE CELLING
	size_t			start_pos[2];	// Position on the grid of the PLAYER start
	t_start_looking	looking_at;		// Direction of the PLAYER start
} t_map; // MAIN MAP STRUCTURE

typedef struct s_game
{
	t_map			map;
	t_player		player;
}					t_game;


#endif