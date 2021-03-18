/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woopark <woopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:22:48 by woopark           #+#    #+#             */
/*   Updated: 2021/03/06 20:47:53 by woopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "print.h"
#include "count.h"
#include "global.h"
#include "check.h"

//유저 인풋을 받아서 전역변수인 g_view에 넣어주는 함수
void	split(char *str)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	//유저 인풋이 끝날때까지
	while (str[i])
	{
		//만약 유저 인풋이 공백이 아니라면
		if (str[i] != ' ')
		{
			//g_view에 유저 인풋값을 넣어준다
			g_view[k] = str[i] - '0';
			k++;
		}
		i++;
	}
}

//마지막에 최종으로 왼쪽, 오른쪽, 가로로 겹치는 숫자, 세로로 겹치는 숫자를 체크해주는 함수. 만약 통과하지 못한다면 0을, 통과한다면 1을 반환한다.
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

//백트레킹으로 계속해서 더 깊은 depth로 들어가는 함수. x는 depth, 즉 몇번째 column인지를 나타내고, comb는 몇번째 조합인지를 나타낸다
void	check_board(int x, int comb)
{
	int	i;

	i = 0;
	//g_board의 x번째 column에 현재 콤비네이션을 대입한다
	while (i < N)
	{
		g_board[i][x] = g_comb_f[x][comb][i];
		i++;
	}
	//만약 현재 depth가 마지막이 아니라면. 즉, 마지막 column에 도달하지 않았다면
	if (x < N - 1)
	{
		i = 0;
		//다음 depth의 모든 경우에 수에 대하여 checkboard를 호출한다
		while (i < g_comb_len_f[x + 1] && g_result == 0)
			check_board(x + 1, i++);
	}
	//만약 현재 depth가 마지막이라면. 즉, 마지막 column이라면
	else
	{
		//checkfinal을 실행하여 왼쪽, 오른쪽, 중복을 체크해준다
		if (!check_final())
			return ;
		//만약 checkfinal을 통과했다면 g_result를 1로 만들어주고 (1일때 찾았다는 뜻, 기본적으로 0으로 설정되어있다) 현재 g_board를 출력해준다.
		g_result = 1;
		print_list2(g_board, N);
	}
}

int		main(int argc, char *argv[])
{
	int	i;

	//만약 유저 인풋이 올바르지 않다면 에러 메세지를 띄우고 종료해라
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	//유저 인풋을 숫자로 바꿔서 g_view라는 배열에 넣어주어라
	split(argv[1]);
	i = 0;
	//get_comb는 모든 조합을 g_comb에 저장하고, 그 조합의 수를 반환한다. 그 조합의 수를 g_comb_len이라는 배열에 넣어주어라
	while (i < N)
	{
		g_comb_len[i] = get_comb(g_view[i], i);
		i++;
	}
	//check_down이라는 함수는 g_comb의 조합들 중 아래서 봤을때 알맞지 않은것들을 필터하여 g_comb_f라는 배열에 넣어준다. 마찬가지로 g_comb_f의 조합의 수는 g_comb_len_f에 저장된다
	check_down();
	i = 0;
	//g_comb_count를 0으로 초기화 시켜준다. 이는 check_board를 호출할때 계속해서 tree를 타고 내려가기 위함이다
	while (i < N)
		g_comb_count[i++] = 0;
	i = 0;
	//0번째 column의 모든 경우의 수에 대해서 check_board를 실행해라
	while (i < g_comb_len_f[0])
		check_board(0, i++);
	//만약 결과를 찾지 못했다면 (g_result가 아직도 0이라면) 에러 메세지를 띄워라
	if (!g_result)
		write(1, "Error\n", 6);
}
