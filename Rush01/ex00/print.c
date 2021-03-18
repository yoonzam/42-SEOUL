/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woopark <woopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 11:08:10 by woopark           #+#    #+#             */
/*   Updated: 2021/03/07 11:03:58 by woopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include <unistd.h>
#include "global.h"

void	put_char(char c)
{
	write(1, &c, 1);
}

void	print_list(int list[])
{
	int		i;
	char	temp;

	i = 0;
	while (i < N)
	{
		temp = list[i] + '0';
		put_char(temp);
		if (i < N - 1)
			put_char(' ');
		i++;
	}
	put_char('\n');
}

void	print_list2(int list[][N], int len)
{
	int	i;

	i = 0;
	while (i < len)
		print_list(list[i++]);
}
