/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doing_things.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:33:28 by ffidha            #+#    #+#             */
/*   Updated: 2024/07/30 19:46:18 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	eat(t_philo *philo)
{
	int		rn;

	rn = DONE;
	if (print_philo_state(philo, -1) == DEAD)
		rn = DEAD;
	philo->last_eat = get_time();
	if (sleepy(philo, philo->data->time_to_eat) == DEAD)
		rn = DEAD;
	pthread_mutex_lock(philo->left_mutex);
	*philo->left_fork = philo->id;
	pthread_mutex_unlock(philo->left_mutex);
	pthread_mutex_lock(philo->right_mutex);
	*philo->right_fork = philo->id;
	pthread_mutex_unlock(philo->right_mutex);
	philo->neat++;
	philo->state = SLEEP;
	return (rn);
}

int	slep(t_philo *philo)
{
	int		rn;

	rn = print_philo_state(philo, -1);
	if (rn == DEAD)
		return (DEAD);
	if (sleepy(philo, philo->data->time_to_sleep) == DEAD)
		return (DEAD);
	rn = print_philo_state(philo, DEAD);
	philo->state = THINK;
	return (rn);
}

int	thunk(t_philo *philo)
{
	int		rn;

	rn = print_philo_state(philo, -1);
	philo->state = PICK_FORK;
	return (rn);
}
