//Write a function that displays all digits in ascending order.
//
//
//
//Your function must be declared as follows:
//
//
//
//void	ft_print_numbers(void);


#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_numbers(void)
{
	char	c;

	c = '0';
	while (c <= '9')
	{
		ft_putchar(c);
		c++;
	}
}
