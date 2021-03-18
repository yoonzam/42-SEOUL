/*Write a program that displays all digits in descending order, followed by a

newline.



Example:

$> ./ft_countdown | cat -e

9876543210$

$>*/

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(void)
{
	char	c;

	c = '9';
	while (c >= '0')
	{
		ft_putchar(c);
		c--;
	}
	ft_putchar('\n');
	return (0);
}
