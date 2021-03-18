/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junbjang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 19:01:51 by junbjang          #+#    #+#             */
/*   Updated: 2021/02/21 19:09:25 by junbjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_first_row(int a, int column)
{
	while (column <= a)
	{
		if (column == 1)
			ft_putchar('A');
		else if (column != a)
			ft_putchar('B');
		else
			ft_putchar('C');
		column++;
	}
	ft_putchar('\n');
}

void	ft_middle_row(int a, int b, int row, int column)
{
	while (row < b)
	{
		column = 1;
		while (column <= a)
		{
			if (column == 1 || column == a)
				ft_putchar('B');
			else
				ft_putchar(' ');
			column++;
		}
		ft_putchar('\n');
		row++;
	}
	column = 1;
}

void	ft_last_row(int a, int column)
{
	while (column <= a)
	{
		if (column == 1)
			ft_putchar('A');
		else if (column != a)
			ft_putchar('B');
		else
			ft_putchar('C');
		column++;
	}
	ft_putchar('\n');
}

void	rush(int a, int b)
{
	int row;
	int column;

	row = 2;
	column = 1;
	ft_first_row(a, column);
	ft_middle_row(a, b, row, column);
	if (b >= 2)
		ft_last_row(a, column);
}
