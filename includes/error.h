/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 21:45:44 by nclavel           #+#    #+#             */
/*   Updated: 2026/04/01 11:34:15 by nclavel          ###   ########.fr       */
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

/* --- ERROR ERRNO --- */
# define EGNL 0x55

#endif