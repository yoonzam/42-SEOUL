/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsikki <minsikki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 11:36:59 by minsikki          #+#    #+#             */
/*   Updated: 2021/03/15 17:43:30 by minsikki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putnbr(char *base, int nbr, int cnt)
{
	long	nb;

	nb = nbr;
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	if (nb >= cnt)
	{
		ft_putnbr(base, nb / cnt, cnt);
		ft_putnbr(base, nb % cnt, cnt);
	}
	else
		write(1, &base[nb], 1);
}

int			check_and_count_base(char *base)
{
	int		idx;
	int		check_idx;
	int		cnt;

	idx = 0;
	cnt = 0;
	while (base[idx])
	{
		if (base[idx] == '+' || base[idx] == '-')
			return (0);
		check_idx = idx + 1;
		while (base[check_idx])
		{
			if (base[idx] == base[check_idx])
				return (0);
			check_idx++;
		}
		idx++;
	}
	while (base[cnt])
		cnt++;
	return (cnt);
}

void		ft_putnbr_base(int nbr, char *base)
{
	if (!base[1] || !base[0])
		return ;
	if (!check_and_count_base(base))
		return ;
	ft_putnbr(base, nbr, check_and_count_base(base));
}
