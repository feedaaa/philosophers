/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doing_things.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:07:39 by ffidha            #+#    #+#             */
/*   Updated: 2024/06/30 17:11:41 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eat(t_philo *philo, t_data *data);
void	*monitor(void *arg);
void	*routine(void *arg);
void	ssleep(size_t ms);

void	*dinner(t_data *data)
{
	pthread_t		moniter_thread;
	int				i;

	i = -1;
	while (++i && data->tphilos && !data->white_flag)
	{
		if (pthread_create(&data->resources[i].thread, NULL,
				routine, &data->resources[i]) != 0)
		{
				return (printf("error: pthread_create()/n"), NULL);
	}
	}
	if (pthread_create(&moniter_thread, NULL, monitor, data) != 0)
		return(printf("error: pthread_create()\n"), NULL);
	if (data->white_flag)
		return (NULL);
	i = -1;
	while (++i < data->tphilos)
	{
		if (pthread_join(data->resources[i].thread, NULL) != 0)
			return (printf("pthread_join() error 1"), NULL);
	}
	if (pthread_join(moniter_thread, NULL) != 0)
		return (printf("error: pthread_join()\n"), NULL);
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->tphilos == 1)
		return (handle_one(philo->data), NULL);
	if (philo->philo % 2 == 0)
		ssleep(philo->time_to_eat - 10);
	printf("%d\n", philo->philo);
	while (philo->kill_all && philo->meals)
	{
		if (!philo->kill_all)
		{
			printf("%d\n", philo->philo);
			eat(philo, philo->data);
			if (philo->kill_all || !philo->meals)
				return (NULL);
			if (!philo->kill_all)
				print_write(philo->data, philo->philo, SLEEP);
			if (!philo->kill_all)
				ssleep(philo->time_to_sleep);
			if (!philo->kill_all)
				print_write(philo->data, philo->philo, THINK);
		}
	}
	return (NULL);
}

int	check_philosopher(t_data *data, int i)
{
	pthread_mutex_lock(&data->resources[i].perished_philo);
	if ((get_time() - data->resources[i].last_meal_time)
		>= data->resources[i].hour_of_demise)
	{
		print_write(data, data->resources[i].philo, "died");
		every_die(data);
		data->white_flag = 1;
	}
	pthread_mutex_unlock(&data->resources[i].perished_philo);
	return (data->white_flag);
}

void	*monitor(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (!data->white_flag)
	{
		i = -1;
		while (++i < data->tphilos && !data->white_flag)
		{
			if (!data->resources[i].meals)
				return (NULL);
			if (check_philosopher(data, i))
				return (NULL);
		}
		printf("%d\n", i);
		usleep(350);
	}
	return (NULL);
}

void	ssleep(size_t ms)
{
	size_t	start_time;

	start_time = get_time();
	while ((get_time() - start_time) < (size_t)ms)
		usleep(500);
}

int	eat(t_philo *philo, t_data *data)
{
	if (!philo->kill_all)
	{
		pthread_mutex_lock(philo->right_fork);
		print_write(data, philo->philo, TAKE_FORK);
		pthread_mutex_lock(&philo->left_fork);
		print_write(data, philo->philo, TAKE_FORK);
		pthread_mutex_lock(&data->did_he_die);
		philo->last_meal_time = get_time();
		ssleep(philo->time_to_eat);
		if (philo->meals > 0)
			philo->meals--;
		if (philo->meals == 0)
			philo->meals_done = 1;
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(&philo->left_fork);
	}
	return (0);
}