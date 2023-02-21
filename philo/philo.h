/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 01:34:24 by maneddam          #+#    #+#             */
/*   Updated: 2023/02/21 03:09:40 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_args
{
	int philos_num;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int option_arg;
}			t_args;

void	print_error(char *msg);
long int	ft_atoi(const char *str);


#endif
