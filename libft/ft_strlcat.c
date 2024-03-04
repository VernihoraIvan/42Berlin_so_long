/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:01:45 by iverniho          #+#    #+#             */
/*   Updated: 2023/11/26 13:56:13 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (dst[len] && len < size)
		len ++;
	i = len;
	while (src[len - i] && len + 1 < size)
	{
		dst[len] = src[len - i];
		len ++;
	}
	if (i < size)
		dst[len] = '\0';
	return (i + ft_strlen((char *)src));
}
