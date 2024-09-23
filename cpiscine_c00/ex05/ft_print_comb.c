#include <unistd.h>

void ft_print_comb(void)
{
	char digits[3];

	digits[0] = '0';
	digits[1] = '1';
	digits[2] = '2';

	write(1, digits, 3);

	while (digits[2] != '9' || digits[1] != '8' || digits[0] != '7')
	{
		digits[2]++;

		if (digits[2] > '9') {
			digits[1]++;

			if (digits[1] > '8') {
				digits[0]++;
				digits[1] = digits[0] + 1;
			}

			digits[2] = digits[1] + 1;
		}

		write(1, ", ", 2);
		write(1, digits, 3);
	}

	write(1, "\n", 1);
}
