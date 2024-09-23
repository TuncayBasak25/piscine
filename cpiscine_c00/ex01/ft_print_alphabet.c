#include "ft_print_alphabet.h"
#include <unistd.h>

void ft_print_alphabet(void)
{
	char lettre;
	
	lettre = 'a';

	while (lettre <= 'z')
	{
		write(1, &lettre, 1);
		lettre++;
	}
}
