#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	ft_last_param(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
	return (*str);
}

int		main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putchar('\n');
	}
	else
	{
		ft_last_param(argv[argc - 1]);
	}
	return (0);
}

// Write a program that takes strings as arguments, and displays its last
//
// argument followed by a newline.
//
//
//
// If the number of arguments is less than 1, the program displays a newline.
//
//
//
// Examples:
//
//
//
// $> ./aff_last_param "zaz" "mange" "des" "chats" | cat -e
//
// chats$
//
// $> ./aff_last_param "j'aime le savon" | cat -e
//
// j'aime le savon$
//
// $> ./aff_last_param
//
// $
// //
 
