/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:25:46 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/22 18:11:34 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	someone_died(t_philo *p)
{
	ft_print(p, 5);
	p->data->done = 1;
	pthread_mutex_unlock(p->fork_left);
	pthread_mutex_unlock(p->fork_right);
	return (1);
}

long int	time_now(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

int	ft_usleep(long int time)
{
	long int	start_time;

	start_time = time_now();
	while ((time_now() - start_time) < time)
		usleep(150);
	return (1);
}

void	free_all(t_philo *p)
{
	int	i;

	i = -1;
	while (++i < p->data->num_of_philos)
		pthread_mutex_destroy(p[i].fork_left);
	pthread_mutex_destroy(p->data->death);
	free(p->data->death);
	free(p->data->fork);
	free(p->data);
	free(p);
}

void	ft_print(t_philo *p, int i)
{
	pthread_mutex_lock(p->data->death);
	if (p->data->done)
	{
		pthread_mutex_unlock(p->data->death);
		return ;
	}
	if (i == 1)
		printf("%ld %d is eating\n", time_now() - p->begin, p->id);
	else if (i == 2)
		printf("%ld %d is sleeping\n", time_now() - p->begin, p->id);
	else if (i == 3)
		printf("%ld %d is thinking\n", time_now() - p->begin, p->id);
	else if (i == 4)
		printf("%ld %d has taken fork\n", time_now() - p->begin, p->id);
	else if (i == 5)
		printf("%ld %d DIED\n", time_now() - p->begin, p->id);
	pthread_mutex_unlock(p->data->death);
}
