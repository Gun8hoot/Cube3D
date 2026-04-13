
#include "includes/cube3d.h"

ll	ms_time(ll *ll_ptr)
{
	struct timeval	time;
	ll				time_in_ms;

	gettimeofday(&time, 0);
	time_in_ms = (ll)(time.tv_sec * 1000 + time.tv_usec / 1000);
	if (ll_ptr)
		*ll_ptr = time_in_ms;
	return (time_in_ms);
}

ll	ms_to_s(ll timestamp, ll *ll_ptr)
{
	ll	time_in_s;

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

ll	timeval_to_ms(struct timeval time, ll *ll_ptr)
{
	ll	time_in_ms;

	time_in_ms = (ll)(time.tv_sec * 1000 + time.tv_usec / 1000);
	if (ll_ptr)
		*ll_ptr = time_in_ms;
	return (time_in_ms);
}

ll	ms_time_cmp(ll timestamp1, ll timestamp2, ll *ll_ptr)
{
	ll	diff;

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
