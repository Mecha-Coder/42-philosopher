/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 23:24:42 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/22 23:24:42 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	initialize(t_data *data, pid_t *philo_pid)
{
	data->meal_count = 0;
	data->eating = FALSE;
	data->philo_pid = philo_pid;
	data->stop_flag = FALSE;
	sem_unlink("/fork");
	sem_unlink("/print");
	data->fork_sem = sem_open("/fork", O_CREAT, 0644, data->philo_no);
	data->print_sem = sem_open("/print", O_CREAT, 0644, 1);
}
