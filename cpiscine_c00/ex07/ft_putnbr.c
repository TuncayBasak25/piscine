#include <unistd.h>

void	ft_putnbr(int n)
{
	char digits[11];
	int digits_length;

	digits_length = 0;

	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}

	while (n > 9)
	{
		digits[digits_length] = '0' + n%10;
		n /= 10;
		digits_length++;
	}

	digits[digits_length] = '0' + n;
	
	while (digits_length >= 0)
	{
		write(1, &digits[digits_length], 1);
		digits_length--;
	}
}

int main(){ft_putnbr(-551);}
