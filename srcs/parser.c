

#include "../includes/philo.h"

static int	check_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			printit("philo: non-digit argument");
			return (ERROR);
		}
		i++;
		if (i > 11 || ft_atoi(str) > INT_MAX)
		{
			printit("philo: error: argument greater than int max");
			return (ERROR);
		}
	}
	return (DONE);
}

int	parser(int ac, char **av)
{
	int		i;

	i = 0;
	if (ac > 6 || ac < 5)
	{
		printit("philo: error: invalid argument");
		return (ERROR);
	}
	while (av[++i])
	{
		if (check_number(av[i]) == ERROR)
			return (ERROR);
	}
	return (DONE);
}
