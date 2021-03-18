//Write a program that takes a string, and displays the string in reverse
//
//followed by a newline.
//
//
//
//If the number of parameters is not 1, the program displays a newline.
//
//
//
//Examples:
//
//
//
//$> ./rev_print "zaz" | cat -e
//
//zaz$
//
//$> ./rev_print "dub0 a POIL" | cat -e
//
//LIOP a 0bud$
//
//$> ./rev_print | cat -e
//
//$
//

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			i++;
		}
		while (i >= 0)
		{
			ft_putchar(argv[1][i]);
			i--;
		}
	}
	ft_putchar('\n');
	return (0);
}
