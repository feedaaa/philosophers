#ifndef     PHILO_H
# define    PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <ctype.h>
# include <limits.h>
# include <sys/time.h>

# define ERROR				1
# define DONE				0

/*--------philo state-------*/

# define DEAD				-2
# define THINK				0
# define PICK_FORK			1
# define SLEEP				3
# define EAT				2

/*----------forks----------*/
# define LEFT				0
# define RIGHT				1
# define USED_FORKS			0
# define FREE_FORKS			1

/*-----------------------------------_COLORS_------------------------------*/

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

/*-----------------------------------_DOING THINGS_------------------------*/

int					eat(t_philo *philo);
int					slep(t_philo *philo);
int					thunk(t_philo *philo);
void				pick_record(t_philo *philo, size_t current);

/*-----------------------------------_UTILS_-------------------------------*/

int					printit(char *reason);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
size_t				ft_atoi(const char *str);
int					ft_isdigit(int c);
/*-----------------------------------_TIME_--------------------------------*/

size_t				get_time(void);
size_t				time_stamp(time_t start);
int					sleepy(t_philo *philo, size_t period);

/*---------------------------_INIT & PARSE_--------------------------------*/

int					init_forks(t_table **table, int count);
t_table				*init_table(char **av);
t_data				*init_data(char **av);
void				all_data_init(t_table *table, t_philo *philo, int id);
t_table				*init(char **av);
t_philo				*init_philo(t_table *table);
int					philo(int ac, char **av);
int					parser(int ac, char **av);
int					init_mutex(t_table **table);
int					init_threads(t_table **table);

/*------------------------_LIFE_-----------------------------------------*/

void				death_record(int n, int current_philo);
int					check_death(size_t last_meal, size_t death_time);
int					print_philo_state(t_philo *philo, int num_fork);
void				*circle_of_life(void *routine);

/*------------------------_FREE_----------------------------------------*/

int					forks(t_philo *philo);

/*------------------------_FREE_----------------------------------------*/

void				clean_table(t_table *table);
void				collect_philo(t_table **table);
#endif