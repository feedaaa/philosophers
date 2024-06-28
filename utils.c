/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 10:42:46 by ffidha            #+#    #+#             */
/*   Updated: 2024/06/26 10:17:01 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	bad(char *reason);
void	ft_putstr_fd(char *s, int fd);
 
int	checkargs(int ac, char **av)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	if (ac < 5)
		return(bad("error: less than 5 arguments\n"));
	if (ac > 6)
		return(bad("error: more than 6 arguments\n"));
	if (av[1][0] == '0')
		return (bad("no philos found\n"), 1);
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!isdigit(av[i][j]))
				return (bad("arguments is negative"), 1);
			j++;
		}
		i++;
	}
	return (0);
}

int	bad(char *reason)
{
	ft_putstr_fd(reason, 2);
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s[i] == '\0')
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}
void	print_write(t_data *data, int id, char *print)
{
	pthread_mutex_lock(&data->write);
	if(!data->resources->kill_all)
		printf("%zu %d %s\n", get_time() - data->time, id, print);
	pthread_mutex_unlock(&data->write);
}

int	ft_atoi(const char *str)
{
	long			result;
	long			sign;
	unsigned int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result >= LONG_MAX / 10 && sign == 1)
			return (-1);
		else if (result >= LONG_MAX / 10 && sign == -1)
			return (0);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return ((int)result * sign);
}

void	handle_one(t_data	*data)
{
	pthread_mutex_lock(&data->resources->left_fork);
	print_write(data, 1, "has taken a fork");
	pthread_mutex_unlock(&data->resources->left_fork);
	pthread_mutex_lock(&data->resources->perished_philo);
	printf("%zu %d %s\n", data->resources->hour_of_demise,
		data->resources->philo, "died");
	data->white_flag = 1;
	pthread_mutex_unlock(&data->resources->perished_philo);
}
void	every_die(t_data *data)
{
	int	i;

	i = -1;
	pthread_mutex_lock(&data->write);
	while (++i < data->tphilos)
		data->resources[i].kill_all = 1;
	pthread_mutex_unlock(&data->write);
}
