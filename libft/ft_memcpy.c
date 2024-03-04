/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:18:12 by iverniho          #+#    #+#             */
/*   Updated: 2023/12/09 13:47:59 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*tmpd;
	unsigned char	*tmps;
	size_t			i;

	i = 0;
	if (src == NULL && dest == NULL)
		return (dest);
	tmpd = (unsigned char *)dest;
	tmps = (unsigned char *)src;
	while (i < n)
	{
		tmpd[i] = tmps[i];
		i++;
	}
	return (dest);
}
