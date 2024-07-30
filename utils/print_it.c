/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:34:06 by ffidha            #+#    #+#             */
/*   Updated: 2024/07/30 13:23:34 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void printit(char *reason)
{
	ft_putstr_fd(reason, 2);
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
