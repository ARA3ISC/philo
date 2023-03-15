/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 03:05:04 by maneddam          #+#    #+#             */
/*   Updated: 2023/03/15 14:28:27 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	check(const char *str, long int nb, int isneg, int i)
{
	if ((nb * 10 + str[i] - 48 < nb) && (isneg == 1))
	{
		// print_error("Out of range");
		return (-1);
	}
	if ((nb * 10 + str[i] - 48 + 1 < nb) && (isneg == -1))
	{
		// print_error("Out of range");
		return (-1);
	}
	return (1);
}

int	check_dupl_signs(const char *str, int i)
{
	if (((str[i] == '+' || str[i] == '-') && (str[i + 1] == '+' || str[i
					+ 1] == '-' || str[i + 1] == '\0')))
	{
		// print_error("Error");
		return (-1);
	}
	if (str[i] == '-')
		return (-1);
	return (1);
}

long int	ft_atoi(const char *str)
{
	long int	nb;
	int			isneg;
	int			i;

	nb = 0;
	isneg = 1;
	i = 0;
	while (str[i] == 32 || str[i] == '\t')
		i++;
	if (check_dupl_signs(str, i) < 0)
		return (-1);
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
		return (-1);
	while (is_digit(str[i]))
	{
		if (check(str, nb, isneg, i) < 0)
			return (-1);
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	return (nb * isneg);
}
