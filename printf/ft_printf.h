/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:01:54 by iverniho          #+#    #+#             */
/*   Updated: 2023/12/22 17:02:51 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
char	*ft_strchr(const char *str, int c);
int		ft_putstr(char *str);
int		ft_putpointer(unsigned long long ptr);
int		ft_putnumber(int num, int base);
int		ft_putunnumber(unsigned int n);
int		ft_putchar(int c);
// int		ft_puthex(int num, const char format);
int		ft_puthex(const char format, unsigned int args);
#endif
