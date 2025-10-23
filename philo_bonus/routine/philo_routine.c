/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 00:02:17 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/23 00:02:17 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

static void	sleeping(t_data *data);
static void	thinking(t_data *data);

void	philo_routine(t_data *data, int id)
{
	pthread_t	checker;

	data->id = id;
	data->last_meal_time = data->start_time;
	sem_init(&data->my_unsem, 0, 1);
	thread(&checker, ft_monitor, data, CREATE);
	thread(&checker, NULL, NULL, DETACH);
	if (data->philo_no != 1 && data->id % 2)
		ft_sleep(data->eat_period - 10);
	while (1)
	{
		if (eating(data))
		{
			sem_close(&data->my_unsem);
			exit(EXIT_SUCCESS);
		}
		sleeping(data);
		thinking(data);
	}
}

static void	sleeping(t_data *data)
{
	print_log(data, SLEEP);
	ft_sleep(data->sleep_period);
}

static void	thinking(t_data *data)
{
	print_log(data, THINK);
}
