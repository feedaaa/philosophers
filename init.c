/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:10:21 by ffidha            #+#    #+#             */
/*   Updated: 2024/06/24 13:08:44 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <semaphore.h>
void init_philo(t_data *data, char **av);

void	init(char **av, t_data *data, t_philo *philo)
{
	int		philos;

	philos = ft_atoi(av[1]);
	data->tphilos = philos;
	data->resources = philo;
	if(data->resources = NULL)
	{
		bad("error: allocation failed\n");
		exit(1);
	}
	data->white_flag = 0;
	pthread_mutex_init(&data->did_he_die, NULL);
	pthread_mutex_init(&data->write, NULL);
	init_philo(data, av);
}

void init_philo(t_data *data, char **av)
{
	int		i;
	
	i = -1;
	while (++i < data->tphilos)
	{
		pthread_mutex_init(&data->resources[i].perished_philo, NULL);
		data->resources[i].kill_all = 0;
		data->resources[i].meals_done = 0;
		data->resources[i].philo = i + 1;
		data->resources[i].hour_of_demise = ft_atoi(av[2]);
		data->resources[i].time_to_eat = ft_atoi(av[3]);
		data->resources[i].time_to_sleep = ft_atoi(av[4]);
		if (av[5])
			data->resources[i].meals = ft_atoi(av[5]);
		else
			data->resources[i].meals = -1;
		data->resources[i].last_meal_time = get_time(); //create
		data->resources[i].data = data;
		pthread_mutex_init(&data->resources[i].left_fork, NULL);
		if (i == data->tphilos - 1)
			data->resources[i].right_fork = &data->resources[0].left_fork;
		else
			data->resources[i].right_fork = &data->resources[i + 1].left_fork;
	}
}