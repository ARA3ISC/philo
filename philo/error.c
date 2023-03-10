/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 03:09:03 by maneddam          #+#    #+#             */
/*   Updated: 2023/02/28 19:07:51 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(t_philo *philo, char *str, int i)
{
	pthread_mutex_lock(&philo->infos->print_mutex);
	printf("%ld %d %s\n", get_current_time() - philo->infos->init_time,
		philo->id + 1, str);
	if (i)
		pthread_mutex_unlock(&philo->infos->print_mutex);
}

void	print_error(char *msg)
{
	printf("%s !!\n", msg);
	exit(1);
}

int	is_full_of_whitespaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 32 && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

void	check_args(char *argv[])
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (argv[i])
	{
		j = 0;
		count = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] != 32 && argv[i][j + 1] == 32) || ((argv[i][j] != 32
						&& argv[i][j + 1] == '\0')))
				count++;
			j++;
		}
		if (count > 1 || is_full_of_whitespaces(argv[i]))
			print_error("Invalid argument");
		i++;
	}
}
