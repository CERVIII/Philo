/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:25:25 by pcervill          #+#    #+#             */
/*   Updated: 2024/08/07 23:00:33 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_msg(char *str, t_philo *philo, int id)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = get_current_time() - philo->start_time;
	if (!dead_loop(philo))
		printf("%zu %d %s\n", time, id, str);
	pthread_mutex_unlock(philo->write_lock);
}

void	ft_think(t_philo *philo)
{
	print_msg(THINKING, philo, philo->id);
}

void	ft_sleep(t_philo *philo)
{
	print_msg(SLEEPING, philo, philo->id);
	ft_usleep(philo->time_to_sleep);
}

int	lock_fork(t_philo *philo)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	if (philo->id == 1 && philo->num_of_philos != 1)
	{
		first_fork = philo->l_fork;
		second_fork = philo->r_fork;
	}
	else
	{
		first_fork = philo->r_fork;
		second_fork = philo->l_fork;
	}
	pthread_mutex_lock(first_fork);
	print_msg(TAKE_FORKS, philo, philo->id);
	pthread_mutex_lock(second_fork);
	print_msg(TAKE_FORKS, philo, philo->id);
	return (0);
}

void	ft_eat(t_philo *philo)
{
	if (lock_fork(philo))
		return ;
	pthread_mutex_lock(philo->meal_lock);
	philo->eating = 1;
	philo->last_meal = get_current_time();
	print_msg(EATING, philo, philo->id);
	philo->meals_eaten++;
	ft_usleep(philo->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->meal_lock);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	/* if (philo->id == 1 && philo->num_of_philos != 1)
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
	} */
}
