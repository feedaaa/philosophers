/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fee <fee@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:10:21 by ffidha            #+#    #+#             */
/*   Updated: 2024/07/07 09:39:46 by fee              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int init_forks(t_table **table, int count);

t_table *init_table(char **av);

t_data init_data(char **av);

void all_data(t_table *table, t_philo *philo, int id)
{
	(*philo).id = id;
	(*philo).state = PICK_FORK;
	(*philo).check_death = &table->check_death;
	(*philo).start_time = &table->start_time;
	(*philo).left_forkn = id;
	(*philo).left_fork = &table->forks[id - 1];
	(*philo).left_mutex = &table->mutex[id - 1];
	if (id == table->data->num)
	{
		(*philo).right_forkn = 1;
		(*philo).right_fork = &table->forks[0];
		(*philo).right_mutex = &table->mutex[0];
	}
	else
	{
		(*philo).right_forkn = id + 1;
		(*philo).right_fork = &table->forks[id];
		(*philo).right_mutex = &table->mutex[id];
	}
	(*philo).data = table->data;
	(*philo).neat = 0;
	(*philo).last_eat = 0;
	(*philo).print = &table->print;
}
void init_philo(t_table *table)
{
	int i;
	t_philo *philo;

	i = -1;
	philo = (t_philo *)malloc(sizeof(t_philo) * (table->data->num));
	if(!philo)
	{
		free(table);
		printit("philo failed: malloc error");
		return (NULL);
	}
	while(++i < table->data->num)
		all_data(table, &(philo[i]), i + 1);
	return (philo);
}