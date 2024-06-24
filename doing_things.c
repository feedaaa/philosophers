/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doing_things.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:07:39 by ffidha            #+#    #+#             */
/*   Updated: 2024/06/24 19:44:02 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	think(t_philo *philo);

int ssleep(t_philo *philo);

int	eat(t_philo *philo);

void	*routine();

/* get the time
	create thread
		join thread
			do things(routines) for eating, sleeping and thinking */
void	*dinner(t_data *data)
{
	pthread_t		moniter_thread;
	int				i;

	i = -1;
	while (++i && data->tphilos && !data->white_flag)
	{
		if (pthread_create(&data->resources[i].thread, NULL,
				routine, &data->resources[i]) != 0)
				return (printf("error: pthread_create()/n"));
	}
	if (pthread_create(&moniter_thread, NULL, monitor, data) != 0)
		return(printf("pthread_create()\n"));
}
void	*routine();
void	*monitor()