/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:56:53 by iverniho          #+#    #+#             */
/*   Updated: 2023/11/21 10:56:53 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int				i;
	unsigned char	*tmp;

	i = 0;
	tmp = (unsigned char *)s;
	while (n > 0)
	{
		tmp[i] = 0;
		i++;
		n--;
	}
}
