/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:44:56 by pcervill          #+#    #+#             */
/*   Updated: 2023/10/17 15:41:37 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* static void	leaks(void)
{
	system("leaks -q philo");
} */ //atexit(leaks);

void	*routine(t_data *data, int argc)
{
	int	i;

	i = 0;
	while (i++ < argc)
	{
		pthread_mutex_lock(&data->lock);
		data->philo_num++;
		printf("NUM PHILO: %d\n", data->philo_num);
		pthread_mutex_unlock(&data->lock);
	}
	return (NULL);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (check_arg((argc - 1), argv))
		return (1);
	init(&data, argv, argc);
	return (0);
}
