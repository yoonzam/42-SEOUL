//Write a program that displays the alphabet, with even letters in uppercase, and
//
//odd letters in lowercase, followed by a newline.
//
//
//
//Example:
//
//
//
//$> ./maff_alpha | cat -e
//
//aBcDeFgHiJkLmNoPqRsTuVwXyZ$




#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(void)
{
	char	a;
	char	b;

	a = 'a';
	b = 'B';
	while (a <= 'z' && b <= 'Z')
	{
		ft_putchar(a);
		ft_putchar(b);
		a += 2;
		b += 2;
	}
	ft_putchar('\n');
	return (0);
}
