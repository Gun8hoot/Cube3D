/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 21:45:44 by nclavel           #+#    #+#             */
/*   Updated: 2026/04/20 14:18:16 by thlibers         ###   ########.fr       */
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
# define CR_SIZE 130 /* Size of the crosshair */

/* Game */
# define UNLIMITED 99999 /* FPS no limit define */
# define DEFAULT_FOV 66 /* Best FOV define */
# define HITBOX 0.1 /* square 0.1 * 0.1 arround player */
# define CR_PADD_CENTER 150
# define ANIM_FRAME 30
# define RELOADING_TIME 5 /* Reloading animation in second */
# define SHOOTING_TIME 2 /* Shooting animation in second */
// # define FPS_TIME (1000000.0 / FPS) /* Convert nanosec per frame */
# define ROT_SPEED 0.025
# define PLA_SPEED 0.05
# define M_PI 3.141592653589793

# define B_BLACK 0x000000
# define B_RED 0xFF0000
# define B_GREEN 0x00FF00
# define B_BLUE 0x0000FF
# define B_YELLOW 0xFFFF00
# define B_WHITE 0xFFFFFF

/* Event player */
# define KEY_W 0x77
# define KEY_S 0x73
# define KEY_A 0x61
# define KEY_D 0x64
# define KEY_R 0x72
# define KEY_E 0x65
# define KEY_SPC 0x20
# define KEY_ESC 0xFF1B
# define KEY_ENT 0xFF0D
# define KEY_LEFT 0xFF51
# define KEY_RIGHT 0xFF53
# define KEY_SHIFT 0xFFE1

/* Event MLX */
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define DESTROY_NOTIFY 17

/* MINIMAP */
# define PIXEL_PER_TILES 8
// # define MINIMAP_WIDTH WIDTH / 4
// # define MINIMAP_HEIGHT HEIGHT / 4
# define BACKBOX_PADD 4
# define FRONTBOX_PADD 6
# define INBOX_PADD 10
// # define TOT_PADD BACKBOX_PADD + FRONTBOX_PADD
# define DEFAULT_ELEM_SIZE 16
# define RAY_PRECISION 0.1

/* ANIM FILENAME */
# define IDLE "textures/720p/weapon/idle.xpm"

/* ======== Fire ======== */
# define FIRE_A1 "textures/720p/weapon/fire/1.xpm"
# define FIRE_A2 "textures/720p/weapon/fire/2.xpm"
# define FIRE_A3 "textures/720p/weapon/fire/3.xpm"
# define FIRE_A4 "textures/720p/weapon/fire/4.xpm"
# define FIRE_A5 "textures/720p/weapon/fire/5.xpm"

/* ======== Reload ======== */
# define RELOAD_A1 "textures/720p/weapon/reload/1.xpm"
# define RELOAD_A2 "textures/720p/weapon/reload/2.xpm"
# define RELOAD_A3 "textures/720p/weapon/reload/3.xpm"
# define RELOAD_A4 "textures/720p/weapon/reload/4.xpm"
# define RELOAD_A5 "textures/720p/weapon/reload/5.xpm"

#endif
