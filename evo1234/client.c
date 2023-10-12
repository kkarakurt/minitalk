/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkarakur <kkarakur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:29:46 by kkarakur          #+#    #+#             */
/*   Updated: 2023/09/29 13:29:46 by kkarakur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>

void	signal_push(int pid, char *str)
{
	int	i;

	while (*str)
	{
		i = 7;
		while (i >= 0)
		{
			if (*str >> i-- & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
		str++;
	}
}

int	check(char *str)
{
	while (*str)
	{
		if (*str < 1)
			return (1);
		str++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc < 3 || !argv[2][0])
		return (write(2, "Error: Too less arguments.\n", 28), 1);
	else if (argc > 3)
		return (write(2, "Error: Too much arguments.\n", 28), 1);
	if (check(argv[2]) == 1)
		return (write(2, "Error: Extended ascii.\n", 24), 1);
	pid = ft_atoi(argv[1]);
	signal_push(pid, argv[2]);
	signal_push(pid, "\n");
	return (0);
}
