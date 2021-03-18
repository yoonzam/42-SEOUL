/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woopark <woopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 11:59:42 by woopark           #+#    #+#             */
/*   Updated: 2021/03/06 21:26:37 by woopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "count.h"

//위에서 본 경우의 수를 체크. 경우의 수는 인수로 받은 list에 저장되며 경우의 수가 몇개인지를 반환한다. 기본적인 알고리즘은 check_left와 같다. 참고할것.
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

//아래에서 본 경우의 수를 체크. count_up과 같으나 인덱스가 뒤에서 시작한다는것만 다르다.
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

//올림을 해주는 함수. 만약 n이 3이고 경우의 수가 124가 되었다면 올림을 하여서 131을 만들어줘야 한다. 그때 쓰이는 함수.
void	up(int list[])
{
	int	i;

	i = N - 1;
	while (i > 0)
	{
		//만약 해당 인덱스의 값이 n보다 크다면
		if (list[i] > N)
		{
			//다음 자릿수에 1을 더해주고 현재 인덱스는 1로 초기화한다. 124 -> 131
			list[i - 1]++;
			list[i] = 1;
		}
		i--;
	}
}

//위에서 봤을때 x번째 columm(depth)에 대해서 유저인풋(view)과 같은 모든 콤비네이션을 찾아서 g_comb에 저장하고 몇개의 콤비네이션이 있는지를 반환하는 함수
int		get_comb(int view, int x)
{
	int	temp[N + 1];
	int	i;
	int	j;

	i = 0;
	//배열을 1로 초기화. 만약 n이 3이라면 111부터 333까지의 모든 경우의 수를 체크한다
	while (i < N)
		temp[i++] = 1;
	temp[i] = 0;
	i = 0;
	//temp의 첫번째 수가 n+1이 아닐때까지. 만약 n이 3이라면 111, 112, 113 이렇게 계속 가다가 333, 411에서 멈추게 될 것이다
	while (temp[0] != N + 1)
	{
		//만약 위에서 본 건물의 수가 유저 인풋과 같다면
		if (count_up(temp) == view)
		{
			j = 0;
			//g_comb를 현재 경우의 수로 설정
			while (j < N)
			{
				g_comb[x][i][j] = temp[j];
				j++;
			}
			i++;
		}
		//마지막 자릿수에 1을 더해주고 (예) 111 -> 112
		temp[N - 1]++;
		//올림을 실행해준다
		up(temp);
	}
	return (i);
}
