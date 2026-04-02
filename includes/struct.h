/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 17:45:48 by nclavel           #+#    #+#             */
/*   Updated: 2026/04/02 12:08:31 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

/* --- RENDER --- */
typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	// double		angle;
}				t_player;

typedef struct s_vec
{
	double		x;
	double		y;
}				t_vec;

typedef struct s_render
{
	t_vec		plane;
	double		oldtime;
	double		time;
	int			draw_start;
	int			draw_end;
	int			line_height;
}				t_render;

typedef struct s_ray
{
	t_vec		dir;
	t_vec		step;
	t_vec		cam;
	t_vec		ray_dir;
	t_vec		side_dist;
	t_vec		delta_dist;
	double		perp_wall_dist;
	int			map_x;
	int			map_y;
	int hit;  // was a wall hit?
	int side; // was a NS or a EW wall hit?
}				t_ray;

/* --- MAP --- */
typedef enum e_start_looking
{
	NORTH = 0,
	EAST = 1,
	SOUTH = 2,
	WEST = 3,
}				t_start_looking;

typedef enum e_identifier
{
	NONE = 0,
	F = 1,
	C = 2,
	NO = 3,
	EA,
	SO,
	WE
}				t_identifier;

typedef struct s_map
{
	int16_t fd;                 // Map file fd
	char *filepath;             // Map filepath
	char **grid;                // BASE MAP
	ssize_t line_number;        // Map y size
	char *NO_texture;           // Path of texture NORTH
	char *EA_texture;           // Path of texture EAST
	char *SO_texture;           // Path of texture SOUTH
	char *WE_texture;           // Path of texture WEST
	int F_color;                // COLOR OF THE FLOOR
	int C_color;                // COLOR OF THE CELLING
	size_t start_pos[2];        // Position on the grid of the PLAYER start
	t_start_looking looking_at; // Direction of the PLAYER start
} t_map;                        // MAIN MAP STRUCTURE

typedef struct s_game
{
	t_map		map;
	t_player	player;
	t_render	render;
	t_ray		ray;
	int			mlx;
	int			win;
}				t_game;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

#endif