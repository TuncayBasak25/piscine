unsigned int	ft_strlen(char *str)
{
	unsigned int	len;
	
	len = 0;
	while (*str++)
	{
		len++;
	}
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	src_len;
	unsigned int	dest_len;

	src_len = ft_strlen(src);
	dest_len = 0;
	while (*dest && size)
	{
		dest++;
		dest_len++;
		size--;
	}
	if (!size)
	{
		return (dest_len + src_len);
	}
	while (*src && size > 1)
	{
		*dest++ = *src++;
		size--;
		*dest = 0;
	}
	return (dest_len + src_len);
}
