/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:32:42 by ffidha            #+#    #+#             */
/*   Updated: 2024/07/30 13:45:35 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	checkargs(int ac, char **av)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	if (ac < 5)
		return(printit("error: less than 5 arguments\n"));
	if (ac > 6)
		return(printit("error: more than 6 arguments\n"));
	if (av[1][0] == '0')
		return (printit("no philos found\n"), 1);
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!isdigit(av[i][j]))
				return (printit("arguments is negative"), 1);
			j++;
		}
		i++;
	}
	return (0);
}
