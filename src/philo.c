/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:44:56 by pcervill          #+#    #+#             */
/*   Updated: 2023/10/19 12:59:01 by pcervill         ###   ########.fr       */
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
	int		i;

	if (check_arg((argc - 1), argv))
		return (1);
	if (init(&data, argv, argc))
		return (1);
	i = 0;
	while (i < data.philo_num)
	{
		printf("%sPHILO: %d\n%sId: %d\nTime to die: %llu\nEat cont: %d\nEating: %d\nStatus: %d\n", GREEN, i, NORMAL, data.philos[i].id, data.philos[i].time_to_die, data.philos[i].eat_cont, data.philos[i].eating, data.philos[i].status);
		i++;
	}
	ft_exit(&data);
	return (0);
}
