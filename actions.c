/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:59:06 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/22 20:44:48 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *p)
{
	pthread_mutex_lock(p->fork_left);
	ft_print(p, 4);
	pthread_mutex_lock(p->fork_right);
	ft_print(p, 4);
	p->meal = time_now();
	p->iter++;
	ft_usleep(p->data->time_to_sleep);
	ft_print(p, 1);
	pthread_mutex_unlock(p->fork_left);
	pthread_mutex_unlock(p->fork_right);
}

void	*routine(void *ph)
{
	t_philo	*p;

	p = (t_philo *)ph;
	while (!p->data->ready)
		continue ;
	if (p->id & 1)
		ft_usleep(p->data->time_to_eat * 0.9 + 1);
	while (!p->data->done)
	{
		ft_eat(p);
		ft_usleep(p->data->time_to_sleep);
		ft_print(p, 2);
		ft_print(p, 3);
	}
	return (NULL);
}

void	action(t_philo *p)
{
	int	i;

	i = -1;
	while (++i < p->data->num_of_philos)
		pthread_mutex_init(p[i].fork_left, NULL);
	pthread_mutex_init(p->data->death, NULL);
	ft_create_threads(p);
	check_threads(p);
}