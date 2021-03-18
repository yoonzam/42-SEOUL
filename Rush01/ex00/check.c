/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woopark <woopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:16:55 by woopark           #+#    #+#             */
/*   Updated: 2021/03/06 18:26:28 by woopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "check.h"
#include "print.h"
#include "count.h"

void	check_down(void)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < g_comb_len[i])
		{
			if (count_down(g_comb[i][j]) == g_view[N + i])
			{
				k = 0;
				while (k < N)
				{
					g_comb_f[i][g_comb_len_f[i]][k] = g_comb[i][j][k];
					k++;
				}
				g_comb_len_f[i]++;
			}
			j++;
		}
		i++;
	}
}

int		check_left(void)
{
	int	i;
	int	j;
	int	largest;
	int	count;

	count = 1;
	i = 0;
	while (i < N)
	{
		largest = g_board[i][0];
		j = 1;
		while (j < N)
		{
			if (g_board[i][j] > largest)
			{
				count++;
				largest = g_board[i][j];
			}
			j++;
		}
		if (count != g_view[2 * N + i++])
			return (0);
		count = 1;
	}
	return (1);
}

int		check_right(void)
{
	int	i;
	int	j;
	int	largest;
	int	count;

	count = 1;
	i = 0;
	while (i < N)
	{
		largest = g_board[i][N - 1];
		j = N - 2;
		while (j >= 0)
		{
			if (g_board[i][j] > largest)
			{
				count++;
				largest = g_board[i][j];
			}
			j--;
		}
		if (count != g_view[3 * N + i++])
			return (0);
		count = 1;
	}
	return (1);
}

int		check_dup_row(void)
{
	int	i;
	int j;
	int k;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N - 1)
		{
			k = j + 1;
			while (k < N)
			{
				if (g_board[i][j] == g_board[i][k])
					return (0);
				k++;
			}
			j++;
		}
		i++;
	}
	return (1);
}

int		check_dup_col(void)
{
	int	i;
	int j;
	int k;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N - 1)
		{
			k = j + 1;
			while (k < N)
			{
				if (g_board[j][i] == g_board[k][i])
					return (0);
				k++;
			}
			j++;
		}
		i++;
	}
	return (1);
}
