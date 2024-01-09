/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaltine <akifnuman@student.42kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:41:57 by akaltine          #+#    #+#             */
/*   Updated: 2023/10/12 03:03:59 by akaltine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sendbit(int pid, char *str)
{
	int	bit;

	while (*str)
	{
		bit = 7;
		while (bit >= 0)
		{
			if (*str >> bit & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			bit--;
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		write(1, "ARGUMAN HATASI!", 15);
		write(1, "(client, pid, string)\n", 22);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	ft_sendbit(pid, argv[2]);
	ft_sendbit(pid, "\n");
	return (0);
}
