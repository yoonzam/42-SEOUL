/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 20:04:14 by jyoon             #+#    #+#             */
/*   Updated: 2021/03/13 20:11:59 by jyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	non_print(unsigned char c)
{
	unsigned char	div;
	unsigned char	mod;

	if (c / 16 >= 10)
		div = c / 16 - 10 + 'a';
	else
		div = c / 16 + '0';
	if (c % 16 >= 10)
		mod = c % 16 - 10 + 'a';
	else
		mod = c % 16 + '0';
	write(1, "\\", 1);
	write(1, &div, 1);
	write(1, &mod, 1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	c;
	int				i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] > 126)
		{
			c = str[i];
			non_print(c);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
