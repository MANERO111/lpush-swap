#include "push.h"

int	ft_atoi(const char *nptr, int *n)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr++ == '-')
			sign *= -1;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr++ - '0');
		if((result > 2147483647 && sign == 1) || (result > 2147483648 && sign == -1) )
			return (1);
	}
	if ((*nptr && !(*nptr >= '0' && *nptr <= '9')) && *nptr !=' ' )
		return (1);
	*n = result * sign;
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && (unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}