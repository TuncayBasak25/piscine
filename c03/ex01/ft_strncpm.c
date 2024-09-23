int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (*s1 != '\0' && n)
	{
		if (*s1++ != *s2++)
			return (0);
	}
	return (1);
}
