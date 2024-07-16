/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:37:09 by pcervill          #+#    #+#             */
/*   Updated: 2024/07/16 14:49:08 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

/* 		alloc_err	 */
# define ALLOC_ERR_1 "ERROR WHILE ALLOCATING THREADS IDs"
# define ALLOC_ERR_2 "ERROR WHILE ALLOCATING FORKS"
# define ALLOC_ERR_3 "ERROR WHILE ALLOCATING PHILOS"
# define ALLOC_ERR_4 "ERROR WHILE ALLOCATING"
/* 		input_err	 */
# define ERR_IN_1 "INVALID INPUT CHARACTER"
# define ERR_IN_2 "INVALID INPUT VALUES"
# define ERR_IN_3 "INVALID NUMBER OF ARGUMENTS"
/* 		pthread_err	 */
# define TH_ERR "ERROR WHILE CREATING THREADS"
# define JOIN_ERR "ERROR WHILE JOINING THREADS"
# define INIT_ERR_1 "ERROR WHILE INIT FORKS"
/* 		time_err	 */
# define TIME_ERR "UNABLE TO RETRIVE UTC"
/* 		philo_msg	 */
# define TAKE_FORKS "has taken a fork 🍽"
# define THINKING "is thinking 🤔"
# define SLEEPING "is sleeping 😴"
# define EATING "is eating 🥘"
# define DIED "died 💀"

# define MAX_PHILO 200

/* 		COLORS		 */
# define NORMAL  "\x1B[0m"
# define RED  "\x1B[31m"
# define GREEN  "\x1B[32m"
# define YELLOW  "\x1B[33m"
# define BLUE  "\x1B[34m"
# define MAGENT  "\x1B[35m"
# define CYAN  "\x1B[36m"
# define WHITE  "\x1B[37m"

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_philo;

typedef struct s_data
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
}					t_data;




/* typedef struct s_philo
{
	struct s_data	*data;
	pthread_t		t1;
	int				id;
	int				eat_cont;
	int				status;
	int				eating;
	size_t			time_to_die;
	pthread_mutex_t	lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}	t_philo;

typedef struct s_data
{
	pthread_t		*tid;
	int				philo_num;
	int				meals_nb;
	int				dead;
	int				finished;
	t_philo			*philos;
	size_t			death_time;
	size_t			eat_time;
	size_t			sleep_time;
	size_t			start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
}	t_data; */

/* 		ARG.C		 */
int		all_num(char *argv[]);
int		check_arg(int argc, char *argv[]);

/* 		INIT.C		 */
void	init_input(t_philo *philo, char **argv);
void	init_philos(t_philo *philos, t_data *data, pthread_mutex_t *forks,
		char **argv);
void	init_forks(pthread_mutex_t *forks, int num_philo);
void	init_data(t_data *data, t_philo *philos);

/* 		UTILS.C		 */
void	clear_data(t_data *data);
void	ft_exit(t_data *data);
int		error(char *error, t_data *data);
int		ft_atoi(const char *str);

/* 		UTILS2.C	 */
size_t	get_current_time(void);
int		ft_usleep(size_t time);
#endif