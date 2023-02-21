/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 01:38:38 by maneddam          #+#    #+#             */
/*   Updated: 2023/02/21 03:38:47 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_infos(t_args *info, int argc, char *argv[])
{
	if (argc == 6)
			info->option_arg = 1;
	info->philos_num = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (info->option_arg)
		info->option_arg = ft_atoi(argv[5]);
}

int	main(int argc, char *argv[])
{
	t_args info;
	if (argc == 5 || argc == 6)
	{
		get_infos(&info, argc, argv);
		// numbering_philos();

		printf("number of philo and forks : %d\n", info.philos_num);
		printf("time to die : %d milliseconds\n", info.time_to_die);
		printf("time to eat : %d milliseconds\n", info.time_to_eat);
		printf("time to sleep : %d milliseconds\n", info.time_to_sleep);
		if (info.option_arg)
			printf("number of times each philosopher must eat : %d times\n", info.option_arg);
	}
	return (0);
}
