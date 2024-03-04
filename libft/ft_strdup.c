/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:30:39 by iverniho          #+#    #+#             */
/*   Updated: 2023/11/30 18:18:23 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	int		i;
	int		size;
	char	*res;

	i = 0;
	size = ft_strlen(src);
	res = (char *)malloc((size + 1) * sizeof(char));
	if (!res)
		return (0);
	while (src[i] != '\0')
	{
		res[i] = src[i];
		i++;
	}
	res[i] = 0;
	return (res);
}
