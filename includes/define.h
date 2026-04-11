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

/* SETTINGS */
# define FPS UNLIMITED
# define FOV DEFAULT_FOV
# define MAX_AMMO_NUM 7
# define WIDTH 1280
# define HEIGHT 720

/* Game */
# define UNLIMITED 99999
# define DEFAULT_FOV 66
# define CR_SIZE 130
# define CR_PADD_CENTER 150
# define ANIM_FRAME 30
# define FPS_TIME (1000000.0 / FPS)
# define ROT_SPEED 0.05
# define PLA_SPEED 0.05
# define M_PI 3.141592653589793

# define B_GREEN 0x00FF00
# define B_RED 0xFF0000
# define B_BLUE 0x0000FF
# define B_BLACK 0x000000
# define B_WHITE 0xFFFFFF
# define B_YELLOW 0xFFFF00

/* Event player */
# define KEY_W 0x77
# define KEY_S 0x73
# define KEY_A 0x61
# define KEY_D 0x64
# define KEY_R 0x72
# define KEY_SPC 32
# define KEY_E 101

# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

/* Event MLX */
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define DESTROY_NOTIFY 17

/* MINIMAP */
# define PIXEL_PER_TILES	8
# define MINIMAP_WIDTH		WIDTH / 4
# define MINIMAP_HEIGHT		HEIGHT / 4
# define BACKBOX_PADD		4
# define FRONTBOX_PADD		6
# define INBOX_PADD			10
# define TOT_PADD			BACKBOX_PADD + FRONTBOX_PADD
# define DEFAULT_ELEM_SIZE	16
# define RAY_PRECISION		0.1

#endif
