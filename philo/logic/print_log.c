/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:54:38 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/20 12:54:38 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
print_log
=========
- Only one thread can print at a time
- Control with write_key mutex
- Also if stop_flag is true, no thread can print anymore

========================================================================
Log message format

- timestamp | philo_id  |  task
-     0     |     1     |    has taken fork
-    200    |     1     |    is sleeping
-    400    |     2     |    is thinking
-    600    |     3     |    is eating
-    600    |     5     |    died
*/

void	print_log(t_philo *philo, char *task)
{
	uint64_t	time;

	time = get_time() - philo->get->start_time;
	mutex(&philo->get->write_key, LOCK);
	if (!check_stop(philo->get))
		printf("%lu %d %s\n", time, philo->id, task);
	mutex(&philo->get->write_key, UNLOCK);
}
