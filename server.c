/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:37:16 by aalami            #+#    #+#             */
/*   Updated: 2023/02/12 18:00:19 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minitalk.h"

void	handler_sig(int sign, siginfo_t *info, void *ptr)
{
	static int	i;
	static int	dec;
	static int	client_pid;

	ptr = NULL;
	if (info->si_pid != client_pid)
	{
		dec = 0;
		i = 0;
		client_pid = info->si_pid;
	}
	dec |= (sign == SIGUSR1);
	if (i == 7)
	{
		i = 0;
		ft_putchar_fd(dec, 1);
		dec = 0;
	}
	else
	{
		dec <<= 1;
		i++;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handler_sig;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	write (1, "PID : ", 6);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		sleep(1);
	}
	return (0);
}
