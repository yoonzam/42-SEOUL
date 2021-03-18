#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);

}

int main()
{
	ft_putchar('z');
return (0);
}


// #include <unistd.h>
// int main(void)
// {
// write(1, 'z', 1);
// return (0);
// }
