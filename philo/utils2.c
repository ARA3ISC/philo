/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:53:26 by maneddam          #+#    #+#             */
/*   Updated: 2023/02/28 19:06:36 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(int time_to_eat)
{
	long	time;

	time = get_current_time();
	while (get_current_time() - time < time_to_eat)
		usleep(100);
}

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
	info->max = 0;
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
	pthread_mutex_init(&infos->time_mutex, NULL);
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
	if (pthread_mutex_destroy(&infos->print_mutex) != 0)
		return ;
	if (pthread_mutex_destroy(&infos->time_mutex) != 0)
		return ;
	while (i < infos->philos_num)
	{
		if (pthread_mutex_destroy(&infos->forks[i]) != 0)
			return ;
		i++;
	}
}
