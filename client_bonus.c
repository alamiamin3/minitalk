/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:08:19 by aalami            #+#    #+#             */
/*   Updated: 2023/02/12 19:36:34 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	g_len;

int	check_arg(char *arg)
{
	if (arg == NULL || !ft_strlen(arg))
		return (0);
	else
		return (1);
}

void	handler(int sig)
{
	if (sig == SIGUSR1)
		g_len++;
	usleep(80);
}

void	notify_message(void)
{
	write(1, "THE MESSAGE WAS SENT SUCCESSFULLY\n", 34);
	exit (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (argc == 3 && check_arg(argv[2]) && ft_atoi(argv[1]) > 0)
	{
		while (argv[2][i] != '\0')
		{
			j = 8;
			while (--j >= 0)
			{
				if ((argv[2][i] >> j) & 1)
					kill(ft_atoi(argv[1]), SIGUSR1);
				else
					kill(ft_atoi(argv[1]), SIGUSR2);
				usleep(550);
				signal(SIGUSR1, handler);
				if (g_len == ft_strlen(argv[2]))
					notify_message();
			}
			i++;
		}
	}
	else
		write(1, "ERROR\n", 6);
}
