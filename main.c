/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:56:11 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/23 14:55:13 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}

int	check_input(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc != 6)
	{
		printf("Usage: ./philos [# Philosophers] [time_to_die] [time_to_eat] ");
		printf("[time_to_sleep] ([times_each_philosopher_must_eat])\n");
		return (1);
	}
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				printf("%s\n", "Incorrect input.");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo	*p;
	t_data	*data;

	check_input(argc, argv);
	p = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if (p == NULL)
		return (1);
	data = init_vars(argv);
	if (!data)
		return (0);
	init_philo_data(p, data);
	action(p);
	//join_threads(p);
	//free_all(p);
	return (0);
}
