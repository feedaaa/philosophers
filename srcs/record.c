/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:27:16 by ffidha            #+#    #+#             */
/*   Updated: 2024/08/01 13:27:21 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	fork_record(int n, int fork_n, int current)
{
	ft_putstr_fd(YELLOW, 1);
	ft_putnbr_fd(current, 1);
	ft_putstr_fd(": philo "BOLDYELLOW, 1);
	ft_putnbr_fd(n, 1);
	ft_putstr_fd(RESET YELLOW" has picked fork ", 1);
	ft_putnbr_fd(fork_n, 1);
	ft_putstr_fd(" 🥢\n", 1);
	ft_putstr_fd(RESET, 1);
}

static void	eat_record(int n, int current)
{
	ft_putstr_fd(GREEN, 1);
	ft_putnbr_fd(current, 1);
	ft_putstr_fd(": philo "BOLDGREEN, 1);
	ft_putnbr_fd(n, 1);
	ft_putstr_fd(RESET GREEN" is eating 🍝\n", 1);
	ft_putstr_fd(RESET, 1);
}

static void	sleep_record(int n, int current)
{
	ft_putstr_fd(BLUE, 1);
	ft_putnbr_fd(current, 1);
	ft_putstr_fd(": philo "BOLDBLUE, 1);
	ft_putnbr_fd(n, 1);
	ft_putstr_fd(RESET BLUE" is sleeping 😴\n", 1);
	ft_putstr_fd(RESET, 1);
}

static void	think_record(int n, int current)
{
	ft_putstr_fd(YELLOW, 1);
	ft_putnbr_fd(current, 1);
	ft_putstr_fd(": philo "BOLDYELLOW, 1);
	ft_putnbr_fd(n, 1);
	ft_putstr_fd(RESET YELLOW" is thinking 💭\n", 1);
	ft_putstr_fd(RESET, 1);
}

void	pick_record(t_philo *philo, size_t current, int fork_n)
{
	if (philo->state == PICK_FORK)
		fork_record(philo->id, fork_n, current);
	else if (philo->state == EAT)
		eat_record(philo->id, current);
	else if (philo->state == SLEEP)
		sleep_record(philo->id, current);
	else if (philo->state == THINK)
		think_record(philo->id, current);
}
