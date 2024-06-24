/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:58:06 by ffidha            #+#    #+#             */
/*   Updated: 2024/06/24 15:45:43 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	
}
// int mails = 0;
// pthread_mutex_t mutex;

// void* routine()
// {
// 	for (int i = 0; i < 10; i++)
// 	{
// 		pthread_mutex_lock(&mutex);
// 		mails++;
// 		pthread_mutex_unlock(&mutex);
// 	}
// 	return (NULL);
// }

// multithreaded process working
int main(int ac, char **av)
{
	t_data		data;
	pthread_t	philo[10];
	int			i;

	i = 0;
	if (checkargs(ac, av))
		return (0);
	if (ft_atoi(av[1] > 200))
		return(bad("too many philosophers, the table isnt that big\n"));
	init(av, &data, philo);
	dinner(); //simulation
	// pthread_mutex_init(&mutex, NULL);
	// while (i < 10)
	// {
	// 	if (pthread_create(&philo[i], NULL, &routine, NULL) != 0)
	// 		bad("thread problems\n");
	// 	printf("philo %d has started execution\n", i);
	// 	i++;
	// }
	// while(i < 10)
	// {
	// 	pthread_join(philo[i], NULL);
	// 	printf("philo %d has finished execution\n", i);
	// 	i++;
	// }
	// pthread_mutex_destroy(&mutex);
	// printf("number of mails: %d\n", mails);
}

