#include "ft_print_reverse_alphabet.h"
#include <unistd.h>

void ft_print_reverse_alphabet(void)
{
	char lettre;
	
	lettre = 'z';

	while (lettre >= 'a')
	{
		write(1, &lettre, 1);
		lettre--;
	}
}
