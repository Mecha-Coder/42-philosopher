/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 01:57:06 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/20 01:57:06 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	pick_fork(t_philo *philo);
static void	begin_eating(t_philo *philo);
static void	release_fork(t_philo *philo);

void	eating(t_philo *philo)
{
	if (pick_fork(philo))
		return ;
	begin_eating(philo);
	release_fork(philo);
}

// If only one philo, grep the right fork and wait until die
// Odd philo, take right fork first
// Even philo, take left fork first
static int	pick_fork(t_philo *philo)
{
	if (philo->get->philo_no == 1)
	{
		mutex(philo->r_fork, LOCK);
		print_log(philo, TAKE);
		wait(philo->get->die_period + 10);
		return (TRUE);
	}
	if (philo->get->philo_no % 2)
	{
		mutex(philo->r_fork, LOCK);
		mutex(philo->l_fork, LOCK);
	}
	else
	{
		mutex(philo->l_fork, LOCK);
		mutex(philo->r_fork, LOCK);
	}
	print_log(philo, TAKE);
	print_log(philo, TAKE);
	return (FALSE);
}

// Reason why have eating = TRUE is to prevent philo die during eating
// Monitor thread skip check_dead when eating
static void	begin_eating(t_philo *philo)
{
	mutex(&philo->my_key, LOCK);
	print_log(philo, EAT);
	philo->eating = TRUE;
	philo->last_meal_time = get_time();
	philo->meal_count++;
	mutex(&philo->my_key, UNLOCK);
	wait(philo->get->eat_period);
}

// When release fork do in reverse
// Odd philo, release left fork first
// Even philo, release right fork first 
static void	release_fork(t_philo *philo)
{
	mutex(&philo->my_key, LOCK);
	philo->eating = FALSE;
	mutex(&philo->my_key, UNLOCK);
	if (philo->get->philo_no % 2)
	{
		mutex(philo->l_fork, UNLOCK);
		mutex(philo->r_fork, UNLOCK);
	}
	else
	{
		mutex(philo->r_fork, UNLOCK);
		mutex(philo->l_fork, UNLOCK);
	}
}
