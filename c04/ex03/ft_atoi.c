int	ft_atoi(char *str)
{
	int signe;
	int nb;

	while (*str == ' ')
	{
		str++;
	}
	signe = 0;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			signe = !signe;
		}
		str++;
	}
	nb = 0;
	while (*str >= '0' && *str <= '9')
	{
		nb *= 10;
		nb += *str - '0';
		str++;
	}
	if (signe)
	{
		nb *= -1;
	}
	return (nb);
}

#include <stdio.h>
int main()
{
	int test = ft_atoi("     +++---+--+--0007a6509008");
	printf("%i", test);
}
