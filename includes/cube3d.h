/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 21:45:44 by nclavel           #+#    #+#             */
/*   Updated: 2026/04/01 13:20:19 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "includes/define.h"
# include "includes/error.h"
# include "includes/includes.h"
# include "includes/prototypes.h"
# include "includes/struct.h"
# include "library/minilibx-linux/mlx.h"
# include "library/mylibft/libft.h"

typedef struct s_vec
{
	float x;
	float y;
	float z;
}	t_vec;

typedef struct s_ray
{
	t_vec origin;
	t_vec direction;
}	t_vec;

typedef struct s_game
{
	
}	t_game

#endif
