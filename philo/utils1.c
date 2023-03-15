/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 00:00:37 by maneddam          #+#    #+#             */
/*   Updated: 2023/03/15 15:20:45 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	// lock forks and print situation
	pthread_mutex_lock(&philo->infos->forks[philo->right_fork]);
	print_message(philo, "has taken a fork", 1);
	pthread_mutex_lock(&philo->infos->forks[philo->left_fork]);
	print_message(philo, "has taken a fork", 1);
	print_message(philo, "is eating", 1);

	// reading mutex locked
	pthread_mutex_lock(&philo->infos->read_mutex);
	philo->eaten_meals++;
	pthread_mutex_unlock(&philo->infos->read_mutex);
	// reading mutex unlocked

	// incrementing mutex locked
	pthread_mutex_lock(&philo->infos->increment_mutex);
	philo->infos->max++;
	pthread_mutex_unlock(&philo->infos->increment_mutex);
	// incrementing mutex unlocked

	// lock time mutex
	pthread_mutex_lock(&philo->infos->time_mutex);
	philo->last_eat_time = get_current_time();
	pthread_mutex_unlock(&philo->infos->time_mutex);
	// incrementing mutex unlocked

	// sleep
	ft_sleep(philo->infos->time_to_eat);

	// unlock forks
	pthread_mutex_unlock(&philo->infos->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->infos->forks[philo->right_fork]);
}

void	*actions(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2)
		usleep(200);
	while (1)
	{
		eating(philo);
		print_message(philo, "is sleeping", 1);
		ft_sleep(philo->infos->time_to_sleep);
		print_message(philo, "is thinking", 1);
	}
}

int	check_death(t_args *infos, int i)
{
	i = 0;
	while (i < infos->philos_num)
	{
		pthread_mutex_lock(&infos->time_mutex);
		if (get_current_time() - infos->philo[i].last_eat_time > infos->time_to_die)
		{
			printf(RED);
			print_message(&infos->philo[i], "is died ☠️", 0);
			printf(RESET);
			return (1);
		}

		pthread_mutex_unlock(&infos->time_mutex);
		pthread_mutex_lock(&infos->read_mutex);
		pthread_mutex_lock(&infos->time_mutex);

		pthread_mutex_lock(&infos->increment_mutex);
		if (infos->is_max_specified && infos->max == infos->max_eaten * infos->philos_num)
		{
			pthread_mutex_lock(&infos->print_mutex);
			printf(RED);
			printf("%d has eaten max meals\n", infos->philo[i].id + 1);
			printf(RESET);
			return (1);
		}
		pthread_mutex_unlock(&infos->read_mutex);
		pthread_mutex_unlock(&infos->time_mutex);
		pthread_mutex_unlock(&infos->increment_mutex);

		i++;
	}
	return (0);
}

void	creating_threads(t_args *infos, int i)
{
	while (i < infos->philos_num)
	{
		infos->philo[i].id = i;
		infos->philo[i].eaten_meals = 0;
		infos->philo[i].right_fork = i;
		infos->philo[i].infos = infos;
		infos->philo[i].last_eat_time = infos->init_time;
		if (i == infos->philos_num - 1)
			infos->philo[i].left_fork = infos->philo[0].right_fork;
		else
			infos->philo[i].left_fork = i + 1;
		if (pthread_create(&infos->philo[i].thread, NULL, &actions,
				&infos->philo[i]) != 0)
		{
			print_error("creating thread failed");
			return ;
		}
		i++;
	}
}

void	initializing_infos(t_args *infos)
{
	int	i;

	i = 0;
	creating_threads(infos, i);
	while (1)
		if (check_death(infos, i))
			return ;
}
