/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:03:16 by ffidha            #+#    #+#             */
/*   Updated: 2024/06/26 10:01:37 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time(void)
{
	struct timeval	time;

	if ((gettimeofday(&time, NULL)) == -1)
	{
		printf("gettimeofday error!\n");
		return (0);
	}
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}