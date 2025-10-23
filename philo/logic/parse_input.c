/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 02:19:44 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/20 02:19:44 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	invalid_input(char *s, int min, int max);

/*
parse_input
===========
- Ensure argument count is correct (4 or 5)
- Ensure all arguments within allowable range
- For optional argument (meal_count) if not given, set to -1

===========================================================================
Range allowed

1. philo_number:  1 - 200
2. die_period  : 60 - INT_MAX
3. eat_period  : 60 - INT_MAX
4. sleep_period: 60 - INT_MAX
5. meal_limit  :  1 - INT_MAX

==========================================================================
Return 
	FALSE : One of the arg out of range
	TRUE  : Meet range 
*/
int	parse_input(t_data *data, int ac, char **av)
{
	if (ac < 5 || ac > 6
		|| invalid_input(av[1], 1, 200)
		|| invalid_input(av[2], 60, INT_MAX)
		|| invalid_input(av[3], 60, INT_MAX)
		|| invalid_input(av[4], 60, INT_MAX)
		|| (ac == 6 && invalid_input(av[5], 1, INT_MAX))
	)
		return (FALSE);
	data->philo_no = ft_atoi(av[1]);
	data->die_period = ft_atoi(av[2]);
	data->eat_period = ft_atoi(av[3]);
	data->sleep_period = ft_atoi(av[4]);
	data->meal_no = -1;
	if (ac == 6)
		data->meal_no = ft_atoi(av[5]);
	return (TRUE);
}

static int	invalid_input(char *s, int min, int max)
{
	int	num;

	if (ft_strlen(s) > 10)
		return (TRUE);
	num = ft_atoi(s);
	return (num < min || num > max);
}

/*
int main(int ac, char **av)
{
	t_data data;

	 if (!parse_input(&data, ac, av))
		printf("Wrong input\n");
	else
		printf(
		"1. philo_number: %d\n"
		"2. die_period  : %lu\n"
		"3. eat_period  : %lu\n"
		"4. sleep_period: %lu\n"
		"5. meal_limit  : %d\n"
		, data.philo_no, data.die_period, data.eat_period
		, data.sleep_period, data.meal_no);
}
*/