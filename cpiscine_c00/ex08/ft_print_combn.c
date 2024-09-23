#include <unistd.h>

void	init_digits(char *digits, int count)
{
	while (count >= 0)
	{
		count--;
		digits[count] = '0' + count;
	}
}

void	increment(char *digits, int length, int index)
{
	index--;
	digits[index]++;

	if (digits[index] > '9' - length + 1 + index && index > 0)
	{
		increment(digits, length, index);
		digits[index] = digits[index - 1] + 1;
	}
}

void	ft_print_combn(int n)
{
	char digits[9];
	init_digits(digits, n);
	write(1, digits, n);

	while (digits[0] != '0' + 10 - n)
	{
		increment(digits, n, n);
		write(1, ", ", 2);
		write(1, digits, n);
	}

	write(1, "\n", 1);
}

int main()
{
	for (int i=1; i<10; i++)
	{
		ft_print_combn(i);
	}
}
