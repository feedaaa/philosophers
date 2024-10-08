/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:26:24 by ffidha            #+#    #+#             */
/*   Updated: 2024/08/01 13:26:27 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_fork(t_philo *philo, pthread_mutex_t *lock, int f)
{
	int		*fork;
	int		forkn;
	int		rn;

	pthread_mutex_lock(lock);
	if (!f)
	{
		fork = philo->left_fork;
		forkn = philo->left_forkn;
	}
	else
	{
		fork = philo->right_fork;
		forkn = philo->right_forkn;
	}
	if ((*fork != philo->id && *fork != 0 && *fork != -1)
		|| (*fork == -1 && philo->id % 2 != 0))
	{
		*fork = USED_FORKS;
		rn = print_philo_state(philo, forkn);
	}
	else
		rn = ERROR;
	pthread_mutex_unlock(lock);
	return (rn);
}

static void	which_fork(t_philo *philo, int *side, pthread_mutex_t **lock, int f)
{
	if (f == 0)
	{
		if (philo->id % 2 == 0)
		{
			*side = LEFT;
			*lock = philo->left_mutex;
		}
		else
		{
			*side = RIGHT;
			*lock = philo->right_mutex;
		}
		return ;
	}
	if (philo->id % 2 == 0)
	{
		*side = RIGHT;
		*lock = philo->right_mutex;
	}
	else
	{
		*side = LEFT;
		*lock = philo->left_mutex;
	}
}

int	forks(t_philo *philo)
{
	int				rn;
	int				side;
	int				fork_check;
	pthread_mutex_t	*lock;

	fork_check = 0;
	which_fork(philo, &side, &lock, fork_check);
	while (fork_check < 2)
	{
		if (philo->neat == 0 && fork_check == 0)
			philo->last_eat = get_time();
		rn = check_fork(philo, lock, side);
		if (rn == DONE)
		{
			fork_check++;
			which_fork(philo, &side, &lock, fork_check);
		}
		else if (rn == DEAD)
			return (DEAD);
		if (print_philo_state(philo, DEAD) == DEAD)
			return (DEAD);
	}
	philo->state = EAT;
	return (DONE);
}
