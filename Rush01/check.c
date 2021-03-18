/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woopark <woopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:16:55 by woopark           #+#    #+#             */
/*   Updated: 2021/03/06 21:18:23 by woopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "check.h"
#include "print.h"
#include "count.h"

//아래로 봤을때를 체크해주는 함수
void	check_down(void)
{
	//i는 column을, j와 k는 해당 column에서 돌면서 상태를 체크해주는 인덱스
	int	i;
	int	j;
	int	k;

	i = 0;
	//모든 column에 대해서
	while (i < N)
	{
		j = 0;
		while (j < g_comb_len[i])
		{
			//만약 현재 콤비네이션의 밑에서 본 건물의 수가 유저가 준 건물의 수와 같다면
			if (count_down(g_comb[i][j]) == g_view[N + i])
			{
				k = 0;
				//현재 콤비네이션을 g_comb_f에 저장한다
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

//왼쪽에서 봤을때를 체크해주는 함수. 만약 왼쪽에서 본 건물의 갯수가 유저 인풋과 같지 않으면 0을, 같다면 1을 반환
int		check_left(void)
{
	int	i;
	int	j;
	int	largest;
	int	count;

	count = 1;
	i = 0;
	//모든 row에 대해서
	while (i < N)
	{
		//largest를 설정하고, 만약 다음 값이 largest보다 클경우 count를 증가시켜주고 largest를 다음 값으로 변경한다
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
		//만약 유저 인풋과 현재 row에서 보이는 건물의 수가 같지 않다면 0을 반환
		if (count != g_view[2 * N + i++])
			return (0);
		count = 1;
	}
	//같다면 1을 반환
	return (1);
}

//왼쪽에서 봤을때와 기본적으로 알고리즘은 같으나, 배열의 끝에서부터 비교를 한다.
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

//겹치는 숫자가 있는지를 체크해주는 함수
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

//check_dup_row와 기본적으로 같으나 g_board[][]의 인수반 바꾸어주었다 (x와 y 위치만 바꾸어준것
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
