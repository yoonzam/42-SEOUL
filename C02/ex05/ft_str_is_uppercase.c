/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 14:18:34 by jyoon             #+#    #+#             */
/*   Updated: 2021/03/13 14:18:36 by jyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_uppercase(char *str)
{
	int		i;
	char	a;

	i = 0;
	while (str[i] != '\0')
	{
		a = str[i];
		if (!(a >= 'A' && a <= 'Z'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}