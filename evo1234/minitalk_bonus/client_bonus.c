/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkarakur <kkarakur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:44:41 by kkarakur          #+#    #+#             */
/*   Updated: 2023/10/12 16:44:41 by kkarakur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
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

int	main(int argc, char **argv)
{
	int	pid;

	if (argc < 3 || !argv[2][0])
		return (write(2, "Error: Too less arguments.\n", 28), 1);
	else if (argc > 3)
		return (write(2, "Error: Too much arguments.\n", 28), 1);
	pid = ft_atoi(argv[1]);
	signal_push(pid, argv[2]);
	signal_push(pid, "\n");
	return (0);
}
