/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:32:54 by ffidha            #+#    #+#             */
/*   Updated: 2024/07/30 13:59:48 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	death_record(int n, int current_philo)
{
	ft_putstr_fd(RED, 1);
	ft_putnbr_fd(current_philo, 1);
	ft_putstr_fd(" : philo "BOLDRED, 1);
	ft_putnbr_fd(n, 1);
	ft_putstr_fd(RESET RED" is dead 💣\n", 1);
	ft_putstr_fd(RESET, 1);
}

int	check_death(size_t last_meal, size_t death_time)
{
	size_t	current;

	current = get_time();
	if(current - last_meal > death_time && last_meal != 0)
		return(DEAD);
	else
		return(DONE);
}

int	print_philo_state(t_philo *philo, int num_fork)
{
	size_t	current;
	pthread_mutex_lock(philo->print);
	current = time_stamp(*philo->start_time); //time stamp : to do
	if(*philo->check_death == DEAD
		|| check_death(philo->last_eat, philo->data->time_to_die) == DEAD)
	{
		if(*philo->check_death != DEAD)
			death_record(philo->id, current);
		*philo->check_death = DEAD;
		pthread_mutex_unlock(philo->print);
		return(DEAD);
	}
	else if(*philo->check_death != DEAD && num_fork != DEAD)
		pick_record(philo, current, num_fork);
	pthread_mutex_unlock(philo->print);
	return (DONE);
}

void	*circle_of_life(void *routine)
{
	t_philo		*philo;

	philo = (t_philo *)routine;
	while(1)
	{
		if(forks(philo) == DEAD)
			break;
		if(eat(philo) == DEAD)
			break;
		if(slep(philo) == DEAD)
			break;
		if(thunk(philo) == DEAD)
			break;
		if(philo->data->cycle != -1 && philo->neat == philo->data->cycle)
			break;
	}
	return (NULL);
}