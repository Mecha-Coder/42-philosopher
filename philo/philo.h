/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:11:29 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/20 11:11:29 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//===========================================================================
// LIBRARY

# include <pthread.h>   // mutex  : init destroy lock unlock
//                      // thread : create join
# include <stdio.h>     // printf
# include <stdlib.h>    // NULL
# include <sys/time.h>  // gettimeofday
# include <unistd.h>    // write, usleep
# include <stdint.h>    // uin64_t
# include <limits.h>    // INT_MAX

//===========================================================================
// CONSTANT

# define MAX_PHILO 200

// Return state
# define TRUE 1
# define FALSE 0
# define ERROR -1

// Log message
# define TAKE "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIE "died"

// Used by thread & mutex util function
// Purpose: to make those function shorter
typedef enum e_code
{
	INIT,
	LOCK,
	UNLOCK,
	DESTROY,
	CREATE,
	JOIN,
}	t_code;

//===========================================================================
// STRUCT

typedef pthread_mutex_t	t_mutex;// To make mutex type shorter
typedef struct s_data	t_data;// Create 2-way linked between structs

// id     : Range  1 - 200
// my_key : Block monitor thread from reading when philo is editing its data
// eating : Inform monitor thread don't check dead during eating
// get    : To fetch info inside data struct

typedef struct s_philo
{
	int			id;
	pthread_t	thread;
	t_mutex		my_key;
	int			eating;
	int			meal_count;
	t_mutex		*r_fork;
	t_mutex		*l_fork;
	uint64_t	last_meal_time;
	t_data		*get;
}	t_philo;

// stop_flag : philos need to check stop_flag whether to proceed
//			   loop or terminate (philos can't communicate with each other)
//             simulation stop when monitor thread determine if a philo died 
//             or all are full
// write_key : Protect print_log()
// stop_key  : Protect stop_flag var

struct s_data
{
	int			stop_flag;
	int			philo_no;
	int			meal_no;
	uint64_t	die_period;
	uint64_t	eat_period;
	uint64_t	sleep_period;
	uint64_t	start_time;
	t_mutex		write_key;
	t_mutex		stop_key;
	t_mutex		start_key;
	t_philo		*philo;
	t_mutex		*fork;
};

//===========================================================================
// PROTOTYPE

// Step
int			parse_input(t_data *data, int ac, char **av);
void		initialize(t_data *data, t_philo *philo_list, t_mutex *fork_list);
void		simulation(t_data *data);
void		all_mutex(t_data *data, t_code code);
void		print_log(t_philo *philo, char *task);

// Routine
void		*ft_philo(void *arg);
void		*ft_monitor(void *arg);
void		eating(t_philo *philo);

// Check
int			check_stop(t_data *data);
int			check_dead(t_data *data);
int			check_all_full(t_data *data);

// Utils
int			thread(pthread_t *t, void *(*f)(void *), void *arg, t_code code);
int			mutex(t_mutex *m, t_code code);
int			ft_atoi(char *str);
int			ft_strlen(char *str);
void		wait(uint64_t millisec);
uint64_t	get_time(void);

#endif