/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:31:23 by ffidha            #+#    #+#             */
/*   Updated: 2024/07/30 13:23:26 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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