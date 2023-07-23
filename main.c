/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:56:11 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/23 20:40:05 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}

int	check_input(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				printf("%s\n", "Incorrect input.");
				return (0);
			}
			j++;
		}
		i++;
	}
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) <= 0 || \
		ft_atoi(argv[3]) <= 0 || ft_atoi(argv[4]) <= 0 || \
		(argv[5] && ft_atoi(argv[5]) <= 0))
	{
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_philo	*p;
	t_data	*data;

	if ((argc != 5 && argc != 6) || !check_input(argv) || ft_atoi(argv[1]) < 1)
	{
		print_error();
		exit(0);
	}
	p = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if (p == NULL)
		return (1);
	data = init_vars(argv);
	if (!data)
		return (0);
	init_philo_data(p, data);
	action(p);
	join_threads(p);
	free_all(p);
	return (0);
}
