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

#include "../philo.h"

int	thread(pthread_t *t, void *(*f)(void *), void *arg, t_code code)
{
	if (code == CREATE)
		return (pthread_create(t, NULL, f, arg));
	else if (code == JOIN)
		return (pthread_join(*t, NULL));
	return (ERROR);
}
