/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkarakur <kkarakur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:30:24 by kkarakur          #+#    #+#             */
/*   Updated: 2023/09/29 13:30:24 by kkarakur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>

void	ft_handler(int sig)
{
	static char	c = 0;
	static int	i = 128;

	if (sig == SIGUSR1)
		c += i;
	i /= 2;
	while (!i)
	{
		ft_putchar_fd(c, 1);
		i = 128;
		c = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putstr_fd("\n-----------------\n", 1);
	ft_putstr_fd("Process ID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n-----------------\n\n", 1);
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	while (1)
		pause();
	return (0);
}
