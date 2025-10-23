/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:06:43 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/23 11:06:43 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	clean_up(t_data *data)
{
	sem_close(data->fork_sem);
	sem_close(data->print_sem);
	sem_unlink("/fork");
	sem_unlink("/print");
}
