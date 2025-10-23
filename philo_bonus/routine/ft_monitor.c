/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 01:28:20 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/23 01:28:20 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	*ft_monitor(void *arg)
{
	t_data		*data;
	uint64_t	now;

	data = (t_data *)arg;
	ft_sleep(data->die_period);
	while (1)
	{
		sem_wait(&data->my_unsem);
		if (data->stop_flag)
		{
			sem_post(&data->my_unsem);
			break ;
		}
		now = get_time();
		if (!data->eating && now - data->last_meal_time >= data->die_period)
		{
			sem_wait(data->print_sem);
			printf("%lu %d %s\n", now - data->start_time, data->id, DIE);
			sem_close(&data->my_unsem);
			exit(EXIT_FAILURE);
		}
		sem_post(&data->my_unsem);
		ft_sleep(2);
	}
	return (NULL);
}
