/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 12:45:13 by thlibers          #+#    #+#             */
/*   Updated: 2026/04/17 13:06:17 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*check_s1(void)
{
	char	*s1;

	s1 = malloc(1);
	if (!s1)
	{
		errno = EGNL;
		return (NULL);
	}
	s1[0] = '\0';
	return (s1);
}

static char	*mini_join(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*join;

	i = ft_strlen_mod(s1);
	j = ft_strlen_mod(s2);
	join = malloc(i + j + 1);
	if (!join)
	{
		errno = EGNL;
		return (NULL);
	}
	ft_strcpy_mod(join, s1);
	ft_strcpy_mod(join + i, s2);
	join[i + j] = '\0';
	return (join);
}

char	*ft_strjoin_mod(char *s1, char *s2)
{
	char	*join;

	if (!s1)
	{
		s1 = check_s1();
		if (!s1)
			return (NULL);
	}
	if (!s2)
		return (s1);
	join = mini_join(s1, s2);
	free(s1);
	return (join);
}
