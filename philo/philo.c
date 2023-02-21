/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 01:38:38 by maneddam          #+#    #+#             */
/*   Updated: 2023/02/21 01:40:06 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// C program to show thread functions

#include "philo.h"

void	*func(void *arg)
{
	// detach the current thread
	// from the calling thread
	(void)arg;
	pthread_detach(pthread_self());
	printf("Inside the thread\n");
	// exit the current thread
	pthread_exit(NULL);
}

void	fun(void)
{
	pthread_t	ptid;

	// Creating a new thread
	pthread_create(&ptid, NULL, &func, NULL);
	printf("This line may be printed"
			" before thread terminates\n");
	// The following line terminates
	// the thread manually
	// pthread_cancel(ptid);
	// Compare the two threads created
	if (pthread_equal(ptid, pthread_self()))
		printf("Threads are equal\n");
	else
		printf("Threads are not equal\n");
	// Waiting for the created thread to terminate
	pthread_join(ptid, NULL);
	printf("This line will be printed"
			" after thread ends\n");
	pthread_exit(NULL);
}

// Driver code
int	main(void)
{
	fun();
	return (0);
}
