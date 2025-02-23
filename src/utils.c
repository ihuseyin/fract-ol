#include "fractol.h"
#include <stdlib.h>

char	*to_lower(char *str)
{
	t_uint	i;

	i = 0;
	while (str[i])
	{
		str[i] += 32 * (str[i] >= 'A' && str[i] <= 'Z');
		i++;
	}
	str[0] -= 32 * (str[0] >= 'a' && str[0] <= 'z');
	return (str);
}

int	ft_strncmp(const char *s1, const char *s2, int len)
{
	if (len <= 0)
		return (0);
	while (s1 && s2 && 0 < len - 1)
	{
		if (*s1 != *s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
		len--;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

t_uint	ft_atoui(const char *str)
{
	t_uint	result;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+')
		str++;
	if (!*str)
	{
		print("Allowed number of iterations: 10 to 30,000.\n");
		exit(EXIT_FAILURE);
	}
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (*str || result <= 10 || result > 30000)
	{
		print("Allowed number of iterations: 10 to 30,000.\n");
		exit(EXIT_FAILURE);
	}
	return (result);
}

static void	decimal_portion(const char *str, double *result)
{
	double	dec;	

	dec = 1.0;
	if (*str == '.')
	{
		str++;
		while (*str >= '0' && *str <= '9')
		{
			dec *= 0.1;
			*result = *result + (*str - '0') * dec;
			str++;
		}
	}
	if (*str)
	{
		print("Wrong constant number!\n");
		exit(EXIT_FAILURE);
	}
}

double	ft_atof(const char *str)
{
	double	result;
	double	sign;

	result = 0.0;
	sign = 1.0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1.0;
	if (!*str || *str == '.')
	{
		print("Wrong constant number!\n");
		exit(EXIT_FAILURE);
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	decimal_portion(str, &result);
	return (result * sign);
}
