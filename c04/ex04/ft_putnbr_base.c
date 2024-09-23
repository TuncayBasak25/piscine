#include <unistd.h>

int	get_base_len(char *str)
{
	char *base;
	char *iter;
	
	base = str;
	if (!*str || !*(str + 1))
	{
		return (0);
	}
	while (*str)
	{
		if (*str == '+' || *str == '-')
		{
			return (0);
		}
		iter = str + 1;
		while (*iter)
		{
			if (*iter == *str)
			{
				return (0);
			}
			iter++;
		}
		str++;
	}
	return (str - base);
}

void	print_pn_base(long long int pn, char *base, int base_len)
{
	char digit;
	
	if (pn > base_len - 1)
	{
		print_pn_base(pn / base_len, base, base_len);
	}
	digit = base[pn % base_len];
	write(1, &digit, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;
	long long int big_nbr;
	
	base_len = get_base_len(base);
	if(!base_len)
	{
		return ;
	}
	big_nbr = (long long int)nbr;
	if (big_nbr < 0)
	{
		write(1, "-", 1);
		big_nbr *= -1;
	}
	print_pn_base(big_nbr, base, base_len);
}

#include <stdio.h>
int	main()
{
	char base[] = "01";
	
	ft_putnbr_base(0x7FFFFFFF, base);
}
