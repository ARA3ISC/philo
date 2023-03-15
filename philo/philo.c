/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:10:34 by maneddam          #+#    #+#             */
/*   Updated: 2023/03/15 15:34:07 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_philos(t_args *infos)
{
	infos->init_time = get_current_time();
	initializing_infos(infos);
}

int	main(int argc, char *argv[])
{
	t_args	infos;

	if (argc == 5 || argc == 6)
	{
		if (!get_infos(&infos, argc, argv) || !check_args(argv))
		{
			printf("Error\n");
			return (EXIT_FAILURE);
		}
		infos.forks = malloc(sizeof(pthread_mutex_t) * infos.philos_num);
		infos.philo = malloc(sizeof(t_philo) * infos.philos_num);
		if (!(infos.philo) || !(infos.forks))
		{
			print_error("Error");
			return (1);
		}
		initializing_mutexes(&infos);
		create_philos(&infos);
		sleep(1);
		destroy_mutexes(&infos);
	}
	return (0);
}
