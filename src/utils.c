/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:22:43 by pcervill          #+#    #+#             */
/*   Updated: 2023/10/18 12:45:38 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	clear_data(t_data *data)
{
	if (data->tid)
		free(data->tid);
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
	return ;
}

void	ft_exit(t_data *data)
{
	int	i;

	i = 0;
	while (i++ < data->philo_num)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].lock);
	}
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->lock);
	clear_data(data);
	return ;
}

int	error(char *error, t_data *data)
{
	printf("%s%s\n%s", RED, error, NORMAL);
	if (data)
		ft_exit(data);
	return (1);
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
