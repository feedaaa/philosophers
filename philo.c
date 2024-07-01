/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:58:06 by ffidha            #+#    #+#             */
/*   Updated: 2024/06/30 17:10:29 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_data		table;
	t_philo		philo[200];

	if (checkargs(ac, av))
		return (0);
	if (ft_atoi(av[1]) > 200)
		return(bad("too many philosophers, the table isnt that big\n"));
	init(av, &table, philo);
	dinner(&table);
	//destroy the threads
	return (0);
}
