/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 17:45:48 by nclavel           #+#    #+#             */
/*   Updated: 2026/04/17 17:44:21 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "includes/includes.h"

typedef long long	t_ll;

typedef struct s_anim
{
	struct timeval	start;
	struct timeval	end;
	struct timeval	last;
	bool			animate;
}					t_anim;

typedef struct s_door
{
	struct timeval	start;
	bool			is_on_door;
	size_t			door_cord[2];
}					t_door;

typedef struct s_player
{
	t_door			door;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
}					t_player;

typedef struct s_fps
{
	struct timeval	frame_start;
	struct timeval	frame_end;
	struct timeval	last_frame_time;			// Timestamp of the last frame
	double			delta_fps;					// time to process
	double			fps_timer;
	int				fps_counter;				// The fps counter;
	char			string[16];
}					t_fps;

typedef struct s_img
{
	void			*img;				// Images ptr
	char			*addr;				// Pixel ptr
	int				width;				// Width of the ptr
	int				height;				// Height of the ptr
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_img;

typedef struct s_fvec
{
	double			x;
	double			y;
	double			z;
}					t_fvec;

typedef struct s_vec
{
	int				x;
	int				y;
}					t_vec;

typedef struct s_line
{
	t_vec			d;
	t_vec			s;
	int				err;
}					t_line;

typedef struct s_render
{
	t_fvec			plane;
	double			plane_length;
	double			oldtime;
	double			time;
	int				draw_start;
	int				draw_end;
	int				line_height;
}					t_render;

typedef struct s_weapon
{
	t_img			reload[5];
	t_img			fire[5];
	t_img			idle;
	t_anim			anim;
	char			*dst;
	int				color;
	int				start_x;
	int				start_y;
	int				frame;
	bool			is_animating;
	bool			cannot_shoot;
	bool			is_reloading;
	bool			is_shooting;
	u_int32_t		remaining_bullet;
}					t_weapon;

typedef struct s_ray
{
	t_img			*current_texture;
	t_fvec			step;
	t_fvec			cam;
	t_fvec			ray_dir;
	t_fvec			side_dist;
	t_fvec			delta_dist;
	double			perp_wall_dist;
	int				wall_pos[2];
	int				map_x;
	int				map_y;
	int				hit;				// Wall hit?
	int				side;				// NS or a EW wall hit?
}					t_ray;

typedef struct s_minimap
{
	double			ratio;				// Ratio zoom or unzoom minimap
	size_t			pixel_per_elem;		// Num of pixel to display one element
	size_t			width_max;			// Width maximum we can get
	size_t			height_max;			// Height maximum we can get
	size_t			padding_top_bottom;	// Num of pixel top/bottom padding
	size_t			padding_right_left;	// Num of pixel right/left padding
	bool			was_on_door;
}					t_minimap;

typedef struct s_map
{
	int16_t			fd;					// Map file fd
	char			**grid;				// BASE MAP
	char			**flood_filled;		// BASE MAP
	char			*filepath;			// Map filepath
	char			*no_texture;		// Path of texture NORTH
	char			*ea_texture;		// Path of texture EAST
	char			*so_texture;		// Path of texture SOUTH
	char			*we_texture;		// Path of texture WEST
	char			*d_texture;			// Path of door texture
	size_t			number_char_max;	// Num of char max in the biggest line
	size_t			line_number;		// Map y size
	size_t			pos_start_map;		// Position of the map in the file
	int				*f_color;			// COLOR OF THE FLOOR
	int				*c_color;			// COLOR OF THE CELLING
	int				door_num;
	double			start_pos[2];		// Pos on the grid of the PLAYER start
	double			looking_at[2];		// Direction of the PLAYER start
}					t_map;				// MAIN MAP STRUCTURE

typedef struct s_game
{
	t_map			map;					// Overall map structure
	t_img			r_img;					// raycasting
	t_img			*w_img;					// weapon
	t_img			textures[5];			// Wall textures
	t_minimap		minimap;				// Minimap data structure
	t_weapon		weapon;					// Weapon related data
	t_player		player;					// Player data structure
	t_render		render;					// Render data structure
	t_line			line;					// Draw_line struct
	t_ray			ray;					// Raycasting data structure
	t_fps			fps;					// Fps related data
	void			*mlx;					// Pointer to MLX data
	void			*win;					// Pointer to window
	long long		old_time;				// Timestamp time to render
	bool			loop_started;
	int				keys_pressed[65535];	// Keys input arrays
	int				old_mouse_pos;
	int				exit_code;				// Exit code for clear_game
}					t_game;

#endif
