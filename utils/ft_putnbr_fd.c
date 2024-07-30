/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:33:49 by ffidha            #+#    #+#             */
/*   Updated: 2024/07/30 19:43:17 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		a;
	char	b;
	int		c;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n == -2147483648)
		ft_putstr_fd("2147483648", fd);
	else if (n >= 10)
	{
		c = n;
		a = c % 10;
		ft_putnbr_fd(c / 10, fd);
		b = a + '0';
		ft_putchar_fd(b, fd);
	}
	if (n < 10 && n >= 0)
	{
		b = n + '0';
		ft_putchar_fd(b, fd);
	}
}
