/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 03:09:03 by maneddam          #+#    #+#             */
/*   Updated: 2023/03/15 14:41:07 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(t_philo *philo, char *str, int i)
{
	pthread_mutex_lock(&philo->infos->print_mutex);
	printf("%ld %d %s\n", get_current_time() - philo->infos->init_time,
		philo->id + 1, str);
		// printf("********* %d\n", i);
	// if ( !i )
		// exit ( 0 );
	if (i)
	{
		pthread_mutex_unlock(&philo->infos->print_mutex);
	}
}

void	print_error(char *msg)
{
	printf("%s !!\n", msg);
}

int	is_full_of_white_spaces(char *str)
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

int	invalid_arg(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i])
	{
		if ((str[i] != ' ' && !(str[i] >= '0' && str[i] <= '9') && str[i] != '+')
			|| is_full_of_white_spaces(str))
			return (1);
		i++;
	}
	return (0);
}

bool	check_args(char *argv[])
{
	int	i;
	int	j;
	int	count;

	i = 1;
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
		if (count > 1 || invalid_arg(argv[i]))
			return (0);
		i++;
	}
	return (1);
}
