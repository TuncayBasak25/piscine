#include <unistd.h>

int is_space(char c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

int	get_base_len(char *str)
{
	char *base;
	char *iter;
	
	base = str;
	if (!*str || !*(str + 1))
		return (0);
	while (*str)
	{
		if (*str == '+' || *str == '-' || is_space(*str))
			return (0);
		iter = str;
		while (*++iter)
			if (*iter == *str)
				return (0);
		str++;
	}
	return (str - base);
}

void	init_base_tab(int *tab, char *base, int base_len)
{
	int i;
	
	i = 0;
	while (i < 256) 
		tab[i++] = -1;
	i = -1;
	while (++i < base_len) 
		tab[base[i]] = i;
}

int	ft_atoi_base(char *str, char *base)
{
	int base_len;
	int	base_tab[256];
	int signe;
	int number;
	
	base_len = get_base_len(base);
	if (!base_len) return (0);
	init_base_tab(base_tab, base, base_len);
	signe = 0;
	while (*str == '+' || *str == '-')
	{
		if (*str++ == '-') signe = !signe;
	}
	number = 0;
	while (base_tab[*str] > -1)
	{
		number *= base_len;
		number += base_tab[*str++];
	}
	if (signe) number *= -1;
	return (number);
}

#include <stdio.h>
#include <stdlib.h>
int	main()
{
	char base[] = "0123456789";
	
	printf("%i", ft_atoi_base("\t--011001", base));
}
