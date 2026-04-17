/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_based.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 12:40:22 by thlibers          #+#    #+#             */
/*   Updated: 2026/04/17 12:40:25 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

t_ll	ms_time(t_ll *ll_ptr)
{
	struct timeval	time;
	t_ll			time_in_ms;

	gettimeofday(&time, 0);
	time_in_ms = (t_ll)(time.tv_sec * 1000 + time.tv_usec / 1000);
	if (ll_ptr)
		*ll_ptr = time_in_ms;
	return (time_in_ms);
}

t_ll	ms_to_s(t_ll timestamp, t_ll *ll_ptr)
{
	t_ll	time_in_s;

	errno = 0;
	if (timestamp < 0)
	{
		errno = ETIME;
		return (-1);
	}
	time_in_s = timestamp / 1000;
	if (ll_ptr)
		*ll_ptr = time_in_s;
	return (time_in_s);
}

t_ll	timeval_to_ms(struct timeval time, t_ll *ll_ptr)
{
	t_ll	time_in_ms;

	if (time.tv_usec == 0)
		return (0);
	time_in_ms = (t_ll)(time.tv_sec * 1000 + time.tv_usec / 1000);
	if (ll_ptr)
		*ll_ptr = time_in_ms;
	return (time_in_ms);
}

t_ll	ms_time_cmp(t_ll timestamp1, t_ll timestamp2, t_ll *ll_ptr)
{
	t_ll	diff;

	errno = 0;
	if (timestamp1 < 0 || timestamp2 < 0)
	{
		errno = ETIME;
		return (-1);
	}
	diff = timestamp1 - timestamp2;
	if (ll_ptr)
		*ll_ptr = diff;
	return (diff);
}
