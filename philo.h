/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:56:30 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/22 18:12:31 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/time.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_data
{
	int				ready;
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	int				time_must_eat;
	int				done;
	int				num_of_philos;
	int				check_time_must_eat;
	pthread_mutex_t	*death;
	pthread_mutex_t	*fork;
}			t_data;

typedef struct s_philo
{
	int				id;
	int				iter;
	long int		begin;
	long int		meal;
	pthread_t		phils;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	t_data			*data;
}	t_philo;

t_data		*init_vars(char **argv);
void		init_philo_data(t_philo *p, t_data *data);

long		ft_atoi(const char *str);
int			ft_isdigit(int ch);

void		free_all(t_philo *p);

void		join_threads(t_philo *p);

void		action(t_philo *p);
void		ft_create_threads(t_philo *p);
void		check_threads(t_philo *p);
void		*routine(void *ph);
int			someone_died(t_philo *p);

long int	time_now(void);
int			ft_usleep(long int time);
void		ft_print(t_philo *p, int i);

#endif