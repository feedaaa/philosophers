/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 10:42:46 by ffidha            #+#    #+#             */
/*   Updated: 2024/06/24 15:03:22 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	bad(char *reason);

 
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
				return (error("arguments is negative"), 1);
			j++;
		}
		i++;
	}
	return (0);
}

int	bad(char *reason)
{
	ft_putstr_fd(reason, 2);
	return (0);
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