/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fee <fee@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:58:06 by ffidha            #+#    #+#             */
/*   Updated: 2024/07/21 17:08:42 by fee              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table *init(char **av)
{
	t_table *table;
	table = init_table(av);
	if (!table)
		return(NULL);
	table->data = init_data(av);
	if(!table->data)
	{
		free(table->forks);
		free(table);
		return(NULL);
	}
	table->philo = init_philo(table);
	if(!table->philo)
	{
		free(table->data);
		free(table->forks);
		free(table);
		return(NULL);
	}
	return(table);
}
int philo(int ac, char **av)
{
	t_table *table;
	if(check_args(ac, av) == ERROR)
		return(ERROR);
	table = init(av);
	if (!table)
		return(ERROR);
	if (init_threads(&table) == ERROR)
		return(ERROR);
	collect_philo(&table);
	clean_table(table);
	return(DONE);
}
int main(int ac, char **av)
{
	if (philo(ac, av) == ERROR);
		return (EXIT_FAILURE);
	return(EXIT_SUCCESS);
}
