/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:09:56 by jyoon             #+#    #+#             */
/*   Updated: 2021/03/08 16:57:24 by jyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	make_lines(int elem_a, int elem_b)
{
	char lines[5];

	lines[0] = elem_a / 10 + 48;
	lines[1] = elem_a % 10 + 48;
	lines[2] = ' ';
	lines[3] = elem_b / 10 + 48;
	lines[4] = elem_b % 10 + 48;
	write(1, lines, 5);
	if (elem_a != 98 || elem_b != 99)
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int element[2];

	element[0] = 0;
	while (element[0] <= 98)
	{
		element[1] = element[0] + 1;
		while (element[1] <= 99)
		{
			make_lines(element[0], element[1]);
			element[1]++;
		}
		element[0]++;
	}
}
