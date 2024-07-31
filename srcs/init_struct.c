#include "../includes/philo.h"

int	init_forks(t_table **table, int num)
{
	int		i;

	i = -1;
	(*table)->forks = (int *)malloc(sizeof(int) * num);
	if (!(*table)->forks)
	{
		free(*table);
		printit("philo: error: malloc() failed");
		return (ERROR);
	}
	while (++i < num)
		(*table)->forks[i] = -1;
	return (DONE);
}

t_table	*init_table(char **av)
{
	t_table		*table;

	table = (t_table *)malloc(sizeof(t_table));
	if (!table)
	{
		printit("philo: error: malloc() failed");
		return (NULL);
	}
	table->mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* ft_atoi(av[1]));
	table->threads = (pthread_t *)malloc(sizeof(pthread_t) * ft_atoi(av[1]));
	if (!table->mutex || !table->threads)
	{
		printit("philo: error: malloc() failed");
		if (table->mutex)
			free(table->mutex);
		if (table->threads)
			free(table->threads);
		free(table);
		return (NULL);
	}
	table->check_death = 0;
	if (init_forks(&table, ft_atoi(av[1])) == ERROR)
		return (NULL);
	return (table);
}

t_data	*init_data(char **av)
{
	t_data		*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
	{
		printit("philo: error: malloc() failed");
		return (NULL);
	}
	data->num = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		data->cycle = ft_atoi(av[5]);
	else
		data->cycle = -1;
	if (data->num == 0 || data->time_to_die == 0
		|| data->time_to_eat == 0 || data->time_to_sleep == 0)
	{
		printit("philo: error: argument is 0");
		free(data);
		return (NULL);
	}
	return (data);
}

void	all_data_init(t_table *table, t_philo *philo, int id)
{
	(*philo).id = id;
	(*philo).state = PICK_FORK;
	(*philo).check_death = &table->check_death;
	(*philo).start_time = &table->start_time;
	(*philo).left_forkn = id;
	(*philo).left_fork = &table->forks[id - 1];
	(*philo).left_mutex = &table->mutex[id - 1];
	if (id == table->data->num)
	{
		(*philo).right_forkn = 1;
		(*philo).right_fork = &table->forks[0];
		(*philo).right_mutex = &table->mutex[0];
	}
	else
	{
		(*philo).right_forkn = id + 1;
		(*philo).right_fork = &table->forks[id];
		(*philo).right_mutex = &table->mutex[id];
	}
	(*philo).data = table->data;
	(*philo).neat = 0;
	(*philo).last_eat = 0;
	(*philo).print = &table->print;
}

t_philo	*init_philo(t_table *table)
{
	int			i;
	t_philo		*philo;

	i = -1;
	philo = (t_philo *)malloc(sizeof(t_philo) * (table->data->num));
	if (!philo)
	{
		free(table);
		printit("philo: error: malloc() failed");
		return (NULL);
	}
	while (++i < table->data->num)
		all_data_init(table, &(philo[i]), i + 1);
	return (philo);
}
