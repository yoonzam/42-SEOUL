/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 13:27:00 by jyoon             #+#    #+#             */
/*   Updated: 2021/03/17 10:52:10 by jyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	len;
	unsigned int	index;

	len = 0;
	index = 0;
	while (dest[len] != '\0')
	{
		len++;
	}
	while (src[index] != '\0' && index < nb)
	{
		dest[index + len] = src[index];
		index++;
	}
	dest[len + index] = '\0';
	return (dest);
}
