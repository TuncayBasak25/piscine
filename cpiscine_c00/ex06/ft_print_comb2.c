#include <unistd.h>

void	print_numbers(int n0, int n1)
{
	char buff[5];

	buff[1] = '0' + n0 % 10;
	n0 /= 10;
	buff[0] = '0' + n0;
	buff[2] = ' ';
	buff[4] = '0' + n1 % 10;
	n1 /= 10;
	buff[3] = '0' + n1;
	write(1, buff, 5);
}
void	ft_print_comb2(void)
{
	int n0;
	int n1;

	n0 = 0;
	n1 = 1;
	print_numbers(n0, n1);

	while (n1 != 99 || n0 != 98)
	{
		n1++;

		if (n1 > 99)
		{
			n0++;
			n1 = n0 + 1;
		}

		write(1, ", ", 2);
		print_numbers(n0, n1);
	}

	write(1, "\n", 1);
}

int main(){ft_print_comb2();}
