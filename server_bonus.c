/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:08:12 by aalami            #+#    #+#             */
/*   Updated: 2023/02/12 19:25:52 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_data;

int	count_bytes(int dec)
{
	if (dec >= 240 && dec <= 247)
		return (4);
	else if (dec >= 224 && dec <= 239)
		return (3);
	else if (dec >= 192 && dec <= 223)
		return (2);
	else
		return (1);
}

void	reset_data(siginfo_t *info)
{
	if (info->si_pid != g_data.client_pid)
	{
		g_data.dec = 0;
		g_data.i = 0;
		ft_bzero(g_data.tab, g_data.byte_save);
		g_data.index = 0;
		g_data.client_pid = info->si_pid;
		g_data.bytes = 0;
	}
}

void	print_tab(int *tab, int nbr_bytes)
{
	int	i;

	i = 0;
	if (!g_data.bytes)
	{
		while (nbr_bytes)
		{
			write(1, &tab[i], 1);
			nbr_bytes --;
			i ++;
		}
		ft_bzero(g_data.tab, 4);
		g_data.index = 0;
	}
}

void	handler_function(int sign, siginfo_t *info, void *ptr)
{
	ptr = NULL;
	reset_data(info);
	g_data.dec |= (sign == SIGUSR1);
	if (g_data.i == 7)
	{
		if (!g_data.bytes)
		{
			g_data.bytes = count_bytes(g_data.dec);
			g_data.byte_save = g_data.bytes;
		}
		g_data.tab[g_data.index] = g_data.dec;
		kill(g_data.client_pid, SIGUSR1);
		g_data.i = 0;
		g_data.dec = 0;
		g_data.index ++;
		g_data.bytes--;
		print_tab(g_data.tab, g_data.byte_save);
	}
	else
	{
		g_data.dec <<= 1;
		g_data.i++;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handler_function;
	sa.sa_flags = SA_SIGINFO;
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
