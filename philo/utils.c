/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 03:05:04 by maneddam          #+#    #+#             */
/*   Updated: 2023/02/21 03:33:46 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

void	check(const char *str, long int nb, int isneg, int i)
{
	if ((nb * 10 + str[i] - 48 < nb) && (isneg == 1))
		print_error("error");
	if ((nb * 10 + str[i] - 48 + 1 < nb) && (isneg == -1))
		print_error("error");
}

void	check_dupl_signs(const char *str, int i)
{
	if (((str[i] == '+' || str[i] == '-') && (str[i + 1] == '+' || str[i + 1] == '-' || str[i + 1] == '\0')))
		print_error("Error");
	if (str[i] == '-')
		print_error("Negative values are not allowed");
}

long int	ft_atoi(const char *str)
{
	long int	nb;
	int			isneg;
	int			i;

	nb = 0;
	isneg = 1;
	i = 0;
	check_dupl_signs(str, i);
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (is_digit(str[i]))
	{
		check(str, nb, isneg, i);
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9') && str[i])
		print_error("Only digits are allowed");
	return (nb * isneg);
}
