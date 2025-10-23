/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:30:13 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/23 20:30:13 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	clean_up(t_data *data);
static void	show_instruction(void);

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	philo_l[MAX_PHILO];
	t_mutex	fork_l[MAX_PHILO];

	if (!parse_input(&data, ac, av))
		return (show_instruction(), EXIT_FAILURE);
	initialize(&data, philo_l, fork_l);
	simulation(&data);
	clean_up(&data);
}

static void	clean_up(t_data *data)
{
	all_mutex(data, DESTROY);
}

static void	show_instruction(void)
{
	printf(
		"=============================================================\n"
		"                         WRONG INPUT                         \n"
		"=============================================================\n"
		"Correct input > ./philo 4 800 200 200 5\n\n"
		"   1. philo_number:  1 - 200\n"
		"   2. die_period  : 60 - INT_MAX (ms)\n"
		"   3. eat_period  : 60 - INT_MAX (ms)\n"
		"   4. sleep_period: 60 - INT_MAX (ms)\n"
		"   5. meal_limit  :  1 - INT_MAX (optional)\n\n"
		"- If meal limit not set, simulation continues until a philo die\n"
		"- ms is millisecond\n\n");
}

/* Test cases

1) Incorrect arg

./philo 
./philo 5 200 300
./philo 5 200 400 500 20 6

___________________________________________________
2) With and without option

./philo 2 500 200 200
./philo 2 500 200 200 300
./philo 2 10000 200 200 300
___________________________________________________

3) min and max input

./philo 200 600 200 200
./philo 200 2147483647 10000 10000 2147483647
./philo 200 200 60 60
./philo 7 200 60 60 1 
___________________________________________________

4) None number input

./philo 2 --2 200 200
./philo a 100 100 100
./philo 5 650 200 200 -b
./philo +5 650 200 +200 "    +05" 
___________________________________________________

5) Input value not within allowed range

./philo 5 650 -200 200
./philo 500 100 100 100
./philo 5 -2147483649 200 200
./philo 5 10 200 200
./philo 0 60 200 200
./philo 7 200 60 60 0 
___________________________________________________

6) eat_period == sleep_period

./philo 5 620 200 200 5
./philo 4 620 200 200 5
___________________________________________________

7) eat_period < sleep_period

./philo 5 750 200 300 5
./philo 4 750 200 300 5
___________________________________________________

8) eat_period > sleep_period

./philo 5 1200 300 200 5
./philo 4 820 300 200 5
___________________________________________________

9) Crtl + C, no crashes

___________________________________________________

10) Must die (philo shouldn't die during eating)

./philo 1 500 100 100
./philo 3 310 200 200
./philo 7 450 200 200

11) Must not die

./philo 2 800 200 200 100\


____________________________________________

Requirement 
./philo 1 800 200 200. should not eat and should die.
./philo 5 800 200 200. philosopher should die.
./philo 5 800 200 200 7. No philosopher, eaten at least 7 times.
./philo 4 410 200 200. No philosopher should die.
./philo 4 310 200 100. One philosopher should die.
*/