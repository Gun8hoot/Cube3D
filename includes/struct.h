/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:42:27 by nclavel           #+#    #+#             */
/*   Updated: 2026/04/01 14:39:33 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "includes/includes.h"

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
	char *filepath; // Map filepath
	char **grid;    // BASE MAP
	ssize_t			line_number;
	char *NO_texture; // Path of texture NO
	char *EA_texture; // Path of texture EA
	char *SO_texture; // Path of texture SO
	char *WE_texture; // Path of texture WE
	int F_color;      // COLOR OF THE FLOOR
	int C_color;      // COLOR OF THE CELLING
	t_start_looking	looking_at;
}					t_map;

typedef struct s_game
{
	t_map			map;
	t_player		player;
}					t_game;

typedef struct s_vec
{
	int				x;
	int				y;
}					t_vec;

typedef struct s_player
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			angle;
	double			fov;
}					t_player;

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

#endif