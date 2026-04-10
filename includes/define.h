/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 21:45:44 by nclavel           #+#    #+#             */
/*   Updated: 2026/04/10 17:41:32 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

/* Game */
# define WIDTH 1280
# define HEIGHT 720
# define FOV 66
# define CROSSHAIR_SIZE 150
# define ANIM_FRAME 30
# define FPS 60
# define FPS_TIME (1000000.0 / FPS)
# define ROT_SPEED 0.05
# define PLA_SPEED 0.05
# define M_PI 3.141592653589793

/* Event player */
# define KEY_W 0x77
# define KEY_S 0x73
# define KEY_A 0x61
# define KEY_D 0x64
# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
// # define KEY_UP 65362
// # define KEY_DOWN 65364

/* Event MLX */
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define DESTROY_NOTIFY 17

/* MINIMAP */
# define PIXEL_PER_TILES	8
# define MINIMAP_WIDTH		WIDTH/4
# define MINIMAP_HEIGHT		HEIGHT/4
# define BACKBOX_PADD		4
# define FRONTBOX_PADD		6
# define INBOX_PADD			10
# define TOT_PADD			BACKBOX_PADD + FRONTBOX_PADD
# define DEFAULT_ELEM_SIZE	16
# define RAY_PRECISION		0.1

#endif
