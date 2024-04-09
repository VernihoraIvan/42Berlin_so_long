/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:52:24 by iverniho          #+#    #+#             */
/*   Updated: 2023/12/22 17:11:13 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	ft_puthex(int num, const char format)
// {
// 	int		count;
// 	char	*symbols;

// 	count = 0;
// 	symbols = "0123456789abcdef";
// 	if (num < 0)
// 	{
// 		ft_putchar('-');
// 		num = -num;
// 	}
// 	if (num < 16)
// 	{
// 		if (format == 'X' && (symbols[num] >= 'a' && symbols[num] <= 'z'))
// 			// return (ft_putchar(symbols[num] - 32));
// 			count += ft_putchar(symbols[num] - 32);
// 		else
// 			// return (ft_putchar(symbols[num]));
// 			count += ft_putchar(symbols[num]);
// 	}
// 	else
// 	{
// 		// count = ft_puthex(num / 16, format);
// 		// return (count + ft_puthex(num % 16, format));
// 		count += ft_puthex(num / 16, format);
// 		count += ft_puthex(num % 16, format);
// 	}
// 	return count;
// }

static int	countlen(uintptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static void	puthex(uintptr_t num, const char format)
{
	if (num >= 16)
	{
		puthex(num / 16, format);
		puthex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else if (format == 'x')
			ft_putchar(num - 10 + 'a');
		else if (format == 'X')
			ft_putchar(num - 10 + 'A');
	}
}

int	ft_puthex(const char format, unsigned int args)
{
	int	print_length;

	print_length = 0;
	if (args == 0)
		print_length = print_length + write(1, "0", 1);
	else
	{
		puthex(args, format);
		print_length = print_length + countlen(args);
	}
	return (print_length);
}
