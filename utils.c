/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fee <fee@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 10:42:46 by ffidha            #+#    #+#             */
/*   Updated: 2024/07/21 17:08:51 by fee              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr_fd(char *s, int fd);
 
int	checkargs(int ac, char **av)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	if (ac < 5)
		return(bad("error: less than 5 arguments\n"));
	if (ac > 6)
		return(bad("error: more than 6 arguments\n"));
	if (av[1][0] == '0')
		return (bad("no philos found\n"), 1);
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!isdigit(av[i][j]))
				return (bad("arguments is negative"), 1);
			j++;
		}
		i++;
	}
	return (0);
}

void printit(char *reason)
{
	ft_putstr_fd(reason, 2);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s[i] == '\0')
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_atoi(const char *str)
{
	long			result;
	long			sign;
	unsigned int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result >= LONG_MAX / 10 && sign == 1)
			return (-1);
		else if (result >= LONG_MAX / 10 && sign == -1)
			return (0);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return ((int)result * sign);
}
