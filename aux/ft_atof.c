#include "aux.h"

float	ft_atof(const char *str)
{
	float	result;
	float	sign;
	float	decimal;
	int		i;

	result = 0;
	sign = 1;
	decimal = 0;
	i = 0;
	if (str[i++] == '-')
		sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	if (str[i] == '.' || str[i] == ',')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10 + str[i++] - '0';
			decimal++;
		}
	}
	while (decimal--)
		result /= 10;
	return (result * sign);
}
