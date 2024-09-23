int	is_substring(char *str, char *sub)
{
	while (*sub)
	{
		if (*str++ != *sub++)
		{
			return (0);
		}
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	while (*str)
	{
		if (is_substring(str, to_find))
		{
			return (str);
		}
		str++;
	}
	return (0);
}
