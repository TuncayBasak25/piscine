#include <stdlib.h>

int	index_of_char(char *str, char c)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int is_whitespace(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

unsigned int	get_base_len(char *base)
{
	int i;

	if (!base || !base[0] || !base[1]) 
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || is_whitespace(base[i]))
		{
			return (0);
		}
		if (index_of_char(base + i + 1, base[i]) > -1)
		{
			return (0);
		}
		i++;
	}
	return (i);
}

int	atoi_base(char *input, char *base)
{
	unsigned int base_len;
	int	total;
	int signe;
	
	base_len = get_base_len(base);
	if (!base_len)
	{
		return (0);
	}
	while (is_whitespace(*input))
	{
		input++;
	}
	signe = 1;
	while (*input == '+' || *input == '-')
	{
		if (*input == '-') signe *= -1;
		input++;
	}
	total = 0;
	while (index_of_char(base, *input) > -1)
	{
		total *= base_len;
		total += index_of_char(base, *input);
		input++;
	}
	return (total * signe);
}

void	write_value_base(long long int nb, char *base, unsigned int base_len, char **digit)
{
	if (nb < 0)
	{
		**digit = '-';
		return write_value_base(nb * -1, base, base_len, digit);
	}
	if (nb > 0)
	{
		write_value_base(nb / base_len, base, base_len, digit++);
		*digit = base[nb % base_len];
		return ;
	}
	*digit = 0;
	return ;
}

char	*ft_strcpy(char *dest, char *src)
{
	char	*ret;
	
	ret = dest;
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = 0;
	return (ret);
}

char	*ft_strdup(char *str)
{
	unsigned int	len;
	char			*dup;
	
	len = 0;
	while (str[len])
	{
		len++;
	}
	dup = malloc(sizeof(char) * len + 1);
	if (!dup)
	{
		return (dup);
	}
	ft_strcpy(dup, str);
	return (dup);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	unsigned int	base_from_len;
	unsigned int	base_to_len;
	char			nbr_in_new_base[34];

	base_from_len = get_base_len(base_from);
	base_to_len = get_base_len(base_to);
	if (!base_from_len || !base_to_len)
	{
		return (0);
	}
	write_value_base((long long int)atoi_base(nbr, base_from), base_to, base_to_len, nbr_in_new_base);
	if (!nbr_in_new_base[0])
	{
		nbr_in_new_base[0] = base_to[0];
		nbr_in_new_base[1] = 0;
	}
	return (ft_strdup(nbr_in_new_base));
}

#include <stdio.h>
int	main()
{
	char *base_from = "ab";
	char *base_to = "0123456789abcd";
	char *nbr = "baaa";
	char *nbr_in_new = ft_convert_base(nbr, base_from, base_to);
	printf("%s", nbr_in_new);
	return (0);
}
