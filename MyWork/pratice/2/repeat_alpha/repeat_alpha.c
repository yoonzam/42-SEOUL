//
//
//Write a program called repeat_alpha that takes a string and display it
//
//repeating each alphabetical character as many times as its alphabetical index,
//
//followed by a newline.
//
//
//
//'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...
//
//
//
//Case remains unchanged.
//
//
//
//If the number of arguments is not 1, just display a newline.
//
//
//
//Examples:
//
//
//
//$>./repeat_alpha "abc"
//
//abbccc
//
//$>./repeat_alpha "Alex." | cat -e
//
//Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
//
//$>./repeat_alpha 'abacadaba 42!' | cat -e
//
//abbacccaddddabba 42!$
//
//$>./repeat_alpha | cat -e
//
//$
//
//$>
//
//$>./repeat_alpha "" | cat -e
//
//$
//
//$>
//

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char ft_repeat_alpha(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			j = str[i] - 65;
			while (j >= 0)
			{
				ft_putchar(str[i]);
				j--;
			}
		}
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			j = str[i] - 97;
			while (j >= 0)
			{
				ft_putchar(str[i]);
				j--;
			}
		}
		else
		{
			ft_putchar(str[i]);
		}
		i++;
	}
	ft_putchar('\n');
	return (*str);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_repeat_alpha(argv[1]);
	}
	else
	{
		ft_putchar('\n');
	}
	return (0);
}
