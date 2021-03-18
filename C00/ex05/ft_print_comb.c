/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:31:19 by jyoon             #+#    #+#             */
/*   Updated: 2021/03/08 16:57:01 by jyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char comb[3];

	comb[0] = '0';
	while (comb[0] <= '7')
	{
		comb[1] = comb[0] + 1;
		while (comb[1] <= '8')
		{
			comb[2] = comb[1] + 1;
			while (comb[2] <= '9')
			{
				if (comb[0] != comb[1])
				{
					write(1, comb, 3);
					if (comb[0] == '7')
						break ;
					write(1, ", ", 2);
				}
				comb[2]++;
			}
			comb[1]++;
		}
		comb[0]++;
	}
}
