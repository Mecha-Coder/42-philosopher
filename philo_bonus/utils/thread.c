/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:10:42 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/20 11:10:42 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

int	thread(pthread_t *t, void *(*f)(void *), void *arg, t_code code)
{
	if (code == CREATE)
		return (pthread_create(t, NULL, f, arg));
	else if (code == DETACH)
		return (pthread_detach(*t));
	return (ERROR);
}
