
#include "../includes/philo.h"

void	clean_table(t_table *table)
{
	free(table->forks);
	free(table->threads);
	free(table->mutex);
	free(table->philo);
	free(table->data);
	free(table);
}

static void	join_threads(t_table **table)
{
	int		i;

	i = -1;
	while (++i < (*table)->data->num)
	{
		if (pthread_join((*table)->threads[i], NULL))
			printit("philo: error: pthread_join() failed");
	}
}

static void	destroy_mutex(t_table **table)
{
	int		i;

	i = -1;
	while (++i < (*table)->data->num)
	{
		if (pthread_mutex_destroy(&(*table)->mutex[i]))
			printit("philo: nutex destroy failed");
	}
	if (pthread_mutex_destroy(&(*table)->print))
		printit("philo: nutex destroy failed");
}

void	collect_philo(t_table **table)
{
	join_threads(table);
	destroy_mutex(table);
}
