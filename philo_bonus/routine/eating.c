/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:10:39 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/23 10:10:39 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

static void	pick_fork(t_data *data);
static void	begin_eating(t_data *data);
static int	release_fork(t_data *data);

int	eating(t_data *data)
{
	pick_fork(data);
	begin_eating(data);
	return (release_fork(data));
}

static void	pick_fork(t_data *data)
{
	if (data->philo_no == 1)
	{
		sem_wait(data->fork_sem);
		print_log(data, TAKE);
		ft_sleep(data->die_period + 10);
	}
	sem_wait(data->fork_sem);
	sem_wait(data->fork_sem);
}

static void	begin_eating(t_data *data)
{
	sem_wait(&data->my_unsem);
	print_log(data, TAKE);
	print_log(data, TAKE);
	print_log(data, EAT);
	data->last_meal_time = get_time();
	data->eating = TRUE;
	data->meal_count++;
	sem_post(&data->my_unsem);
	ft_sleep(data->eat_period);
}

static int	release_fork(t_data *data)
{
	int	state;

	sem_post(data->fork_sem);
	sem_post(data->fork_sem);
	state = FALSE;
	sem_wait(&data->my_unsem);
	data->eating = FALSE;
	if (data->meal_no > 0 && data->meal_no == data->meal_count)
	{
		data->stop_flag = TRUE;
		state = TRUE;
	}
	sem_post(&data->my_unsem);
	return (state);
}
