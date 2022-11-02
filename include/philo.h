/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy <bbourcy@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:29:33 by bbourcy           #+#    #+#             */
/*   Updated: 2022/10/31 13:33:09 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

/*	struct s_arg explications
//	arg after ./philo
//	nb of philo
//	time to die en milliseconds
//	time to eat en milliseconds
//	time to sleep en milliseconds
//	must eat m_eat times
//	start time en milliseconds
//	ecrit mutex
//	when a philosopher ate m_eat times : nb_p_finish++
//	0 if none philosopher is dead, 1 if a philosopher
	is dead, 2 if all philosophers ate m_eat times
*/
typedef struct s_arg
{
	int						total;
	int						die;
	int						eat;
	int						sleep;
	int						m_eat;
	long int				start_t;
	pthread_mutex_t			write_mutex;
	pthread_mutex_t			dead;
	pthread_mutex_t			time_eat;
	pthread_mutex_t			finish;
	int						nb_p_finish;
	int						stop;
}							t_arg;

/*	struct s_philo explications
	id of the philosopher
	thread id
	id of the thread monitoring death
	right fork mutex
	left fork mutex
	pointer to structure with all arguments (pointer on a)
	time of the last dinner in milliseconds
	number of dinners (each time the philosopher eats nb_eat++)
	1 when a philosopher ate m_eat times, if not, 0
*/
typedef struct s_philo
{
	int						id;
	pthread_t				thread_id;
	pthread_t				thread_death_id;
	pthread_mutex_t			*r_f;
	pthread_mutex_t			l_f;
	t_arg					*pa;
	long int				ms_eat;
	unsigned int			nb_eat;
	int						finish;
}							t_philo;

/* 	struct s_p explications
	structure for each philosopher
	structure with arguments, same for all philosophers	
*/
typedef struct s_p
{
	t_philo					*ph;
	t_arg					a;
}							t_p;

int				parse_args(int argc, char **argv, t_p *p);
int				initialize(t_p *p);
int				ft_exit(char *str);
void			write_status(char *str, t_philo *ph);
long int		actual_time(void);
void			ft_putstr_fd(char *s, int fd);
void			ft_usleep(long int time_in_ms);
int				threading(t_p *p);
void			activity(t_philo *ph);
int				check_death(t_philo *ph, int i);
int				ft_strlen(char *str);

#endif