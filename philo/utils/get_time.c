/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:51:39 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/20 12:51:39 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
get_time
=========
- Get current time in millisecond
- Type uint64_t ensures variable declared exactly 64 bits

============================================================================
Function - gettimeofday()

gettimeofday(struct timeval *tv, struct timezone *tz)

struct timeval
{
	time_t      tv_sec;     // seconds from January 1, 1970
	suseconds_t tv_usec;    // microsecond of tv_sec
}
Return
> 0 on success,
> -1 on error.

============================================================================
Time conversion:
1 second = 1 000 000 microsec
1 second = 1 000 millisec
*/

uint64_t	get_time(void)
{
	struct timeval	t;

	if (gettimeofday(&t, NULL) == -1)
	{
		write(2, "gettimeofday() error\n", 22);
		return (0);
	}
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}
