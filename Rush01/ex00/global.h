/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woopark <woopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 11:19:55 by woopark           #+#    #+#             */
/*   Updated: 2021/03/07 11:03:07 by woopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

# define N 4

int g_board[N][N];
int	g_comb[N][256][N];
int	g_comb_f[N][256][N];
int	g_comb_len[N];
int	g_comb_len_f[N];
int	g_comb_count[N];
int g_view[N * 4];
int g_result;

#endif
