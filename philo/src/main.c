/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:44:56 by pcervill          #+#    #+#             */
/*   Updated: 2024/08/07 12:29:46 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* static void	leaks(void)
{
	system("leaks -q philo");
} */

int	main(int argc, char *argv[])
{
	t_data			data;
	t_philo			philos[MAX_PHILO];
	pthread_mutex_t	forks[MAX_PHILO];

//	atexit(leaks);
	if (check_arg((argc - 1), argv))
		return (1);
	init_data(&data, philos);
	init_forks(forks, ft_atoi(argv[1]));
	init_philos(philos, &data, forks, argv);
	thread_create(&data, forks);
	error(NULL, &data, forks);
	return (0);
}
