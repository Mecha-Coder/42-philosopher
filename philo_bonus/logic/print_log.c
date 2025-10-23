/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 01:17:31 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/23 01:17:31 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	print_log(t_data *data, char *task)
{
	uint64_t	time;

	time = get_time() - data->start_time;
	sem_wait(data->print_sem);
	printf("%lu %d %s\n", time, data->id, task);
	sem_post(data->print_sem);
}
