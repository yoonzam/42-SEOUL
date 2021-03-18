/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woopark <woopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 11:59:42 by woopark           #+#    #+#             */
/*   Updated: 2021/03/06 18:26:39 by woopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "count.h"

int		count_up(int list[])
{
	int	i;
	int	largest;
	int	count;

	count = 1;
	i = 1;
	largest = list[0];
	while (i < N)
	{
		if (list[i] > largest)
		{
			count++;
			largest = list[i];
		}
		i++;
	}
	return (count);
}

int		count_down(int list[])
{
	int	i;
	int	largest;
	int	count;

	count = 1;
	i = N - 2;
	largest = list[N - 1];
	while (i >= 0)
	{
		if (list[i] > largest)
		{
			count++;
			largest = list[i];
		}
		i--;
	}
	return (count);
}

void	up(int list[])
{
	int	i;

	i = N - 1;
	while (i > 0)
	{
		if (list[i] > N)
		{
			list[i - 1]++;
			list[i] = 1;
		}
		i--;
	}
}

int		get_comb(int view, int x)
{
	int	temp[N + 1];
	int	i;
	int	j;

	i = 0;
	while (i < N)
		temp[i++] = 1;
	temp[i] = 0;
	i = 0;
	while (temp[0] != N + 1)
	{
		if (count_up(temp) == view)
		{
			j = 0;
			while (j < N)
			{
				g_comb[x][i][j] = temp[j];
				j++;
			}
			i++;
		}
		temp[N - 1]++;
		up(temp);
	}
	return (i);
}
