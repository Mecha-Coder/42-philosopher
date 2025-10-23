/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 01:50:32 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/20 01:50:32 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_stop(t_data *data)
{
	int	state;

	state = FALSE;
	mutex(&data->stop_key, LOCK);
	if (data->stop_flag == TRUE)
		state = TRUE;
	mutex(&data->stop_key, UNLOCK);
	return (state);
}
