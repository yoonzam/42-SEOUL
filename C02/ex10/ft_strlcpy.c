/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 14:19:46 by jyoon             #+#    #+#             */
/*   Updated: 2021/03/13 21:02:52 by jyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	cnt;
	unsigned int	idx;

	cnt = 0;
	idx = 0;
	while (src[cnt] != '\0')
		cnt++;
	if (size != 0)
	{
		while (src[idx] != '\0' && idx < (size - 1))
		{
			dest[idx] = src[idx];
			idx++;
		}
		dest[idx] = '\0';
	}
	return (cnt);
}
