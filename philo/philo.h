/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 01:34:24 by maneddam          #+#    #+#             */
/*   Updated: 2023/02/28 19:08:03 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define RED "\e[1;31m"
# define PURPLE "\e[35m"
# define RESET "\n\033[0m"
# define GREEN "\033[0;32m"

typedef struct philosophers
{
	pthread_t			thread;
	int					id;
	int					right_fork;
	int					left_fork;
	long				last_eat_time;
	int					eaten_meals;
	struct s_args		*infos;
}						t_philo;

typedef struct s_args
{
	int					philos_num;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					max_eaten;
	int					max;
	long				init_time;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		time_mutex;
	pthread_mutex_t		*forks;
	struct philosophers	*philo;
}						t_args;

void					print_error(char *msg);
long int				ft_atoi(const char *str);
void					check_args(char *argv[]);
void					get_infos(t_args *info, int argc, char *argv[]);
long					get_current_time(void);
void					initializing_mutexes(t_args *infos);

void					destroy_mutexes(t_args *infos);
void					initializing_infos(t_args *infos);

void					get_infos(t_args *info, int argc, char *argv[]);
long					get_current_time(void);
void					initializing_mutexes(t_args *infos);
void					destroy_mutexes(t_args *infos);

void					ft_sleep(int time_to_eat);
void					print_message(t_philo *philo, char *str, int i);
#endif
