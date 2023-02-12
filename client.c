/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:58:47 by aalami            #+#    #+#             */
/*   Updated: 2023/02/06 18:09:15 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	check_arg(char *arg)
{
	if (arg == NULL || !ft_strlen(arg))
		return (0);
	else
		return (1);
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
			j = 7;
			while (j >= 0)
			{
				if ((argv[2][i] >> j) & 1)
					kill(ft_atoi(argv[1]), SIGUSR1);
				else
					kill(ft_atoi(argv[1]), SIGUSR2);
				usleep(750);
				j--;
			}
			i++;
		}
	}
	else
		write (1, "Error\n", 6);
}
