/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junbjang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 18:59:38 by junbjang          #+#    #+#             */
/*   Updated: 2021/02/21 19:08:50 by junbjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_first_row(int a, int column)
{
	while (column <= a)
	{
		if (column == 1)
			ft_putchar('/');
		else if (column != a)
			ft_putchar('*');
		else
			ft_putchar('\\');
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
				ft_putchar('*');
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
			ft_putchar('\\');
		else if (column != a)
			ft_putchar('*');
		else
			ft_putchar('/');
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
