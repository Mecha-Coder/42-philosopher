/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 02:21:26 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/20 02:21:26 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	init_philo(t_data *data);

/*
initialize
==========
- Reset/prep all mutex and philo data 
- Assign correct forks to philo

======================================================================
Fork assigment

index      0        1         2
		[philo 1, philo 2, philo 3]
		   ^        ^        ^
		   |        |        |
		[fork 0 , fork 1 , fork 2]

- philo_3 with id of (3) have an index of (2)
- philo_3 grep right_fork = fork_2  fork[philo_index]
- Then grep the left_fork = fork_0  fork[(philo_index + 1) % philo_num]
*/
void	initialize(t_data *data, t_philo *philo_l, t_mutex *fork_l)
{
	data->philo = philo_l;
	data->fork = fork_l;
	data->stop_flag = FALSE;
	all_mutex(data, INIT);
	init_philo(data);
}

static void	init_philo(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_no)
	{
		data->philo[i].id = i + 1;
		data->philo[i].eating = FALSE;
		data->philo[i].meal_count = 0;
		data->philo[i].r_fork = &data->fork[i];
		data->philo[i].l_fork = &data->fork[(i + 1) % data->philo_no];
		data->philo[i].get = data;
	}
}
