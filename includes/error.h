/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 21:45:44 by nclavel           #+#    #+#             */
/*   Updated: 2026/04/13 13:46:41 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

/* --- ERROR MESSAGES --- */
# define ARG_ERROR "Error:\nNot enough arguments\n"
# define OPEN_ERROR "Error:\nFailed to open\n"
# define ALLOC_ERROR "Error:\nFailed to allocated\n"
# define EXT_ERROR "Error:\nWrong extension type\n"
# define ID_ERROR "Error:\nWrong identifier type\n"
# define OOB_ERROR "Error:\nOut-Of-Bound error\n"
# define CPY_ERROR "Error:\nFailed to copy\n"
# define DUPLICAT_ERROR "Error:\nTexture in duplicated\n"
# define MAP_ERROR "Error:\nInvalid map\n"
# define MULT_PLAYER_ERROR "Error:\nMultiple user defined\n"
# define PLAYER_ERR "Error:\nNeed a ONE player\n"
# define TOO_BIG_ERROR "Error:\nMap is too big (< 321 width & < 180 height)\n"

/* --- ERROR ERRNO --- */
# define EGNL 0x55
# define ELESS 0xAB
# define ETRIM 0x99

#endif
