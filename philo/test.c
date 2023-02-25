/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:44:25 by maneddam          #+#    #+#             */
/*   Updated: 2023/02/25 16:50:34 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
	#include <windows.h>
#else
	#include <unistd.h>
#endif

void
my_wait(size_t secs)
{
	#ifdef _WIN32
		Sleep(1000 * secs);
	#else
		sleep(secs);
	#endif
}

void
print_progress(size_t count, size_t max)
{
	const char prefix[] = "Progress: [";
	const char suffix[] = "]";
	const size_t prefix_length = sizeof(prefix) - 1;
	const size_t suffix_length = sizeof(suffix) - 1;
	char *buffer = calloc(max + prefix_length + suffix_length + 1, 1); // +1 for \0
	size_t i = 0;

	strcpy(buffer, prefix);
	for (; i < max; ++i)
	{
		buffer[prefix_length + i] = i < count ? '#' : ' ';
	}

	strcpy(&buffer[prefix_length + i], suffix);
	printf("\b%c[2K\r%s\n", 27, buffer);
	fflush(stdout);
	free(buffer);
}

#define NUM_SECS 10

int
main()
{
	size_t num_secs = 1, max_secs = NUM_SECS;
	printf("%s\n", "");
	print_progress(0, max_secs);
	for (; num_secs <= max_secs; ++num_secs)
	{
		my_wait(1);
		print_progress(num_secs, max_secs);
	}

	return 0;
}