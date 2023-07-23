/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:08:10 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/23 15:42:15 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *p)
{
	long int	now;

	pthread_mutex_lock(p->data->death);
	now = time_now() - p->meal;
	if (now >= p->data->time_to_die)
	{
		pthread_mutex_unlock(p->data->death);
		return (smbd_died(p));
	}
	pthread_mutex_unlock(p->data->death);
	return (0);
}

int	check_meals(t_philo *p)
{
	if (p->data->check_time_must_eat && p->iter > p->data->time_must_eat
		&& p->id == p->data->num_of_philos)
		return (ft_usleep(300));
	return (0);
}

void	check_threads(t_philo *p)
{
	int	i;

	while (!p->data->ready)
		continue ;
	while (!p->data->done)
	{
		i = -1;
		while (++i < p->data->num_of_philos)
			if (check_death(&p[i]) || check_meals(&p[i]))
				p->data->done = 1;
	}
	return ;
}

void	join_threads(t_philo *p)
{
	int	i;

	i = -1;
	while (++i < p->data->num_of_philos)
		pthread_join(p[i].phils, (void *)&p[i]);
}

void	ft_create_threads(t_philo *p)
{
	int			i;
	long int	k;

	i = -1;
	while (++i < p->data->num_of_philos)
		pthread_create(&p[i].phils, NULL, &routine, &p[i]);
	i = -1;
	k = time_now();
	while (++i < p->data->num_of_philos)
	{
		p[i].begin = k;
		p[i].meal = k;
	}
	p->data->ready = 1;
}
