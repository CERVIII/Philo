/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:38:05 by pcervill          #+#    #+#             */
/*   Updated: 2024/08/20 10:53:45 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void	*philo_routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!dead_loop(philo))
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (pointer);
}

int	thread_create(t_data *data, pthread_mutex_t *forks)
{
	pthread_t	observer;
	int			i;

	if (pthread_create(&observer, NULL, &monitor, data->philos) != 0)
		error(TH_ERR, data, forks);
	i = 0;
	while (i < data->philos[0].num_of_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL, &philo_routine,
				&data->philos[i]) != 0)
			error(TH_ERR, data, forks);
		i++;
	}
	i = 0;
	if (pthread_join(observer, NULL) != 0)
		error(JOIN_ERR, data, forks);
	while (i < data->philos[0].num_of_philos)
	{
		if (pthread_join(data->philos[i].thread, NULL) != 0)
			error(JOIN_ERR, data, forks);
		i++;
	}
	return (0);
}
