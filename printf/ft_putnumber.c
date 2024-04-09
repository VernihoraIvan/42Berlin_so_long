/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnumber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 08:37:42 by iverniho          #+#    #+#             */
/*   Updated: 2023/12/22 16:20:57 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnumber(int num, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (num < 0)
	{
		write(1, "-", 1);
		return (ft_putnumber(-num, base) + 1);
	}
	else if (num < base)
	{
		return (ft_putchar(symbols[num]));
	}
	else
	{
		count = ft_putnumber(num / base, base);
		return (count + ft_putnumber(num % base, base));
	}
}

// int	ft_putnumber(int num)
// {
// 	int	i;
// 	// int	temp;

// 	// temp = num;
// 	ft_putnbr(num);
// 	i = 1;
// 	// while (temp != 0)
// 	// {
// 	// 	temp = temp / 10;
// 	// 	i++;
// 	// }
// 	printf("%d", i);
// 	return (i);
// }
