/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fee <fee@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:03:16 by ffidha            #+#    #+#             */
/*   Updated: 2024/07/29 11:54:36 by fee              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time(void)
{
	struct timeval	time;

	if ((gettimeofday(&time, NULL)) == -1)
	{
		printf("gettimeofday error!\n");
		return (0);
	}
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

size_t	time_stamp(time_t start)
{
	return(get_time() - start);
}

int	sleepy(t_philo *philo, size_t period)
{
	size_t	time;

	time = get_time();
	while(get_time() < time + period)
	{
		if(check_death(philo->last_eat, philo->data->time_to_die) == DEAD)
		{
			pthread_mutex_lock(philo->print);
			if(*philo->check_death != DEAD)
				death_record(philo->id, time_stamp(*philo->start_time));
			*philo->check_death = DEAD;
			pthread_mutex_unlock(philo->print);
			return (DEAD);
		}
		usleep(500);
	}
	return (DONE);
}