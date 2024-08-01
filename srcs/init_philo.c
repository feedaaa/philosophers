/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:26:37 by ffidha            #+#    #+#             */
/*   Updated: 2024/08/01 13:26:40 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_mutex(t_table **table)
{
	int		i;

	i = -1;
	if (pthread_mutex_init(&(*table)->print, NULL))
	{
		printit("philo: error: mutex");
		clean_table(*table);
		return (ERROR);
	}
	while (++i < (*table)->data->num)
	{
		if (pthread_mutex_init(&(*table)->mutex[i], NULL))
		{
			printit("philo: error: mutex");
			clean_table(*table);
			return (ERROR);
		}
	}
	return (DONE);
}

static int	creat_threads(t_table **table)
{
	int		i;

	i = -1;
	(*table)->start_time = get_time();
	while (++i < (*table)->data->num)
	{
		if (pthread_create(&(*table)->threads[i],
				NULL, &circle_of_life, &(*table)->philo[i]))
		{
			printit("philo: error: pthread create failed");
			clean_table(*table);
			return (ERROR);
		}
	}
	return (DONE);
}

int	init_threads(t_table **table)
{
	if (init_mutex(table) == ERROR)
		return (ERROR);
	if (creat_threads(table) == ERROR)
		return (ERROR);
	return (DONE);
}
