#include <unistd.h>

void	print_positive(int nb)
{
	char digit;

	if (nb > 9)
	{
		print_positive(nb / 10);
	}
	digit = '0' + nb % 10;
	write(1, &digit, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		write(1,"-", 1);
		if (nb == 0xFFFFFFFF)
		{
			write(1, "2", 1);
			nb += 2000000000;
		}
		nb *= -1;
	}
	print_positive(nb);
}

int	main()
{
	ft_putnbr(-10202020);
}
