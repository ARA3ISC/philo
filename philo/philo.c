/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 01:38:38 by maneddam          #+#    #+#             */
/*   Updated: 2023/02/25 23:26:20 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



void	create_philos(t_args *infos)
{
	// int	i;
	int	num;


	num = infos->philos_num;



	if (!(infos->philo))
		print_error("Error");
	infos->init_time = get_current_time();

	initializing_infos(infos);
	exit(1);
	// printf("hh\n");




}

int	main(int argc, char *argv[])
{
	t_args	*infos;

	if (argc == 5 || argc == 6)
	{
		infos = malloc(sizeof(t_args));
		get_infos(infos, argc, argv);


		// printf("%d\n", infos->philos_num);
		// exit(1);

		infos->forks = malloc(sizeof(pthread_mutex_t) * infos->philos_num);
		infos->philo = malloc(sizeof(t_philo) * infos->philos_num);

		check_args(argv);
		initializing_mutexes(infos);
		create_philos(infos);


		// printf("\ncurrent time --> %ld\n\n", get_current_time());
		// while (get_current_time() - infos.init_time < 200)
		// 	usleep(100);
		// printf("\ninit time --> %ld\n", infos.init_time);
		// printf("\nlferq --> %ld\n\n", get_current_time() - infos.init_time);
		// exit(0);

		// destroy_mutexes(&infos);
	}
	return (0);
}
