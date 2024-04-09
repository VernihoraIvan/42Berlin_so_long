/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 07:42:32 by iverniho          #+#    #+#             */
/*   Updated: 2023/12/19 13:11:07 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	ft_putpointer(unsigned long long ptr)
// {
// 	uintptr_t	address;
// 	int			i;

// 	i = 0;
// 	address = (char*) ptr;
// 	while (address[i])
// 	{
// 		i++;
// 		write(1, address, sizeof(uintptr_t));
// 	}
// 	return (i);
// }

static int	ft_ptr_len(uintptr_t num)
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

static void	ft_put_ptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else
			ft_putchar(num - 10 + 'a');
	}
}

int	ft_putpointer(unsigned long long ptr)
{
	int	print_length;

	print_length = 0;
	if (ptr != 0)
		print_length = print_length + write(1, "0x", 2);
	if (ptr == 0)
	{
		print_length = print_length + write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		ft_put_ptr(ptr);
		print_length = print_length + ft_ptr_len(ptr);
	}
	return (print_length);
}
