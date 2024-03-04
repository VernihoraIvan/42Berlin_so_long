/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:07:43 by iverniho          #+#    #+#             */
/*   Updated: 2023/12/11 17:57:08 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	numlen(int c)
{
	size_t	len;

	len = 0;
	if (c == 0)
		return (1);
	if (c < 0)
		len++;
	while (c != 0)
	{
		c = c / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	size;
	char	*str;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = numlen(n);
	str = (char *)ft_calloc(sizeof(char), (size + 1));
	if (!str)
		return (NULL);
	str[size] = 0;
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		i++;
	}
	while (i < size--)
	{
		str[size] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
