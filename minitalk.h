/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:56:18 by aalami            #+#    #+#             */
/*   Updated: 2023/02/12 19:27:36 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include	<stdio.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<signal.h>

void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);

typedef struct s_data
{
	int	i;
	int	dec;
	int	client_pid;
	int	bytes;
	int	tab[4];
	int	index;
	int	byte_save;
}	t_data;
#endif