/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 23:45:15 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/22 23:45:15 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

static void	fork_philo(t_data *data);
static void	check_return_status(t_data *data);
static int	kill_all(t_data *data);

void	simulation(t_data *data)
{
	data->start_time = get_time();
	fork_philo(data);
	check_return_status(data);
}

static void	fork_philo(t_data *data)
{
	int		i;
	pid_t	child;

	i = -1;
	while (++i < data->philo_no)
	{
		child = fork();
		if (child == 0)
			philo_routine(data, i + 1);
		else if (child > 0)
			data->philo_pid[i] = child;
		else
		{
			write(2, "fork() error\n", 12);
			exit(EXIT_FAILURE);
		}
	}
}

static void	check_return_status(t_data *data)
{
	int	i;
	int	status;

	i = -1;
	while (++i < data->philo_no)
	{
		waitpid(-1, &status, 0);
		if (status != 0 && kill_all(data))
			break ;
	}
	i = -1;
	while (++i < data->philo_no)
		waitpid(data->philo_pid[i], NULL, 0);
}

static int	kill_all(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_no)
		kill(data->philo_pid[i], SIGTERM);
	return (TRUE);
}
