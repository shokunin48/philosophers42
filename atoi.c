/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:28:42 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/20 16:29:20 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	int	ft_iswhitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

long	ft_atoi(const char *str)
{
	int		i;
	int		minus;
	long	result;

	i = 0;
	minus = 1;
	result = 0;
	while (str[i])
	{
		while (ft_iswhitespace(str[i]) == 1)
			i++;
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				minus = -1;
			i++;
		}
		while (ft_isdigit(str[i]) == 1)
			result = (result * 10) + (str[i++] - '0');
		return (result * minus);
		i++;
	}
	return (0);
}
