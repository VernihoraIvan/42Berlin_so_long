/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:20:18 by iverniho          #+#    #+#             */
/*   Updated: 2023/12/09 13:58:18 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cs;
	unsigned char	cc;
	size_t			i;

	cs = (unsigned char *) s;
	cc = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (cs[i] == cc)
			return ((void *) &cs[i]);
		i++;
	}
	return (NULL);
}
