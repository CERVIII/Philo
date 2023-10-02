/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:46:45 by pcervill          #+#    #+#             */
/*   Updated: 2023/10/02 10:56:50 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	all_num(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf("%sError\nOnly numbers in arguments\n%s", RED, NORMAL);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	check_arg(int argc, char *argv[])
{
	if (argc < 4 || argc > 5)
	{
		printf("%sError\nArguments Invalid.\n%s", RED, NORMAL);
		exit (EXIT_FAILURE);
	}
	else
	{
		all_num(argv);
	}
	return ;
}