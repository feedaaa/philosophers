/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:33:22 by ffidha            #+#    #+#             */
/*   Updated: 2024/07/30 13:23:07 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    clean_table(t_table *table)
{
    free(table->forks);
    free(table->threads);
    free(table->mutex);
    free(table->philo);
    free(table->data);
    free(table);
}

static void    thread_join(t_table **table)
{
    int     i;

    i = -1;
    while(++i < (*table)->data->num)
    {
        if(pthread_join((*table)->threads[i], NULL))
            printit("thread join error");
    }
}

static void destroy_mutex(t_table **table)
{
    int     i;

    i = -1;
    while(++i < (*table)->data->num)
    {
        if(pthread_mutex_destroy(&(*table)->mutex[i]))
            printit("error: mutex destory");
    }
    if(pthread_mutex_destroy(&(*table)->print))
        printit("error: mutext destroy");
}

void collect_philo(t_table **table)
{
    thread_join(table);
    destroy_mutex(table);
}