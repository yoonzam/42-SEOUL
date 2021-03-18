//Write a program that takes a string, and displays the first 'z'
//
//character it encounters in it, followed by a newline. If there are no
//
//'z' characters in the string, the program writes 'z' followed
//
//by a newline. If the number of parameters is not 1, the program displays
//
//'z' followed by a newline.
//
//
//
//Example:
//
//
//
//$> ./aff_z "abc" | cat -e
//
//z$
//
//$> ./aff_z "dubO a POIL" | cat -e
//
//z$
//
//$> ./aff_z "zaz sent le poney" | cat -e
//
//z$
//
//$> ./aff_z | cat -e
//
//z$

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(void)
{
	ft_putchar('z');
	ft_putchar('\n');
	return (0);
}
