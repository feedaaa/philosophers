#include "philo.h"

int	checkargs(int ac, char **av)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	if (ac < 5)
		return(bad("error: less than 5 arguments\n"));
	if (ac > 6)
		return(bad("error: more than 6 arguments\n"));
	if (av[1][0] == '0')
		return (bad("no philos found\n"), 1);
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!isdigit(av[i][j]))
				return (bad("arguments is negative"), 1);
			j++;
		}
		i++;
	}
	return (0);
}
