/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 19:47:17 by jyoon             #+#    #+#             */
/*   Updated: 2021/03/13 20:36:13 by jyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_alpnum(char c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (1);
	if ((c >= 'A') && (c <= 'Z'))
		return (1);
	if ((c >= '0') && (c <= '9'))
		return (1);
	return (0);
}

int		is_large(char c)
{
	if ((c >= 'A') && (c <= 'Z'))
		return (1);
	return (0);
}

char	is_small(char c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	while (str[i])
	{
		if ((is_small(str[i])) && (word == 0))
			str[i] = str[i] - 32;
		else if ((is_large(str[i])) && (word == 1))
			str[i] = str[i] + 32;
		if (is_alpnum(str[i]) == 0)
			word = 0;
		else
			word = 1;
		i++;
	}
	return (str);
}
