/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 00:00:37 by maneddam          #+#    #+#             */
/*   Updated: 2023/02/25 23:26:34 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_infos(t_args *info, int argc, char *argv[])
{
	if (argc == 6)
		info->max_eaten = 1;
	if (ft_atoi(argv[1]) > INT_MAX || ft_atoi(argv[2]) > INT_MAX
		|| ft_atoi(argv[3]) > INT_MAX || ft_atoi(argv[4]) > INT_MAX)
		print_error("Out of range");
	info->philos_num = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		info->max_eaten = ft_atoi(argv[5]);
		if (ft_atoi(argv[5]) > INT_MAX)
			print_error("Out of range");
	}
}

long	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	initializing_mutexes(t_args *infos)
{
	int	i;

	i = 0;
	pthread_mutex_init(&infos->print_mutex, NULL);
	while (i < infos->philos_num)
	{
		if (pthread_mutex_init(&infos->forks[i], NULL) != 0)
			print_error("Initializing mutex failed");
		i++;
	}
}

void	destroy_mutexes(t_args *infos)
{
	int	i;

	i = 0;
	while (i < infos->philos_num)
	{
		if (pthread_mutex_destroy(&infos->forks[i]) != 0)
			print_error("Destroying mutex failed");
		i++;
	}
}

void	ft_sleep(int time_to_eat)
{
	long time;
	time = get_current_time();

	while (get_current_time() - time < time_to_eat)
		usleep(100);
}
void	print_message(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->infos->print_mutex);
	printf("%ld ms %d %s\n", get_current_time() - philo->infos->init_time ,philo->id + 1, str);
	pthread_mutex_unlock(&philo->infos->print_mutex);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->infos->forks[philo->right_fork]);
	print_message(philo, "has taken a fork\n");
	pthread_mutex_lock(&philo->infos->forks[philo->left_fork]);

	print_message(philo, "has taken a fork\n");
	print_message(philo, "is eating\n");
	philo->eaten_meals++;
	philo->last_eat_time = get_current_time();
	ft_sleep(philo->infos->time_to_eat);
	pthread_mutex_unlock(&philo->infos->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->infos->forks[philo->right_fork]);
}

void	*actions(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
		eating(philo);

	return (NULL);
}

void	initializing_infos(t_args *infos)
{
	int	i;

	i = 0;
	while (i < infos->philos_num)
	{
		infos->philo[i].id = i;
		infos->philo[i].eaten_meals = 0;
		infos->philo[i].right_fork = i;
		infos->philo[i].last_eat_time = infos->init_time;

		if (i == infos->philos_num - 1)
			infos->philo[i].left_fork = infos->philo[0].right_fork;
		else
			infos->philo[i].left_fork = i + 1;

		pthread_create(&infos->philo[i].thread, NULL, &actions, &infos->philo[i]);
		usleep(200);
		printf("hh\n");
		i++;
	}

	i = 0;
	while (i < infos->philos_num)
	{
		pthread_join(infos->philo[i].thread, NULL);
		i++;
	}
}
