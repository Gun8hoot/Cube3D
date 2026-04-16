/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 15:47:08 by thlibers          #+#    #+#             */
/*   Updated: 2026/04/16 18:51:55 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

# include "includes/includes.h"

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
}	t_allow_char;

typedef enum e_start_looking
{
	NORTH = 0,
	EAST = 1,
	SOUTH = 2,
	WEST = 3,
}	t_start_looking;

typedef enum e_id
{
	NONE = 0,
	F = 1,
	C = 2,
	NO = 3,
	EA,
	SO,
	WE,
	DO
}	t_id;

#endif
