/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:51:48 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/20 12:51:48 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

/*
wait
=====
Purpose: 
- Custom/improved version of usleep function
- WHY! usleep is not precise and timing differ from pc to pc

==========================================================================

- if millisec > 60 millisec
- Sleep until the last 60 ms, then resume calculation
*/

void	ft_sleep(uint64_t millisec)
{
	uint64_t	start;

	start = get_time();
	if (millisec > 60)
		usleep((millisec - 60) * 1000);
	while (get_time() - start < millisec)
		usleep(10);
}
