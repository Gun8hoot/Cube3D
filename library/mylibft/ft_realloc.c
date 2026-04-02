/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:22:32 by thlibers          #+#    #+#             */
/*   Updated: 2026/04/02 14:16:05 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	*ft_realloc_rmx(void	*ptr, size_t size)
// {
// 	void	*new_ptr;

// 	if (ptr == NULL)
// 		return (ft_calloc(size, sizeof(char)));
// 	if (size == 0)
// 	{
// 		free(ptr);
// 		return (NULL);
// 	}
// }

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	if (ptr == NULL)
		return (ft_calloc(size, sizeof(char)));
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = ft_calloc(size + 1, sizeof(ptr));
	if (new_ptr == NULL)
		return (NULL);
	ft_memcpy(new_ptr, ptr, size);
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
	return (new_ptr);
}

void	*ft_hoelalloc(void *old, size_t old_size, size_t new_size)
{
	size_t			smallest;
	unsigned char	*new;

	smallest = old_size;
	if (new_size < old_size)
		smallest = new_size;
	new = malloc(sizeof(char) * (new_size + 1));
	if (!new)
		return (free(old), NULL);
	return (ft_memcpy(new, old, smallest), free(old), new);
}
