/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:34:52 by ffidha            #+#    #+#             */
/*   Updated: 2024/06/26 10:17:05 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <ctype.h>
#include <limits.h>
#include <sys/time.h>


# define TAKE_FORK "has taken a fork"
# define THINK "is thinking"
# define SLEEP "is sleeping"
# define EAT "is eating"
# define DIED "has died"

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

typedef struct s_data
{
	int					tphilos;
	int					white_flag;
	size_t				time;
	t_philo				*resources;
	pthread_mutex_t		write;
	pthread_mutex_t		did_he_die;
}			t_data;


void	init(char **av, t_data *data, t_philo *philo);
void	*dinner(t_data *data);

int	bad(char *reason);
int	checkargs(int ac, char **av);

void	ft_putstr_fd(char *s, int fd);
void	print_write(t_data *data, int id, char *print);
int	ft_atoi(const char *str);
size_t	get_time(void);
void	handle_one(t_data	*data);
void	every_die(t_data *data);
#endif