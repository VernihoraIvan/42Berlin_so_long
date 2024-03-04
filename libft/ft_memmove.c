/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:40:57 by iverniho          #+#    #+#             */
/*   Updated: 2023/12/09 13:48:10 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmpd;
	unsigned char	*tmps;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	tmpd = (unsigned char *)dst;
	tmps = (unsigned char *)src;
	i = -1;
	if (tmpd > tmps)
	{
		while (len-- > 0)
			tmpd[len] = tmps[len];
	}
	else
	{
		while (++i < len)
			tmpd[i] = tmps[i];
	}
	return (tmpd);
}
