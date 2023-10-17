/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba_datarace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:12:08 by pcervill          #+#    #+#             */
/*   Updated: 2023/10/16 11:35:52 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//	DATARACE	//

/* int	cont = 0;

void	*routine()
{
	int	i;

	i = -1;
	while (++i < 1000000)
		cont++;
	return (NULL);
}

int	main(void)
{
	pthread_t	tid1;
	pthread_t	tid2;

	pthread_create(&tid1, NULL, &routine, NULL);
	pthread_create(&tid2, NULL, &routine, NULL);

	pthread_join(tid1, NULL);
	printf("cont: %d\n", cont);
	pthread_join(tid2, NULL);
	printf("cont: %d\n", cont);
} */


// SIN DATARACE //

int	cont = 0;
pthread_mutex_t	lock;

void	*routine()
{
	int	i;

	i = -1;
	while (++i < 1000000)
	{
		pthread_mutex_lock(&lock);
		cont++;
		pthread_mutex_unlock(&lock);
	}
	return (NULL);
}

int	main(void)
{
	pthread_t	tid1;
	pthread_t	tid2;

	pthread_mutex_init(&lock, NULL);
	pthread_create(&tid1, NULL, &routine, NULL);
	pthread_create(&tid2, NULL, &routine, NULL);

	pthread_join(tid1, NULL);
	printf("cont: %d\n", cont);
	pthread_join(tid2, NULL);
	pthread_mutex_destroy(&lock);
	printf("cont: %d\n", cont);
}
