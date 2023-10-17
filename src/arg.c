/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:46:45 by pcervill          #+#    #+#             */
/*   Updated: 2023/10/17 14:52:38 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* int	correct_value(int argc, char *argv[])
{
	int	*ar;
	int	i;

	ar = malloc(sizeof(int) * argc);
	if (!ar)
		return (error(ALLOC_ERR_4, NULL));
	i = 0;
	while (i++ < argc)
		ar[i] = ft_atoi(argv[i + 1]);
	if (ar[0] < 1 || ar[0] >= 250)
		return (error(ERR_IN_2, NULL));
	if (ar[1] < 1 || ar[2] < 1 || ar[3] < 1)
		return (error(ERR_IN_2, NULL));
	if (argc == 5 && ar[4] < 1)
		return (error(ERR_IN_2, NULL));
	free(ar);
	return (0);
} */

int	all_num(char *argv[])
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
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_arg(int argc, char *argv[])
{
	if (argc < 4 || argc > 5)
		return (error(ERR_IN_3, NULL));
	if (all_num(argv))
		return (error(ERR_IN_1, NULL));
	return (0);
}
