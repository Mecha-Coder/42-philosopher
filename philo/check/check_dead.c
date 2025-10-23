/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 01:51:15 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/20 01:51:15 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	is_dead(t_philo *philo);

int	check_dead(t_data *data)
{
	int	i;
	int	state;

	i = -1;
	state = FALSE;
	while (!state && ++i < data->philo_no)
	{
		mutex(&data->philo[i].my_key, LOCK);
		if (is_dead(&data->philo[i]))
			state = TRUE;
		mutex(&data->philo[i].my_key, UNLOCK);
	}
	return (state);
}

static int	is_dead(t_philo *philo)
{
	uint64_t	time_elapse;

	time_elapse = get_time() - philo->last_meal_time;
	if (!philo->eating && time_elapse >= philo->get->die_period)
	{
		print_log(philo, DIE);
		mutex(&philo->get->stop_key, LOCK);
		philo->get->stop_flag = TRUE;
		mutex(&philo->get->stop_key, UNLOCK);
		return (TRUE);
	}
	return (FALSE);
}
