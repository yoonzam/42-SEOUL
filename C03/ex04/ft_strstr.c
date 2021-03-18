/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 13:27:24 by jyoon             #+#    #+#             */
/*   Updated: 2021/03/16 20:38:39 by jyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	int		find_it;

	if (to_find[0] == '\0')
		return (str);
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		find_it = 1;
		while (str[i + j] != '\0' && to_find[j] != '\0')
		{
			if (str[i + j] != to_find[j])
			{
				find_it = 0;
				break ;
			}
			j++;
		}
		if (find_it == 1 && to_find[j] == '\0')
			return (str + i);
		i++;
	}
	return (0);
}
