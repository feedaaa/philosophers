#include "../philo.h"

int	ft_atoi(const char *str)
{
	long			result;
	long			sign;
	unsigned int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result >= LONG_MAX / 10 && sign == 1)
			return (-1);
		else if (result >= LONG_MAX / 10 && sign == -1)
			return (0);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return ((int)result * sign);
}