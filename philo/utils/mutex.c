/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:51:44 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/20 12:51:44 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	mutex(t_mutex *m, t_code code)
{
	if (code == INIT)
		return (pthread_mutex_init(m, NULL));
	else if (code == LOCK)
		return (pthread_mutex_lock(m));
	else if (code == UNLOCK)
		return (pthread_mutex_unlock(m));
	else if (code == DESTROY)
		return (pthread_mutex_destroy(m));
	return (ERROR);
}
