#include <unistd.h>

int	ft_strlen(char *str)
{
	int l;
	
	l = 0;
	while (*str++)
	{
		l++;
	}
	return (l);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int main()
{
	char	test[] = "My name";
	ft_putstr(test);
}
