/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:34:52 by ffidha            #+#    #+#             */
/*   Updated: 2024/06/24 15:43:41 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "libft/libft.h"

# define RED "\033[0;31m"

typedef struct s_data
{
	int					tphilos;
	int					white_flag;
	size_t				time;
	t_philo				*resources;
	pthread_mutex_t		write;
	pthread_mutex_t		did_he_die;
}			t_data;

typedef struct s_philo
{
	pthread_t			thread;
	struct s_data		*data;
	int					philo;
	int					meals_done;
	int					meals;
	int					kill_all;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	size_t				hour_of_demise;
	size_t				last_meal_time;
	pthread_mutex_t		perished_philo;
	pthread_mutex_t		left_fork;
	pthread_mutex_t		*right_fork;
}				t_philo;

void	init(char **av, t_data *data, t_philo *philo);

int	bad(char *reason);
int	checkargs(int ac, char **av);


//--------------UTILS------------------//
void	ft_putstr_fd(char *s, int fd);

#endif