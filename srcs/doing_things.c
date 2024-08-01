/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doing_things.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:26:18 by ffidha            #+#    #+#             */
/*   Updated: 2024/08/01 13:26:20 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	eat(t_philo *philo)
{
	int		ret;

	ret = DONE;
	if (print_philo_state(philo, -1) == DEAD)
		ret = DEAD;
	philo->last_eat = get_time();
	if (sleepy(philo, philo->data->time_to_eat) == DEAD)
		ret = DEAD;
	pthread_mutex_lock(philo->left_mutex);
	*philo->left_fork = philo->id;
	pthread_mutex_unlock(philo->left_mutex);
	pthread_mutex_lock(philo->right_mutex);
	*philo->right_fork = philo->id;
	pthread_mutex_unlock(philo->right_mutex);
	philo->neat++;
	philo->state = SLEEP;
	return (ret);
}

int	slep(t_philo *philo)
{
	int		ret;

	ret = print_philo_state(philo, -1);
	if (ret == DEAD)
		return (DEAD);
	if (sleepy(philo, philo->data->time_to_sleep) == DEAD)
		return (DEAD);
	ret = print_philo_state(philo, DEAD);
	philo->state = THINK;
	return (ret);
}

int	thunk(t_philo *philo)
{
	int		ret;

	ret = print_philo_state(philo, -1);
	philo->state = PICK_FORK;
	return (ret);
}
