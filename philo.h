
#ifndef PHILO_H
#define PHILO_H

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <ctype.h>
#include <limits.h>
#include <sys/time.h>

#define ERROR 1
#define DONE 0
#define MALLOC_ERROR "philo: allocation error"

// philo state
#define DEAD				-3
#define THINK				0
#define PICK_FORK			1
#define SLEEP				2
#define EAT					3

// colors
# define RESET			"\033[0m"			// Reset
# define BLACK			"\033[30m"			// Black
# define RED			"\033[31m"			// Red
# define GREEN			"\033[32m"			// Green
# define YELLOW			"\033[33m"			// Yellow
# define BLUE			"\033[34m"			// Blue
# define MAGENTA		"\033[35m"			// Magenta
# define CYAN			"\033[36m"			// Cyan
# define WHITE			"\033[37m"			// White
# define BOLDBLACK		"\033[1m\033[30m"	// Bold Black
# define BOLDRED		"\033[1m\033[31m"	// Bold Red
# define BOLDGREEN		"\033[1m\033[32m"	// Bold Green
# define BOLDYELLOW		"\033[1m\033[33m"	// Bold Yellow
# define BOLDBLUE		"\033[1m\033[34m"	// Bold Blue
# define BOLDMAGENTA	"\033[1m\033[35m"	// Bold Magenta
# define BOLDCYAN		"\033[1m\033[36m"	// Bold Cyan
# define BOLDWHITE		"\033[1m\033[37m"	// Bold White

/**
 * eat: time to eat
 * death: time to die
 * sleep: time to sleep
 * cycle: number of times each philosopher should eat 
**/
typedef struct s_data
{
	int			num;
	int			time_to_eat;
	int			time_to_die;
	int			time_to_sleep;
	int			cycle;
}	t_data;

/**
 * id: philosopher id
 * state: philosopher status
 * 			-1: dead
 * 			 0: didn't start yet / thinking
 * 			 1: picked forks
 * 			 2: eating
 * 			 3: sleeping
 * start_time: system time when the first thread was created
 * check_death: checks if any philosopher died
 * left_forkn: left fork number
 * right_forkn: right fork number
 * left_fork: fork on the left
 * right_fork: fork on the right
 * eat: time to eat
 * death: time to die
 * sleep: time to sleep
 * neat: how many times the philosopher ate
 * repeat: number of times each philosopher should eat
 * last_eat: last time philosopher ate
 * left_mutex: mutex for the left fork
 * right_mutex: mutex for the right fork
 * print: mutex that is shared between all philosophers to print
**/
typedef struct s_philo
{
	int				id;
	int				state;
	int				*check_death;
	size_t			*start_time;
	int				left_forkn;
	int				right_forkn;
	int				*left_fork;
	int				*right_fork;
	int				neat;
	size_t			last_eat;
	t_data			*data;
	pthread_mutex_t	*left_mutex;
	pthread_mutex_t	*right_mutex;
	pthread_mutex_t	*print;
}	t_philo;

/**
 * num: number of philosophers
 * check_death: check if any philo died
 * 				0: no philosopher died
 * 				1: a philosopher died
 * start_time: system time when the first thread was created
 * eat: time to eat
 * death: time to die
 * sleep: time to sleep
 * repeat: number of times each philosopher should eat
 * fork: each fork status
 * threads: philosophers threads
 * mutex: mutex locks array
 * print: printing lock
 * philo: philosophers structure
**/
typedef struct s_table
{
	int				check_death;
	size_t			start_time;
	int				*forks;
	pthread_t		*threads;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	print;
	t_data			*data;
	t_philo			*philo;
}	t_table;



// utils 
void printit(char *reason);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
#endif