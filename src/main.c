/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:44:56 by pcervill          #+#    #+#             */
/*   Updated: 2024/07/16 14:28:14 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* static void	leaks(void)
{
	system("leaks -q philo");
} */ //atexit(leaks);

int	main(int argc, char *argv[])
{
	t_data	data;
	t_philo philos[MAX_PHILO];
	pthread_mutex_t forks[MAX_PHILO];

	if (check_arg((argc - 1), argv))
		return (1);
	init_data(&data, philos);
	init_forks(forks, ft_atoi(argv[1]));
	init_philos(philos, &data, forks, argv);
	return (0);
}

/* int	one_philo(t_data *data)
{
	data->start_time = get_time();
	if (pthread_create(&data->tid[0], NULL, &routine, &data->philos[0]))
		return (error(TH_ERR, data));
	pthread_detach(data->tid[0]);
	while (data->dead == 0)
		ft_usleep(0);
	ft_exit(data);
	return (0);
} */

/* int	main(int argc, char *argv[])
{
	t_data	data;

	if (check_arg((argc - 1), argv))
		return (1);
	if (init(&data, argv, argc))
		return (1);
	if (data.philo_num == 1)
		return (one_philo(&data));
	ft_exit(&data);
	return (0);
} */
