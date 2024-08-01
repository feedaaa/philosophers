

#include "../includes/philo.h"

void	death_record(int n, int current)
{
	ft_putstr_fd(RED, 1);
	ft_putnbr_fd(current, 1);
	ft_putstr_fd(" ", 2);
	ft_putnbr_fd(n, 1);
	ft_putstr_fd(RESET RED" died 💀\n", 1);
	ft_putstr_fd(RESET, 1);
}

int	check_death(size_t last_eat, size_t death_time)
{
	size_t	current;

	current = get_time();
	if (current - last_eat > death_time && last_eat != 0)
		return (DEAD);
	else
		return (DONE);
}

int	print_philo_state(t_philo *philo, int fork_n)
{
	size_t	current;

	pthread_mutex_lock(philo->print);
	current = time_stamp(*philo->start_time);
	if (*philo->check_death == DEAD
		|| check_death(philo->last_eat, philo->data->time_to_die) == DEAD)
	{
		if (*philo->check_death != DEAD)
			death_record(philo->id, current);
		*philo->check_death = DEAD;
		pthread_mutex_unlock(philo->print);
		return (DEAD);
	}
	else if (*philo->check_death != DEAD && fork_n != DEAD)
		pick_record(philo, current);
	pthread_mutex_unlock(philo->print);
	return (DONE);
}

void	*circle_of_life(void *p)
{
	t_philo		*philo;

	philo = (t_philo *)p;
	while (1)
	{
		if (forks(philo) == DEAD)
			break ;
		if (eat(philo) == DEAD)
			break ;
		if (slep(philo) == DEAD)
			break ;
		if (thunk(philo) == DEAD)
			break ;
		if (philo->data->cycle != -1 && philo->neat == philo->data->cycle)
			break ;
	}
	return (NULL);
}
