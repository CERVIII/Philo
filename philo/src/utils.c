/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:22:43 by pcervill          #+#    #+#             */
/*   Updated: 2024/08/20 11:24:05 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	error(char *error, t_data *data, pthread_mutex_t *forks)
{
	int	i;

	if (error)
		printf("%s%s\n%s", RED, error, NORMAL);
	if (data)
	{
		pthread_mutex_destroy(&data->dead_lock);
		pthread_mutex_destroy(&data->meal_lock);
		pthread_mutex_destroy(&data->write_lock);
	}
	if (forks)
	{
		i = 0;
		while (i < data->philos[0].num_of_philos)
		{
			pthread_mutex_destroy(&forks[i]);
			i++;
		}
	}
	return (1);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t time)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < time)
		usleep(500);
	return (0);
}

static int	snumber(unsigned long int number, int sign)
{
	if (number > 2147483648 && sign == 1)
		number = 0;
	else if (number > 2147483647 && sign != 1)
		number = -1;
	return (number);
}

int	ft_atoi(const char *str)
{
	unsigned long int	number;
	int					sign;

	while ((*str == ' ') || (*str >= 7 && *str <= 13))
		str++;
	sign = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign++;
		str++;
	}
	number = 0;
	while (*str >= '0' && *str <= '9')
	{
		number = 10 * number + (*str - 48);
		str++;
	}
	number = snumber(number, sign);
	if (sign == 1)
		return (number * -1);
	return (number);
}
