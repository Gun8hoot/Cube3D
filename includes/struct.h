/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 17:45:48 by nclavel           #+#    #+#             */
/*   Updated: 2026/04/08 17:28:10 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include "includes/includes.h"

/* --- RENDER --- */
typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
}				t_player;

typedef struct s_vec
{
	double		x;
	double		y;
	double		z;
}				t_vec;

typedef struct s_render
{
	t_vec		plane;
	double		plane_length;
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
	int			hit;  // was a wall hit?
	int			side; // was a NS or a EW wall hit?
}				t_ray;

typedef struct s_minimap
{
	double	ratio;					// The ratio used to zoom or unzoom the minimap in case of too big minimap
	size_t		pixel_per_elem;		// Number of pixel to display one element of a grid ex: 8 == 8 width * 8 height
	size_t	width_max;				// Width maximum we can get
	size_t	height_max;				// Height maximum we can get
	size_t	padding_top_bottom;		// The number of pixel for the map top/bottom padding
	size_t	padding_right_left;		// The number of pixel for the map right/left padding
	bool	was_on_door;
}				t_minimap;

/* --- MAP --- */
typedef enum e_allow_char
{
	INVALID = 'X',		// Never used but here for safety
	FLOOR = '0',		// Character of the floor
	WALL = '1',			// Character of the wall
	DOOR = 'D',			// Character of the initial door
	DOOR_OPEN = 'O',	// Character of the opened door
	DOOR_CLOSE = 'C',	// Character of the closed door
	SPACE = ' ',		// Character of a space
	PLAYER = 'P'		// Character of a player
}			t_allow_char;

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
	size_t	number_char_max;	// Number of char max in the biggest line
	size_t line_number;			// Map y size
	char *NO_texture;           // Path of texture NORTH
	char *EA_texture;           // Path of texture EAST
	char *SO_texture;           // Path of texture SOUTH
	char *WE_texture;           // Path of texture WEST
	int f_color;                // COLOR OF THE FLOOR
	int c_color;                // COLOR OF THE CELLING
	double start_pos[2];        // Position on the grid of the PLAYER start
	double		looking_at[2];	// Direction of the PLAYER start
	size_t	pos_start_map;		// Position of the map in the file
}	t_map;						// MAIN MAP STRUCTURE


typedef struct s_game
{
	long long		old_time;					// Timestamp to calculate time to render
	double			fps;						// Number of fps
	t_map			map;						// Overall map structure
	t_minimap		minimap;					// Minimap data structure
	t_player		player;						// Player data structure
	t_render		render;						// Render data structure
	t_ray			ray;						// Raycasting data structure
	void			*mlx;						// Pointer to MLX data
	void			*win;						// Pointer to window
	void			*img;
	char			*addr;
	int				keys_pressed[65535];
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}				t_game;						// All game data

#endif
