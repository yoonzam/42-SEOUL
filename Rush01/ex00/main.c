/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woopark <woopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:22:48 by woopark           #+#    #+#             */
/*   Updated: 2021/03/07 11:42:44 by woopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "print.h"
#include "count.h"
#include "global.h"
#include "check.h"

int		split(char *str)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			if (str[i] < '1' && str[i] > (N + '0'))
			{
				write(1, "Error\n", 6);
				return (0);
			}
			g_view[k] = str[i] - '0';
			k++;
		}
		i++;
	}
	if (i != (N * 8 - 1))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

int		check_final(void)
{
	if (!check_left())
		return (0);
	if (!check_right())
		return (0);
	if (!check_dup_row())
		return (0);
	if (!check_dup_col())
		return (0);
	return (1);
}

void	check_board(int x, int comb)
{
	int	i;

	i = 0;
	while (i < N)
	{
		g_board[i][x] = g_comb_f[x][comb][i];
		i++;
	}
	if (x < N - 1)
	{
		i = 0;
		while (i < g_comb_len_f[x + 1] && g_result == 0)
			check_board(x + 1, i++);
	}
	else
	{
		if (!check_final())
			return ;
		g_result = 1;
		print_list2(g_board, N);
	}
}

int		main(int argc, char *argv[])
{
	int	i;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!split(argv[1]))
		return (0);
	i = 0;
	while (i < N)
	{
		g_comb_len[i] = get_comb(g_view[i], i);
		i++;
	}
	check_down();
	i = 0;
	while (i < N)
		g_comb_count[i++] = 0;
	i = 0;
	while (i < g_comb_len_f[0])
		check_board(0, i++);
	if (!g_result)
		write(1, "Error\n", 6);
}
