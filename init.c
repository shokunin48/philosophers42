/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:52:06 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/23 18:44:10 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*init_vars(char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data) * 1);
	if (!data)
		return (NULL);
	data->death = malloc(sizeof(pthread_mutex_t) * 1);
	if (!data->death)
		return (NULL);
	data->fork = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
	if (!data->fork)
		return (NULL);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->check_time_must_eat = 0;
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5] && ft_atoi(argv[5]) > 0)
	{
		data->check_time_must_eat = 1;
		data->time_must_eat = ft_atoi(argv[5]);
	}
	data->num_of_philos = ft_atoi(argv[1]);
	data->ready = 0;
	data->done = 0;
	return (data);
}

void	init_philo_data(t_philo *p, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_of_philos)
	{
		p[i].begin = 0;
		p[i].id = i + 1;
		p[i].phils = 0;
		p[i].meal = 0;
		p[i].fork_left = &data->fork[i];
		if (p[i].id == data->num_of_philos)
			p[i].fork_right = &data->fork[0];
		else
			p[i].fork_right = &data->fork[i + 1];
		p[i].data = data;
		p[i].iter = 0;
	}
}
