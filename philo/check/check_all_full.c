/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_full.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 01:53:48 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/20 01:53:48 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_all_full(t_data *data)
{
	int	i;
	int	state;

	i = -1;
	state = TRUE;
	if (data->meal_no == -1)
		return (FALSE);
	while (state && ++i < data->philo_no)
	{
		mutex(&data->philo[i].my_key, LOCK);
		if (data->philo[i].meal_count < data->meal_no)
			state = FALSE;
		mutex(&data->philo[i].my_key, UNLOCK);
	}
	if (state)
	{
		mutex(&data->stop_key, LOCK);
		data->stop_flag = TRUE;
		mutex(&data->stop_key, UNLOCK);
	}
	return (state);
}
