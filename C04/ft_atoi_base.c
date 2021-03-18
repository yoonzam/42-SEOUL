/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsikki <minsikki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:44:45 by minsikki          #+#    #+#             */
/*   Updated: 2021/03/17 15:19:30 by minsikki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		valid_base(char *base)
{
	int	idx;
	int	sec_idx;

	idx = 0;
	if (!base[0] || !base[1])
		return (0);
	while (base[idx])
	{
		if (base[idx] == '-' || base[idx] == '+' ||
				base[idx] == ' ' || (base[idx] > 8 && base[idx] < 14))
			return (0);
		sec_idx = idx + 1;
		while (base[sec_idx])
		{
			if (base[idx] == base[sec_idx])
				return (0);
			sec_idx++;
		}
		idx++;
	}
	return (1);
}

int		check_str(char *str, char *base, int i)
{
	int	idx_b;

	idx_b = 0;
	while (base[idx_b])
	{
		if (base[idx_b] == str[i])
			return (idx_b);
		idx_b++;
	}
	return (-1);
}

int		ft_atoi(char *str, char *base, int size)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		if (check_str(str, base, i) == -1)
			break ;
		else
			result = result * size + check_str(str, base, i);
		i++;
	}
	return (sign * result);
}

int		ft_atoi_base(char *str, char *base)
{
	int	size;

	size = 0;
	while (base[size])
		size++;
	if (!valid_base(base))
		return (0);
	if (!str[0])
		return (0);
	return (ft_atoi(str, base, size));
}
