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
# define ARG_ERROR "\x1b[0;31mError:\nNot enough arguments\n\x1b[0m"
# define OPEN_ERROR "\x1b[0;31mError:\nFailed to open\x1b[0m\n"
# define ALLOC_ERROR "\x1b[0;31mError:\nFailed to allocated\x1b[0m\n"
# define EXT_ERROR "\x1b[0;31mError:\nWrong extension type\x1b[0m\n"
# define ID_ERROR "\x1b[0;31mError:\nWrong identifier type\x1b[0m\n"
# define OOB_ERROR "\x1b[0;31mError:\nOut-Of-Bound error\x1b[0m\n"
# define CPY_ERROR "\x1b[0;31mError:\nFailed to copy\x1b[0m\n"
# define DUPLICAT_ERROR "\x1b[0;31mError:\nTexture in duplicated\x1b[0m\n"
# define MAP_ERROR "\x1b[0;31mError:\nInvalid map\x1b[0m\n"
# define MLX_ERROR "\x1b[0;31mError:\nFailed to initialized MLX\x1b[0m\n"
# define TEXT_ERROR "\x1b[0;31mError:\nFailed to load %s\x1b[0m\n"
# define MISS_TEXT_ERROR "\x1b[0;31mError:\nMissing %s texture\x1b[0m\n"
# define MULT_PLAYER_ERROR "\x1b[0;31mError:\nMultiple user defined\x1b[0m\n"
# define PLAYER_ERR "\x1b[0;31mError:\nNeed a ONE player\x1b[0m\n"
# define TOO_BIG_ERROR "\x1b[0;31mError:\nMap is too big\x1b[0m\n"

/* COMPLETE MESSAGES */
# define INIT_COMPLET "\x1b[0;32m[+] Initialization complete!\x1b[0m\n"

/* --- ERROR ERRNO --- */
# define EGNL 0x55
# define ELESS 0xAB
# define ETRIM 0x99

#endif
